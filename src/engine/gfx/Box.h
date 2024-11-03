/**
* @file Box.h
* @author Hudson Schumaker
* @brief Defines the Box class.
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
* @class Box
* @brief Represents a box, derived from the Component class.
*
* It represents a box component in the game, with properties such as width, height, fixed status, and color.
*/
class Box final : public Component {
public:
    int w = 0;
    int h = 0;
    bool isFixed = false;
    bool isFilled = false;
    SDL_Color color = Color::getWhite();

    Box();
    Box(int w, int h);
    Box(int w, int h, bool isFixed);
    Box(int w, int h, bool isFixed, SDL_Color color);
    Box(int w, int h, bool isFixed, bool isFilled, SDL_Color color);
    ~Box() = default;

    void setOnCenter();
    inline Dimension<int> getSize() const;
};
