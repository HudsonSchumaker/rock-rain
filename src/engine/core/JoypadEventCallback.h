/**
* @file JoypadEventCallback.h
* @author Hudson Schumaker
* @brief Defines the JoypadEventCallback class.
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
 * @class JoypadEventCallback
 * @brief Joypad event callback class.
 */
class JoypadEventCallback {
public:
    virtual void onJoypadButtonPress(int joypadIndex, int button) = 0;
    virtual void onJoypadButtonRelease(int joypadIndex, int button) = 0;
    virtual void onJoypadAxisMotion(int joypadIndex, int axis, int value) = 0;
};
