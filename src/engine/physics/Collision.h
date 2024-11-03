/**
* @file Collision.h
* @author Hudson Schumaker
* @brief Defines the Collision class.
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
#include "../ecs/component/Transform.h"
#include "../ecs/component/RigidBody.h"
#include "../ecs/component/CircleCollider.h"

struct Collision {
	Transform* tA = nullptr;
	Transform* tB = nullptr;

	RigidBody* rA = nullptr;
	RigidBody* rB = nullptr;
	
	CircleCollider* cA = nullptr;
	CircleCollider* cB = nullptr;

	Vec2 start, end, normal;
	float depth = 0.0f;

	Collision() = default;
	~Collision() = default;

	void resolveCollision();
	void resolvePenetration();
};
