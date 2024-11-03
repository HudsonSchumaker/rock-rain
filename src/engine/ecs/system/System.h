/**
* @file System.h
* @author Hudson Schumaker
* @brief Defines the System class.
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
#pragma once
#include "../../../Pch.h"
#include "../EntityManager.h"
#include "../../core/Hardware.h"
#include "../component/Component.h"

/**
* @class System
* @brief The base class for all systems.
*/
class System {
public:
    template <typename Component>
    static std::vector<std::vector<Entity*>> calculateChunksAndThreads() {
        // Get all entities with the specified component
        auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Component>();

        // Get the number of these entities
        int entitiesSize = static_cast<int>(entities.size());

        // Get the number of threads based on the number of entities
        int numThreads = Hardware::getThreadNumber(entitiesSize);

        // Calculate the size of each chunk for parallel processing
        int chunkSize = (entitiesSize + numThreads - 1) / numThreads; // Round up division

        // Vector to hold the chunks of entities
        std::vector<std::vector<Entity*>> chunks;
        chunks.reserve(numThreads); // Reserve space for the chunks

        // Divide the entities into chunks
        for (int i = 0; i < entities.size(); i += chunkSize) {
            chunks.emplace_back(entities.begin() + i, entities.begin() +
                std::min(i + chunkSize, entitiesSize));
        }

        return chunks;
    }
};
