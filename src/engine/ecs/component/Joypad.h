/**
* @file Joypad.h
* @author Hudson Schumaker
* @brief Defines the Joypad class.
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

/**
* @class Joypad
* @brief Defines the Joypad component.
*/
class Joypad : public Component {
public:
    Vec2 direction;
    int joypadId;

    Joypad(int id) : joypadId(id), direction(Vec2::zero()) {}
    ~Joypad() = default;
};
