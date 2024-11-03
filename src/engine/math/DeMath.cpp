/**
* @file DeMath.cpp
* @author Hudson Schumaker
* @brief Implements the DeMath class.
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
#include "DeMath.h"

float DeMath::distanceBetweenPoints(const float x1, const float y1, const float x2, const float y2) {
    // using the euclidean distance formula
    return std::sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

float DeMath::normalizeAngle(const float angle) {
    auto resultAngle = std::remainder(angle, Defs::TWO_PI);
    if (resultAngle < 0) {
        resultAngle = Defs::TWO_PI + resultAngle;
    }
    return resultAngle;
}

float DeMath::deg2Rad(const float angle) {
    return angle * Defs::PI / 180.0f;
}

float DeMath::rad2Deg(const float angle) {
    return angle * 180.0f / Defs::PI;
}
