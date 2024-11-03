/**
* @file BasicKeyboardHandler.h
* @author Hudson Schumaker
* @brief Defines the BasicKeyboardHandler class.
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
#include "JoypadEventCallback.h"

/**
 * @class BasicJoypadHandler
 * @brief Basic Joypad handler class.
 */
class BasicJoypadHandler : public JoypadEventCallback {
public:
    using ButtonHandler = std::function<void()>;
    using AxisHandler = std::function<void(int)>;

    BasicJoypadHandler() = default;
    ~BasicJoypadHandler() = default;

    void onJoypadButtonPress(int joypadIndex, int button) override;
    void onJoypadButtonRelease(int joypadIndex, int button) override;
    void onJoypadAxisMotion(int joypadIndex, int axis, int value) override;

    void registerJoypadButtonPressHandler(int joypadIndex, int button, ButtonHandler handler);
    void registerJoypadButtonReleaseHandler(int joypadIndex, int button, ButtonHandler handler);
    void registerJoypadAxisMotionHandler(int joypadIndex, int axis, AxisHandler handler);
    
private:
    std::unordered_map<int, std::unordered_map<int, ButtonHandler>> joypadButtonPressHandlers;
    std::unordered_map<int, std::unordered_map<int, ButtonHandler>> joypadButtonReleaseHandlers;
    std::unordered_map<int, std::unordered_map<int, AxisHandler>> joypadAxisMotionHandlers;
};
