/**
* @file WaypointNavigationSystem.cpp
* @author Hudson Schumaker
* @brief Implements the WaypointNavigationSystem class
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
#include "WaypointNavigationSystem.h"
#include "../component/Waypoint.h"
#include "../component/Transform.h"
#include "../component/RigidBody.h"

void WaypointNavigationSystem::update(float dt) {
    // Get all entities with Waypoint component
    auto chunks = calculateChunksAndThreads<Waypoint>();

    // Vector to hold the threads
    std::vector<std::thread> threads;

    // For each chunk of entities, create a thread
    for (const auto& chunk : chunks) {
        threads.emplace_back([chunk, dt] {
            // For each entity in the chunk
            for (auto& entity : chunk) {

                auto components = entity->getComponents<Waypoint, RigidBody, Transform>();
                Waypoint* points = std::get<0>(components);     // Get the Waypoint component
                RigidBody* rigidBody = std::get<1>(components); // Get the RigidBody component
                Transform* transform = std::get<2>(components); // Get the Transform component

                // If the entity has a RigidBody and Waypoints
                if (rigidBody && !points->waypoints.empty()) {
                    // Get the current waypoint
                    auto currentWaypoint = points->waypoints.front();

                    // Calculate the direction vector only if necessary
                    if (points->direction.x == 0 && points->direction.y == 0) {
                        float pointX = static_cast<float>(currentWaypoint.first);
                        float pointY = static_cast<float>(currentWaypoint.second);

                        float dx = pointX - transform->position.x;
                        float dy = pointY - transform->position.y;
                        float distance = std::sqrtf(dx * dx + dy * dy);
                        
                        // Normalize the direction vector
                        points->direction.x = dx / distance;
                        points->direction.y = dy / distance;
                    }

                    // Define an epsilon value for proximity check
                    const float epsilon = 0.2f;

                    // Check if the Entity has reached the Waypoint
                    float dx = currentWaypoint.first - transform->position.x;
                    float dy = currentWaypoint.second - transform->position.y;
                    float distance = std::sqrtf(dx * dx + dy * dy);
                    if (distance <= epsilon) {
                        // Remove the current Waypoint from the list
                        points->waypoints.erase(points->waypoints.begin());
                        // Reset the direction to force recalculation
                        points->direction.x = 0;
                        points->direction.y = 0;
                    } else {
                        // Calculate the movement distances based on the speeds and delta time
                        float movementDistanceX = rigidBody->velocity.x * dt;
                        float movementDistanceY = rigidBody->velocity.y * dt;

                        // Move the entity towards the waypoint
                        transform->position.x += movementDistanceX * points->direction.x;
                        transform->position.y += movementDistanceY * points->direction.y;
                    }
                }
            }
        });
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }
}
