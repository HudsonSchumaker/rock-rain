/**
* @file Circle.h
* @author Hudson Schumaker
* @brief Defines the Circle class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
*
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
#include "../gfx/Color.h"
#include "../math/Dimension.h"
#include "../ecs/component/Component.h"

/**
 * @class Circle
 * @brief A class representing a circle, derived from the Component class.
 *
 * This class provides functionality for creating and manipulating a circle.
 */
class Circle final : public Component {
private:
    int radius = 0;

public:
    float side = 0.0f;
    bool isFixed = false;
    bool isFilled = false;
    bool isDashed = false;
    short dashLength = 8;
    SDL_Color color = Color::getWhite();

    Circle();
    Circle(int radius);
    Circle(int radius, bool isFixed);
    Circle(int radius, bool isFixed, bool isFilled, SDL_Color color);
    Circle(int radius, bool isFixed, short dashLength, SDL_Color color);
    ~Circle() = default;

    /**
    * @brief Calculates the side length of the circle from the radius.
    * for creating a square that contains the circle.
    */
    void sideCalculation();

    /**
    * @brief Sets the radius of the circle and recalculates the side.
    * @param radius The new radius of the circle.
    */
    void setRadius(int radius);
    int getRadius() const;
    Dimension<int> getSize() const;
};
