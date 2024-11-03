/**
* @file InputSystem.cpp
* @author Hudson Schumaker
* @brief Implements the InputSystem class.
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
#include "InputSystem.h"
#include "../EntityManager.h"
#include "../../event/EventBus.h"
#include "../component/Clickable.h"
#include "../component/Transform.h"
#include "../component/BoxCollider.h"

void InputSystem::update() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                handleMouseInput(sdlEvent);
                break;
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                handleKeyboardInput(sdlEvent);
                break;
            case SDL_JOYBUTTONDOWN:
            case SDL_JOYBUTTONUP:
            case SDL_JOYAXISMOTION:
                handleJoypadInput(sdlEvent);
                break;
        }
    }
}

void InputSystem::handleMouseInput(const SDL_Event& sdlEvent) {
    auto entities = EntityManager::getInstance()->getEntitiesWithComponent<Clickable>();

    // Update the mouse pointer position based on the event type
    if (sdlEvent.type == SDL_MOUSEMOTION) {
        pointer.x = sdlEvent.motion.x;
        pointer.y = sdlEvent.motion.y;
    } else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN || sdlEvent.type == SDL_MOUSEBUTTONUP) {
        pointer.x = sdlEvent.button.x;
        pointer.y = sdlEvent.button.y;
    }

	for (auto& entity : entities) {
        auto components = entity->getComponents<Clickable, BoxCollider, Transform>();
        Clickable* clickable = std::get<0>(components); // Get the Clickable component
        BoxCollider* collider = std::get<1>(components);// Get the BoxCollider component
        Transform* transform = std::get<2>(components); // Get the Transform component

        if (collider) {
            SDL_Rect box = { 
                static_cast<int>(transform->position.x), 
                static_cast<int>(transform->position.y),
                collider->bounds.w, 
                collider->bounds.h 
            };

            bool isHovering = isInside(pointer.getBounds(), box);
            EventBus::getInstance()->emitEventAsync<MouseHoverEvent>(entity, isHovering);

            if (isHovering) {
                if (sdlEvent.button.button == SDL_BUTTON_LEFT) {
                    clickable->onClick(entity->id, static_cast<int>(MouseButton::LEFT));
                    continue;
                }
                if (sdlEvent.button.button == SDL_BUTTON_RIGHT) {
                    clickable->onClick(entity->id, static_cast<int>(MouseButton::RIGHT));
                    continue;
                }
                if (sdlEvent.button.button == SDL_BUTTON_MIDDLE) {
                    clickable->onClick(entity->id, static_cast<int>(MouseButton::MIDDLE));
                }
            }
        }
    }
}

void InputSystem::handleKeyboardInput(const SDL_Event& sdlEvent) {
    if (keyboardCallback) {
        if (sdlEvent.type == SDL_KEYDOWN) {
            keyboardCallback->onKeyPress(sdlEvent.key.keysym.sym);
        } else {
            keyboardCallback->onKeyRelease(sdlEvent.key.keysym.sym);
        }
    }
}

void InputSystem::handleJoypadInput(const SDL_Event& sdlEvent) {
    if (joypadCallback) {
        int joypadIndex = sdlEvent.jaxis.which; // Default to axis event

        if (sdlEvent.type == SDL_JOYAXISMOTION) {
            joypadIndex = sdlEvent.jaxis.which;
            joypadCallback->onJoypadAxisMotion(joypadIndex, sdlEvent.jaxis.axis, sdlEvent.jaxis.value);
            return;
        }

        if (sdlEvent.type == SDL_JOYBUTTONDOWN) {
            joypadIndex = sdlEvent.jbutton.which;
            joypadCallback->onJoypadButtonPress(joypadIndex, sdlEvent.jbutton.button);
            return;
        } 
        
        if (sdlEvent.type == SDL_JOYBUTTONUP) {
            joypadIndex = sdlEvent.jbutton.which;
            joypadCallback->onJoypadButtonRelease(joypadIndex, sdlEvent.jbutton.button);
        } 
    }
}

void InputSystem::setKeyboardCallback(KeyboardEventCallback* callback) {
    this->keyboardCallback = callback;
}

void InputSystem::setJoypadCallback(JoypadEventCallback* callback) {
    this->joypadCallback = callback;
}

bool InputSystem::isInside(const SDL_Rect& box1, const SDL_Rect& box2) const {
    // Calculate the AABBs
    SDL_Rect aabb1 = { box1.x - box1.w / 2, box1.y - box1.h / 2, box1.w, box1.h };
    SDL_Rect aabb2 = { box2.x - box2.w / 2, box2.y - box2.h / 2, box2.w, box2.h };

    // Check if aabb1 is completely inside aabb2
    return (aabb1.x >= aabb2.x && aabb1.y >= aabb2.y &&
            aabb1.x + aabb1.w <= aabb2.x + aabb2.w &&
            aabb1.y + aabb1.h <= aabb2.y + aabb2.h);
}
