/**
* @file CameraMovementSystem.cpp
* @author Hudson Schumaker
* @brief Implements the CameraMovementSystem class.
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
#include "CameraMovementSystem.h"
#include "../component/Transform.h"
#include "../component/CameraFollow.h"

void CameraMovementSystem::update(Map* map, Camera* camera) {
    // Get all entities with CameraFollow components
	auto entities = EntityManager::getInstance()->getEntitiesWithComponent<CameraFollow>();

    // For each entity with CameraFollow component
	for (auto& entity : entities) {
        Transform* transform = entity->getComponent<Transform>(); // Get the Transform component 

        // calculate
		if (transform->position.x + (camera->w / 2) < map->mapWidth) {
			camera->x = int(transform->position.x - Defs::SCREEN_H_WIDTH);
		}

		if (transform->position.y + (camera->h / 2) < map->mapHeight) {
			camera->y = int(transform->position.y - Defs::SCREEN_H_HEIGHT);
		}

		// Keep camera rectangle view inside the screen limits
		camera->x = camera->x < 0 ? 0 : camera->x;
		camera->y = camera->y < 0 ? 0 : camera->y;
			
		camera->x = (camera->x + camera->w > map->mapWidth) ?
			map->mapWidth - camera->w : camera->x;
			
		camera->y = (camera->y + camera->h > map->mapHeight) ?
			map->mapHeight - camera->h : camera->y;
	}
}
