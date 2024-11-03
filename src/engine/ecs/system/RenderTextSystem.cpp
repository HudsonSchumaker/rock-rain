/**
* @file RenderTextSystem.cpp
* @author Hudson Schumaker
* @brief Implements the RenderTextSystem class.
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
#include "RenderTextSystem.h"
#include "../EntityManager.h"
#include "../../gfx/Gfx.h"
#include "../../gfx/SpriteText.h"
#include "../component/TextLabel.h"
#include "../component/Transform.h"

RenderTextSystem::RenderTextSystem() {
	this->renderer = Gfx::getInstance()->getRenderer();
}

void RenderTextSystem::update(Camera* camera) {
	renderTextLabel(camera);
	renderSpriteText(camera);
}

void RenderTextSystem::renderTextLabel(Camera* camera) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<TextLabel>();

	for (auto& entity : entities) {
		TextLabel* textLabel = entity->getComponent<TextLabel>();
		
		// render
		SDL_Rect dstRect = {
			static_cast<int>(textLabel->position.x - (textLabel->isFixed ? 0 : camera->x)),
			static_cast<int>(textLabel->position.y - (textLabel->isFixed ? 0 : camera->y)),
			textLabel->w,
			textLabel->h
		};
			
		SDL_RenderCopy(renderer, textLabel->label, NULL, &dstRect);
	}
}

void RenderTextSystem::renderSpriteText(Camera* camera) {
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<SpriteText>();

	for (auto& entity : entities) {
		Transform* transform = entity->getComponent<Transform>();
		SpriteText* spriteText = entity->getComponent<SpriteText>();

		// render
		float newX = transform->position.x + spriteText->offSet.x;
		float newY = transform->position.y + spriteText->offSet.y; 

		spriteText->position.x = newX;
		spriteText->position.y = newY;

		SDL_Rect dstRect = {
			static_cast<int>(spriteText->position.x - (spriteText->isFixed ? 0 : camera->x)),
			static_cast<int>(spriteText->position.y - (spriteText->isFixed ? 0 : camera->y)),
			spriteText->w,
			spriteText->h
		};
			
		SDL_RenderCopy(renderer, spriteText->label, NULL, &dstRect);
	}
}
