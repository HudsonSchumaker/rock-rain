/**
* @file MousePointer.h
* @author Hudson Schumaker
* @brief Defines the MousePointer class and MouseButton enum.
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
#include "../../Pch.h"

/**
 * @enum MouseButton
 * @brief Enum for mouse buttons.
 */
enum class MouseButton {
    NONE,
	LEFT,
	RIGHT,
    MIDDLE,
};

/**
 * @class MousePointer
 * @brief Holds the info of the mouse position.
 */
class MousePointer final {
public:
    int x, y;
    int w, h;
    MouseButton button = MouseButton::NONE;

    MousePointer() {
        x = 0;
        y = 0;
        w = 2;
        h = 2; 
    }

    MousePointer(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
    ~MousePointer() = default;

    SDL_Rect getBounds() const {
        return SDL_Rect { x, y, w, h };
    }
};
