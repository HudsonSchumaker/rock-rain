/**
* @file Radar.h
* @author Hudson Schumaker
* @brief Defines the Radar class.
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
#include "../TLG.h"
#include "../../math/Vec2.h"

/**
 * @class Radar
 * @brief The Radar class is a component that allows to detect other entities within a certain radius.
 */
class Radar final : public Component {
public:
    typedef std::function<void(unsigned long, unsigned long)> OnDetectFunction;
    short r = 2; // radius
    Tag tag = Tag::ENEMY;
    Vec2 offset;

    Radar(const OnDetectFunction& onDetect, short radius) {
        this->callback = onDetect;
        this->r = radius;
    }

    Radar(const OnDetectFunction& onDetect, short radius, Tag tag) {
        this->callback = onDetect;
        this->r = radius;
        this->tag = tag;
    }

    Radar(const OnDetectFunction& onDetect, short radius, Vec2 offset) {
        this->callback = onDetect;
        this->r = radius;
        this->offset = offset;
    }

    Radar(const OnDetectFunction& onDetect, short radius, Tag tag, Vec2 offset) {
        this->callback = onDetect;
        this->r = radius;
        this->tag = tag;
        this->offset = offset;
    }
    
    ~Radar() = default;

    void setOnDetect(const OnDetectFunction& onDetect) {
        this->callback = onDetect;
    }

    void onDetect(unsigned long radar, unsigned long target) {
        if (callback) {
            callback(radar, target);
        }
    }

private:
    OnDetectFunction callback = nullptr;
};
