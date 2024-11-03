/**
* @file Clickable.h
* @author Hudson Schumaker
* @brief Defines the Clickable class.
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
#include "Transform.h"
#include "../EntityManager.h"

/**
 * @class Clickable
 * @brief The clickable component.
 */
class Clickable : public Component {
public:
    typedef std::function<void(unsigned long, int)> Action;
    short hover = 3;
    bool isHover = false;
    
    Clickable(const Action& action) {
        this->callback = action;
    }

    Clickable(const Action& action, short hover) {
        this->callback = action;
        this->hover = hover;
    }
    
    ~Clickable() = default;

    void setAction(const Action& action) {
       this->callback = action;
    }

    void onClick(unsigned long id, int value) {
       if (callback) {
           callback(id, value);
       }
    }

    void hoverOn() {
        if (isHover == false) {
            Entity* parent = EntityManager::getInstance()->getEntity(parentId);
            Transform* parentTransform = parent->getComponent<Transform>();
            
            if (parentTransform) {
                parentTransform->position.y += hover;
                isHover = true;
            }
        }
    }
    
    void hoverOff() {
        if (isHover) {
            Entity* parent = EntityManager::getInstance()->getEntity(parentId);
            Transform* parentTransform = parent->getComponent<Transform>();
            
            if (parentTransform) {
                parentTransform->position.y -= hover;
                isHover = false;
            }
        }
    }

private:
    Action callback = nullptr;
};
