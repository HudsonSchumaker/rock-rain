/**
* @file Map.h
* @author Hudson Schumaker
* @brief Defines the Map class.
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
#include "../../Pch.h"

/**
* @class Map
* @brief The Map class.
*/
class Map final {
public:
	std::string assetId;
	std::string mapId;
	short tileSize = 0;
	short scale = 1;
	short mapNumCols = 0;
	short mapNumRows = 0;
	int mapWidth = 0;
	int mapHeight = 0;

	Map() = default;

	/**
     * @brief Construct a new Map object
     * 
     * @param name The asset ID of the map.
     * @param mapId The unique ID of the map.
     * @param tileSize The size of the tile.
     * @param scale The scale of the map.
     * @param mapNumCols The number of columns in the map.
     * @param mapNumRows The number of rows in the map.
     */ 
	Map(const std::string& name, std::string mapId, short tileSize, short scale, short mapNumCols, short mapNumRows) {
		this->assetId = name;
		this->mapId = std::move(mapId);
		this->tileSize = tileSize;
		this->scale = scale;
		this->mapNumCols = mapNumCols;
		this->mapNumRows = mapNumRows;

		// update map dimension
		this->mapWidth = mapNumCols * tileSize * scale;
		this->mapHeight = mapNumRows * tileSize * scale;
	}

	~Map() = default;
};
