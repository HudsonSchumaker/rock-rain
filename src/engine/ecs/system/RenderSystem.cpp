/**
* @file RenderSystem.cpp
* @author Hudson Schumaker
* @brief Implements the RenderSystem class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "RenderSystem.h"
#include "../../gfx/Gfx.h"
#include "../../gfx/Sprite.h"
#include "../../gfx/Animation.h"
#include "../../gfx/AnimationController.h"

RenderSystem::RenderSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void RenderSystem::update(const Camera* camera) {
	renderables_t renderables;
	renderables_t background;
	renderables_t middleground;
	renderables_t foreground;

	getRenderables(&renderables);

	// Filter renderables by Layer
	for (auto& renderable : renderables) {
		auto entity = std::get<0>(renderable);
		if (entity->layer == Layer::BACKGROUND) {
			background.push_back(renderable);
			continue;
		}

		if (entity->layer == Layer::MIDDLEGROUND) {
			middleground.push_back(renderable);
			continue;
		}

		if (entity->layer == Layer::FOREGROUND) {
			foreground.push_back(renderable);
		}
	}

	// Sort renderables by z-index
	sortRenderables(&background, &middleground, &foreground);

	for (auto& renderable : background) {
		renderCaller(renderable, camera);
	}

	for (auto& renderable : middleground) {
		renderCaller(renderable, camera);
	}

	for (auto& renderable : foreground) {
		renderCaller(renderable, camera);
	}
}

void RenderSystem::getRenderables(renderables_t* renderables) {
	auto renderableEntities = EntityManager::getInstance()->getEntitiesWithGroup(Group::RENDERABLE);

	for (auto& pair : renderableEntities) {
		Entity* entity = pair.first;
		RenderType type = std::get<RenderType>(pair.second);
		renderables->push_back(
			std::make_tuple(
				entity,
				entity->getComponent<Transform>(),
				type
			)
		);
	}
}

void RenderSystem::sortRenderables(renderables_t* background, renderables_t* middleground, renderables_t* foreground) {
	auto bgFuture = std::async(std::launch::async, [&]() {
		std::sort(background->begin(), background->end(), [](const auto& a, const auto& b) {
			return std::get<0>(a)->zIndex < std::get<0>(b)->zIndex;
		});
	});

	auto mdFuture = std::async(std::launch::async, [&]() {
		std::sort(middleground->begin(), middleground->end(), [](const auto& a, const auto& b) {
			Transform* transformA = std::get<1>(a);
			Transform* transformB = std::get<1>(b);
			return transformA->position.y < transformB->position.y;
		});
	});

	auto fgFuture = std::async(std::launch::async, [&]() {
		std::sort(foreground->begin(), foreground->end(), [](const auto& a, const auto& b) {
			return std::get<0>(a)->zIndex < std::get<0>(b)->zIndex;
		});
	});

	// Wait for all futures to complete
	bgFuture.get();
	mdFuture.get();
	fgFuture.get();
}

void RenderSystem::renderSprite(renderable_t& renderable, const Camera* camera) {
	auto entity = std::get<0>(renderable);
	Transform* transform = std::get<1>(renderable);
	Sprite* sprite = entity->getComponent<Sprite>();

	bool isOutsideCameraView = (
		transform->position.x + (transform->scale.x * sprite->w) < camera->x ||
		transform->position.x > camera->x + camera->w ||
		transform->position.y + (transform->scale.y * sprite->h) < camera->y ||
		transform->position.y > camera->y + camera->h
	);

	if (isOutsideCameraView && !sprite->isFixed) {
		return;
	}

	SDL_Rect srcRect = sprite->srcRect;
	SDL_FRect dstRect = {
		transform->position.x - (sprite->isFixed ? 0 : camera->x),
		transform->position.y - (sprite->isFixed ? 0 : camera->y),
		sprite->w * transform->scale.x,
		sprite->h * transform->scale.y
	};

	if (sprite->flipX) {
		SDL_RenderCopyExF(
			renderer,
			sprite->texture,
			&srcRect,
			&dstRect,
			transform->rotation,
			NULL,
			SDL_FLIP_HORIZONTAL
		);
	} else {
		SDL_RenderCopyExF(
			renderer,
			sprite->texture,
			&srcRect,
			&dstRect,
			transform->rotation,
			NULL,
			SDL_FLIP_NONE
		);
	}
}

void RenderSystem::renderAnimation(renderable_t& renderable, const Camera* camera) {
	auto entity = std::get<0>(renderable);
	Transform* transform = std::get<1>(renderable);
	Animation* animation = entity->getComponent<Animation>();

	bool isOutsideCameraView = (
		transform->position.x + (transform->scale.x * animation->bounds.w) < camera->x ||
		transform->position.x > camera->x + camera->w ||
		transform->position.y + (transform->scale.y * animation->bounds.h) < camera->y ||
		transform->position.y > camera->y + camera->h
	);

	if (isOutsideCameraView && !animation->isFixed) {
		return;
	}

	if (animation->isPlaying) {
		animation->currentFrame = ((SDL_GetTicks() - animation->startTime)
			* animation->frameSpeedRate / 1000) % animation->numFrames;

		if (animation->currentFrame == animation->skipFrameIndex) {
			if (animation->skipFrameIndex == 0) {
				animation->currentFrame = 1;
			}
			else { animation->currentFrame = 0; }
		}

		SDL_Rect origin = { animation->currentFrame * animation->getSize().w, 0, animation->getSize().h, animation->getSize().h };

		SDL_FRect dest = { 0.0f, 0.0f, 0.0f, 0.0f };
		dest.x = transform->position.x - (animation->isFixed ? 0 : camera->x);
		dest.y = transform->position.y - (animation->isFixed ? 0 : camera->y);
		dest.w = animation->getSize().w * transform->scale.x;
		dest.h = animation->getSize().h * transform->scale.y;

		if (animation->flip) {
			SDL_RenderCopyExF(renderer, animation->texture, &origin, &dest, transform->rotation, NULL, SDL_FLIP_HORIZONTAL);
		} else {
			SDL_RenderCopyExF(
				renderer,
				animation->texture,
				&origin,
				&dest,
				transform->rotation,
				NULL,
				SDL_FLIP_NONE
			);
		}

		if (!animation->isLoop) {
			// Check if the current frame is equal to the number of frames
			if (animation->currentFrame == animation->numFrames - 1) {
				animation->stop();
			}
		}
	}
}

void RenderSystem::renderAnimationController(renderable_t& renderable, const Camera* camera) {
	auto entity = std::get<0>(renderable);
	Transform* transform = std::get<1>(renderable);
	AnimationController* animationController = entity->getComponent<AnimationController>();
	Animation* animation = animationController->getActive();

	bool isOutsideCameraView = (
		transform->position.x + (transform->scale.x * animation->bounds.w) < camera->x ||
		transform->position.x > camera->x + camera->w ||
		transform->position.y + (transform->scale.y * animation->bounds.h) < camera->y ||
		transform->position.y > camera->y + camera->h
	);

	if (isOutsideCameraView && !animation->isFixed) {
		return;
	}

	if (animation->isPlaying) {
		animation->currentFrame = ((SDL_GetTicks() - animation->startTime)
			* animation->frameSpeedRate / 1000) % animation->numFrames;

		if (animation->currentFrame == animation->skipFrameIndex) {
			animation->currentFrame = 0;
		}

		SDL_Rect origin = { animation->currentFrame * animation->getSize().w, 0, animation->getSize().h, animation->getSize().h };

		SDL_FRect dest = { 0.0f, 0.0f, 0.0f, 0.0f };
		dest.x = transform->position.x - (animation->isFixed ? 0 : camera->x);
		dest.y = transform->position.y - (animation->isFixed ? 0 : camera->y);
		dest.w = animation->getSize().w * transform->scale.x;
		dest.h = animation->getSize().h * transform->scale.y;

		if (animation->flip) {
			SDL_RenderCopyExF(
				renderer,
				animation->texture,
				&origin,
				&dest,
				transform->rotation,
				NULL,
				SDL_FLIP_HORIZONTAL
			);
		} else {
			SDL_RenderCopyExF(
				renderer,
				animation->texture,
				&origin,
				&dest,
				transform->rotation,
				NULL,
				SDL_FLIP_NONE
			);
		}

		if (!animation->isLoop) {
			// Check if the current frame is equal to the number of frames
			if (animation->currentFrame == animation->numFrames - 1) {
				animation->stop();
			}
		}
	}
}

void RenderSystem::renderCaller(renderable_t& renderable, const Camera* camera) {
	auto type = std::get<2>(renderable);

	if (type == RenderType::SPRITE) {
		renderSprite(renderable, camera);
		return;
	}

	if (type == RenderType::ANIMATION) {
		renderAnimation(renderable, camera);
		return;
	}

	if (type == RenderType::ANIMATION_CONTROLLER) {
		renderAnimationController(renderable, camera);
	}
}
