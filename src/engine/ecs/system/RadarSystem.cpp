




#include "RadarSystem.h"
#include "../EntityManager.h"
#include "../component/Radar.h"
#include "../component/Callback.h"
#include "../component/Transform.h"

void RadarSystem::update() {
    // Get all entities with RigidBody components
    auto chunks = calculateChunksAndThreads<Radar>();

    // Vector to hold the threads
    std::vector<std::thread> threads;

    // For each chunk of entities, create a thread
    for (const auto& chunk : chunks) {
        threads.emplace_back([chunk] {
            // For each entity in the chunk
            for (auto& entity : chunk) {
                auto components = entity->getComponents<Radar, Transform>();
                Radar* radar = std::get<0>(components);         // Get the Radar component
                Transform* transform = std::get<1>(components); // Get the Transform component    

                // calculate
                float radarX = transform->position.x + radar->offset.x;
                float radarY = transform->position.y + radar->offset.y;
                float radarRadius = radar->r;

                auto enemies = EntityManager::getInstance()->getEntitiesWithTag(radar->tag);
                for (auto& enemy : enemies) {
                    if (enemy->tags.first == radar->tag) {
                        Transform* enemyTransform = enemy->getComponent<Transform>();

                        // Calculate the distance between the radar and the other entity
                        float dx = (enemyTransform->position.x + 24) - radarX;
                        float dy = (enemyTransform->position.y + 24) - radarY;
                        float distance = std::sqrtf(dx * dx + dy * dy);

                        // Check if the other entity is within the radar area
                        if (distance <= radarRadius) {
                            radar->onDetect(entity->id, enemy->id);
                            break;
                        }
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
