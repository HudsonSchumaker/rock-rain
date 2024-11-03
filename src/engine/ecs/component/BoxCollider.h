/**
* @file BoxCollider.h
* @author Hudson Schumaker
* @brief Defines the BoxCollider class.
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
#include "../../math/Dimension.h"

/**
 * @class BoxCollider
 * @brief A box collider component.
 */
class BoxCollider final : public Component {
public:
	Vec2 offset;
	Dimension<short> bounds;

	BoxCollider() = default;
	BoxCollider(short v) {
		this->bounds.w = v;
		this->bounds.h = v;
	}
	
	BoxCollider(short w, short h) {
		this->bounds.w = w;
		this->bounds.h = h;
	}

	BoxCollider(float x, float y, short w, short h) {
		this->offset.x = x;
		this->offset.y = y;
		this->bounds.w = w;
		this->bounds.h = h;
	}

	BoxCollider(Dimension<short> bounds) {
		this->bounds = bounds;
	}

	BoxCollider(Dimension<short> bounds, Vec2 offset) {
		this->bounds = bounds;
		this->offset = offset;
	}

	~BoxCollider() = default;

	BoxCollider clone() {
		return BoxCollider(bounds, offset);
	}
};
