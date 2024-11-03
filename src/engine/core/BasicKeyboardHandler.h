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
#include "KeyboardEventCallback.h"

/**
 * @class BasicKeyboardHandler
 * @brief Basic keyboard handler class.
 */
class BasicKeyboardHandler : public KeyboardEventCallback {
public:
    /**
     * @brief Key handler function type.
     */
    using KeyHandler = std::function<void()>;

    BasicKeyboardHandler() = default;
    ~BasicKeyboardHandler() = default;

    void onKeyPress(int key) override;
    void onKeyRelease(int key) override;
    void registerKeyPressHandler(int key, KeyHandler handler);
    void registerKeyReleaseHandler(int key, KeyHandler handler);

private:
    std::unordered_map<int, KeyHandler> keyPressHandlers;
    std::unordered_map<int, KeyHandler> keyReleaseHandlers;
};
