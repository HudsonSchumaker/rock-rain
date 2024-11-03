/**
* @file Line.h
* @author Hudson Schumaker
* @brief Defines the Line class.
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
#include "../gfx/Color.h"
#include "../math/Vec2.h"
#include "../math/Dimension.h"
#include "../ecs/component/Component.h"

/**
* @class Line
* @brief A class representing a line, derived from the Component class.
*
* This class provides functionality for creating and manipulating a line.
*/
class Line final : public Component {
public:
    Vec2 b;
    bool isFixed = false;
    SDL_Color color = Color::getWhite();

    /**
    * @brief Initializes a line with the given Vec2, the A point of the line is the transform component.
    * @param b The end point of the line.
    */
    Line(Vec2 b);
    Line(float x, float y);
    Line(Vec2 b, bool isFixed);
    Line(Vec2 b, bool isFixed, SDL_Color color);
    ~Line() = default;

    Dimension<float> getSize() const;
};
