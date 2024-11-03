/**
* @file PrimitiveRenderSystem.cpp
* @author Hudson Schumaker
* @brief Implements the PrimitiveRenderSystem class.
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
#include "PrimitiveRenderSystem.h"
#include "../../gfx/Box.h"
#include "../../gfx/Gfx.h"
#include "../../gfx/Line.h"
#include "../../gfx/Circle.h"

PrimitiveRenderSystem::PrimitiveRenderSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void PrimitiveRenderSystem::update(const Camera* camera) {
	primitives_t primitives;
	primitives_t background;
	primitives_t middleground;
	primitives_t foreground;

	getPrimitives(&primitives);

	// Filter primitives by Layer
	for (auto& primitive : primitives) {
		auto entity = std::get<0>(primitive);
		if (entity->layer == Layer::BACKGROUND) {
			background.push_back(primitive);
			continue;
		}
		
		if (entity->layer == Layer::MIDDLEGROUND) {
			middleground.push_back(primitive);
			continue;
		}
		
		if (entity->layer == Layer::FOREGROUND) {
			foreground.push_back(primitive);
		}
	}	

	// Sort primitives
	sortPrimitives(&background, &middleground, &foreground);

	for (auto& primitive : background) {
		renderCaller(primitive, camera);
	}	

	for (auto& primitive : middleground) {
		renderCaller(primitive, camera);
	}

	for (auto& primitive : foreground) {
		renderCaller(primitive, camera);
	}
}

void PrimitiveRenderSystem::getPrimitives(primitives_t* primitives) {
	auto primitivesEntities = EntityManager::getInstance()->getEntitiesWithGroup(Group::PRIMITIVES);

	for (auto& pair : primitivesEntities) {
		Entity* entity = pair.first;
		PrimitiveType type = std::get<PrimitiveType>(pair.second);
		primitives->push_back(
			std::make_tuple(	
				entity,
				entity->getComponent<Transform>(),
				type
			)
		);
	}
}

void PrimitiveRenderSystem::sortPrimitives(primitives_t* background, primitives_t* middleground, primitives_t* foreground) {
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

void PrimitiveRenderSystem::renderLine(primitive_t& primitive, const Camera* camera) {
	auto entity = std::get<0>(primitive);
	Transform* transform = std::get<1>(primitive);
	Line* line = entity->getComponent<Line>();

	auto dimension = line->getSize();
	auto lW = dimension.w;
	auto lH = dimension.h;

	bool isOutsideCameraView = (
		transform->position.x + (transform->scale.x * lW) < camera->x ||
		transform->position.x > camera->x + camera->w ||
		transform->position.y + (transform->scale.y * lH) < camera->y ||
		transform->position.y > camera->y + camera->h
	);

	if (isOutsideCameraView && !line->isFixed) {
		return;
	}

	auto x0 = static_cast<int>(transform->position.x - (line->isFixed ? 0 : camera->x));
	auto y0 = static_cast<int>(transform->position.y - (line->isFixed ? 0 : camera->y));
	auto x1 = static_cast<int>(line->b.x * transform->scale.x);
	auto y1 = static_cast<int>(line->b.y * transform->scale.y);

	Gfx::getInstance()->drawLine(x0, y0, x1, y1, line->color);
}

void PrimitiveRenderSystem::renderBox(primitive_t& primitive, const Camera* camera) {
	auto entity = std::get<0>(primitive);
	Transform* transform = std::get<1>(primitive);
	Box* box = entity->getComponent<Box>();
	
	bool isOutsideCameraView = (
		transform->position.x + (transform->scale.x * box->w) < camera->x ||
		transform->position.x > camera->x + camera->w ||
		transform->position.y + (transform->scale.y * box->h) < camera->y ||
		transform->position.y > camera->y + camera->h
	);
	
	if (isOutsideCameraView && !box->isFixed) {
		return;
	}

	SDL_FRect dstRect = {
		transform->position.x - (box->isFixed ? 0.0f : camera->x),
		transform->position.y - (box->isFixed ? 0.0f : camera->y),
		box->w * transform->scale.x,
		box->h * transform->scale.y
	};

	if (!box->isFilled) {
		Gfx::getInstance()->drawBox(dstRect, box->color);
	} else {
		Gfx::getInstance()->drawFillBox(dstRect, box->color);
	}
}

void PrimitiveRenderSystem::renderCircle(primitive_t& primitive, const Camera* camera) {
	auto entity = std::get<0>(primitive);
	Transform* transform = std::get<1>(primitive);
	Circle* circle = entity->getComponent<Circle>();

	auto wh = circle->getSize().w;
	bool isOutsideCameraView = (
		transform->position.x + (transform->scale.x * wh) < camera->x ||
		transform->position.x > camera->x + camera->w ||
		transform->position.y + (transform->scale.y * wh) < camera->y ||
		transform->position.y > camera->y + camera->h
	);

	if (isOutsideCameraView && !circle->isFixed) {
		return;
	}

	auto x = static_cast<int>(transform->position.x - (circle->isFixed ? 0 : camera->x));
	auto y = static_cast<int>(transform->position.y - (circle->isFixed ? 0 : camera->y));
	auto r = static_cast<int>(circle->getRadius() * transform->scale.x);

	if (!circle->isDashed) {
		if (!circle->isFilled) {
			Gfx::getInstance()->drawCircle(x, y, r, circle->color);
		} else {
			Gfx::getInstance()->drawFillCircle(x, y, r, circle->color);
		}
	} else {
		Gfx::getInstance()->drawDashedCircle(x, y, r, circle->dashLength, circle->color);
	}
}

void PrimitiveRenderSystem::renderCaller(primitive_t& primitive, const Camera* camera) {
	auto type = std::get<2>(primitive);
	if (type == PrimitiveType::BOX) {
		renderBox(primitive, camera);
		return;
	}

	if (type == PrimitiveType::CIRCLE) {
		renderCircle(primitive, camera);
		return;
	}

	if (type == PrimitiveType::LINE) {
		renderLine(primitive, camera);
	}
}
