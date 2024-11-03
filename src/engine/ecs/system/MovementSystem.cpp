/**
* @file MovementSystem.cpp
* @author Hudson Schumaker
* @brief Implements the MovementSystem class
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
#include "MovementSystem.h"
#include "../component/Waypoint.h"
#include "../component/Transform.h"
#include "../component/RigidBody.h"

void MovementSystem::update(float dt) {
    // Get all entities with RigidBody components
    auto chunks = calculateChunksAndThreads<RigidBody>();

    // Vector to hold the threads
    std::vector<std::thread> threads;

    // For each chunk of entities, create a thread
    for (const auto& chunk : chunks) {
        threads.emplace_back([chunk, dt] {
            // For each entity in the chunk
            for (auto& entity : chunk) {
                // Do nothing if the entity have a Waypoint component
                if (entity->getComponent<Waypoint>()) {
					continue;
				}

                auto components = entity->getComponents<RigidBody, Transform>();
                RigidBody* rigidBody = std::get<0>(components); // Get the RigidBody component
                Transform* transform = std::get<1>(components); // Get the Transform component

                // If the entity is not moving ignore it
                if (!rigidBody->isMoving) { continue; }

                // Update the position based on the velocity
                transform->position.x += rigidBody->velocity.x * dt;
				transform->position.y += rigidBody->velocity.y * dt;
            }
        });
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }
}
