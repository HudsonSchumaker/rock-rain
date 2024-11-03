/**
* @file WaypointNavigationSystem.h
* @author Hudson Schumaker
* @brief Defines the WaypointNavigationSystem class.
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
#include "System.h"

/**
* @class WaypointNavigationSystem
* @brief Responsible for updating the navigation of entities with waypoints.
*
* The WaypointNavigationSystem class is part of the game's navigation system. It updates the navigation of entities that have waypoints, moving them towards their next waypoint based on the time elapsed since the last frame.
*/
class WaypointNavigationSystem final : public System {
public:

    /**
    * @brief Updates the navigation of entities with waypoints.
    * @param dt The time elapsed since the last frame, used to calculate the movement distance.
    */
    void update(float dt);
};
