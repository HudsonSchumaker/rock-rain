/**
* @file Line.cpp
* @author Hudson Schumaker
* @brief Implements the Line class.
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
#include "Line.h"
#include "../math/DeMath.h"
#include "../ecs/EntityManager.h"
#include "../ecs/component/Transform.h"

Line::Line(Vec2 b) : b(b) {}
Line::Line(float x, float y) : b(x, y) {}
Line::Line(Vec2 b, bool isFixed) : b(b), isFixed(isFixed) {}
Line::Line(Vec2 b, bool isFixed, SDL_Color color) : b(b), isFixed(isFixed), color(color) {}

Dimension<float> Line::getSize() const {
    auto parent = EntityManager::getInstance()->getEntity(parentId);
    auto transform = parent->getComponent<Transform>();
    if (transform) {
        Vec2 a = transform->position;
        return Dimension<float>(b.distance(a), 1.0f);
    }
    return Dimension<float>(0.0f, 0.0f);
}
