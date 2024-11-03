/**
* @file BasicJoypadHandler.cpp
* @author Hudson Schumaker
* @brief Implements the BasicJoypadHandler class.
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

#include "BasicJoypadHandler.h"

void BasicJoypadHandler::onJoypadButtonPress(int joypadIndex, int button) {
    if (joypadButtonPressHandlers.count(joypadIndex) && joypadButtonPressHandlers[joypadIndex].count(button)) {
        joypadButtonPressHandlers[joypadIndex][button]();
    } 
}

void BasicJoypadHandler::onJoypadButtonRelease(int joypadIndex, int button) {
    if (joypadButtonReleaseHandlers.count(joypadIndex) && joypadButtonReleaseHandlers[joypadIndex].count(button)) {
        joypadButtonReleaseHandlers[joypadIndex][button]();
    }
}

void BasicJoypadHandler::onJoypadAxisMotion(int joypadIndex, int axis, int value) {
    if (joypadAxisMotionHandlers.count(joypadIndex) && joypadAxisMotionHandlers[joypadIndex].count(axis)) {
        joypadAxisMotionHandlers[joypadIndex][axis](value);
    }
}

void BasicJoypadHandler::registerJoypadButtonPressHandler(int joypadIndex, int button, ButtonHandler handler) {
    joypadButtonPressHandlers[joypadIndex][button] = handler;
}

void BasicJoypadHandler::registerJoypadButtonReleaseHandler(int joypadIndex, int button, ButtonHandler handler) {
    joypadButtonReleaseHandlers[joypadIndex][button] = handler;
}

void BasicJoypadHandler::registerJoypadAxisMotionHandler(int joypadIndex, int axis, AxisHandler handler) {
    joypadAxisMotionHandlers[joypadIndex][axis] = handler;
}
