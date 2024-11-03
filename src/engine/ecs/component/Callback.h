/**
* @file Callback.h
* @author Hudson Schumaker
* @brief Defines the Callback class.
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

/**
 * @class Callback
 * @brief The Callback class is a component that stores a callback function.
 */
class Callback : public Component {

public:
    typedef std::function<void(unsigned long, unsigned long)> CallbackFunction;
    Callback() {
        instance = nullptr;
    }

    Callback(const CallbackFunction& callback) {
        instance = callback;
    }

    ~Callback() = default;

    /**
     * @brief Calls the callback function.
     * @param id The id of the entity.
     * @param otherId The id of the other entity.
     */
    void call(unsigned long id, unsigned long otherId) {
       if (instance) {
           instance(id, otherId);
       }
    }

private:
    CallbackFunction instance;
};
