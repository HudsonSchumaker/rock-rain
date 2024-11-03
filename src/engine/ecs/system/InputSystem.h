/**
* @file InputSystem.h
* @author Hudson Schumaker
* @brief Defines the InputSystem class.
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
#include "System.h"
#include "../../core/MousePointer.h"
#include "../../core/KeyboardEventCallback.h"
#include "../../core/JoypadEventCallback.h"

/**
 * @class InputSystem
 * @brief System for handling input.
 */
class InputSystem final : public System {
public:
    InputSystem() = default;
    ~InputSystem() = default;

    void update();

    void setKeyboardCallback(KeyboardEventCallback* callback);
    void setJoypadCallback(JoypadEventCallback* callback);

private:
    void handleMouseInput(const SDL_Event& sdlEvent);
    void handleKeyboardInput(const SDL_Event& sdlEvent);
    void handleJoypadInput(const SDL_Event& sdlEvent);
    
    bool isInside(const SDL_Rect& box1, const SDL_Rect& box2) const;

    MousePointer pointer;
    KeyboardEventCallback* keyboardCallback;
    JoypadEventCallback* joypadCallback;
};
