/**
* @file Box.cpp
* @author Hudson Schumaker
* @brief Implements the Box class.
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
#include "Box.h"
#include "../ecs/EntityManager.h"
#include "../ecs/component/Transform.h"

Box::Box() : w(2), h(2) {}
Box::Box(int w, int h) : w(w), h(h) {}
Box::Box(int w, int h, bool isFixed) : w(w), h(h), isFixed(isFixed) {}
Box::Box(int w, int h, bool isFixed, SDL_Color color) : w(w), h(h), isFixed(isFixed), color(color) {}
Box::Box(int w, int h, bool isFixed, bool isFilled, SDL_Color color) : w(w), h(h), isFixed(isFixed), isFilled(isFilled), color(color) {}

void Box::setOnCenter() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		transform->position.x = float(Defs::SCREEN_H_WIDTH - (w / 2));
		transform->position.y = float(Defs::SCREEN_H_HEIGHT - (h / 2));
	}
}

Dimension<int> Box::getSize() const {
	return Dimension(w, h);
}
