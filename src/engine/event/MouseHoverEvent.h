/**
* @file MouseHoverEvent.h
* @author Hudson Schumaker
* @brief Defines the MouseHoverEvent class.
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
#include "Event.h"
#include "../ecs/Entity.h"

/**
 * @class MouseHoverEvent
 * @brief Event for mouse hover.
 */
class MouseHoverEvent final : public Event {
public:
    Entity* b;
    bool isInside;

    MouseHoverEvent(Entity* b, bool isInside) : b(b), isInside(isInside) {}
    ~MouseHoverEvent() = default;
};
