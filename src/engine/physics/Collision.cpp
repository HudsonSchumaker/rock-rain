/**
* @file Collision.cpp
* @author Hudson Schumaker
* @brief Implements the Collision class.
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
#include "Collision.h"

void Collision::resolveCollision() {
	// Apply positional correction using the projection method
	resolvePenetration();
	// TODO: calculate the collision impulse
}

void Collision::resolvePenetration() {
	float dA = depth / (rA->invMass + rB->invMass) * rA->invMass;
	float dB = depth / (rA->invMass + rB->invMass) * rB->invMass;

	tA->position -= normal * dA;
	tB->position += normal * dB;
}
