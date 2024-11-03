/**
* @file Waypoint.h
* @author Hudson Schumaker
* @brief Defines the Waypoint class.
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
#include "Component.h"
#include "../../math/Vec2.h"

/**
* @class Waypoint
* @brief A class that represents a waypoint in a game.
*/
class Waypoint final : public Component {
public:
	Vec2 direction;

	/**
	* @property waypoints A vector of tuples. Each tuple represents a waypoint and contains:
	* - A pair of shorts representing the point (x, y)
	*/
	std::vector<std::pair<short, short>> waypoints;

	Waypoint(std::pair<short, short> point) {
		this->waypoints.push_back(point);
	}

	/**
	* add a Point that takes a pair of shorts representing a point (x, y).
	* @param point A pair of shorts representing the point
	*/
	void addPoint(std::pair<short, short> point) {
		waypoints.push_back(point);
	}
	
	~Waypoint() {
		this->waypoints.clear();
	}
};
