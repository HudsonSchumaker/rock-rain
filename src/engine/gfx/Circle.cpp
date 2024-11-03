/**
* @file Circle.cpp
* @author Hudson Schumaker
* @brief Implements the Circle class.
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
#include "Circle.h"
#include "../math/DeMath.h"

Circle::Circle() : radius(2) { sideCalculation(); }
Circle::Circle(int radius) : radius(radius) { sideCalculation(); }
Circle::Circle(int radius, bool isFixed) : radius(radius), isFixed(isFixed) { sideCalculation(); }
Circle::Circle(int radius, bool isFixed, bool isFilled, SDL_Color color) :
    radius(radius), isFixed(isFixed), isFilled(isFilled), color(color) {

    sideCalculation();
}

Circle::Circle(int radius, bool isFixed, short dashLength, SDL_Color color)
    : radius(radius), isFixed(isFixed), dashLength(dashLength), color(color) {

    isDashed = true;
    sideCalculation();
}

void Circle::sideCalculation() {
    side = std::sqrtf(2.0f) * radius;
}

Dimension<int> Circle::getSize() const {
    return Dimension((int)side, (int)side);
}

int Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(int radius) {
    this->radius = radius;
    sideCalculation();
}
