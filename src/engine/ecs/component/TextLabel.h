/**
* @file TextLabel.h
* @author Hudson Schumaker
* @brief Defines the TextLabel class.
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
#include "../../gfx/Gfx.h"
#include "../../math/Vec2.h"
#include "../EntityManager.h"
/**
 * @class TextLabel
 * @brief The text label component.
 */
class TextLabel final : public Component {
public:
    std::string fontName;
    SDL_Texture* label;
    bool isFixed;
    Vec2 position;
    std::string text;
    short size;
    SDL_Color color;
    int w = 0;
    int h = 0;

    TextLabel(const std::string fontName, bool isFixed, std::string text, short size, SDL_Color color) {
        this->fontName = fontName;
        this->isFixed = isFixed;
        this->text = text;
        this->size = size;
        this->position = { 0.0f, 0.0f };
        this->color = color;

        this->label = Gfx::getInstance()->createText(fontName, text, size, color);
        SDL_QueryTexture(label, NULL, NULL, &w, &h);
    }

    TextLabel(const std::string fontName, bool isFixed, Vec2 position, std::string text, short size, SDL_Color color) {
        this->fontName = fontName;
        this->isFixed = isFixed;
        this->text = text;
        this->size = size;
        this->position = position;
        this->color = color;

        this->label = Gfx::getInstance()->createText(fontName, text, size, color);
        SDL_QueryTexture(label, NULL, NULL, &w, &h);
    }

    TextLabel(const std::string fontName, bool isFixed, float x, float y, std::string text, short size, SDL_Color color) {
        this->fontName = fontName;
        this->isFixed = isFixed;
        this->text = text;
        this->size = size;
        this->position = { x, y };
        this->color = color;

        this->label = Gfx::getInstance()->createText(fontName, text, size, color);
        SDL_QueryTexture(label, NULL, NULL, &w, &h);
    }

    void changeSize(short newSize) {
        this->label = Gfx::getInstance()->createText(fontName, text, newSize, color);
        SDL_QueryTexture(label, NULL, NULL, &w, &h);
    }

    void changeColor(SDL_Color newColor) {
        this->label = Gfx::getInstance()->createText(fontName, text, size, newColor);
    }

    void setOnCenter() {
        auto parent = EntityManager::getInstance()->getEntity(parentId);
	    auto transform = parent->getComponent<Transform>();
	    if (transform) {
            auto bounds = Gfx::getInstance()->getTextureSize(label);
            position.x = transform->position.x - (bounds.w/2);
            position.y = transform->position.y - (bounds.h/2);
        }
    }

    void setOnCenterX() {
        auto parent = EntityManager::getInstance()->getEntity(parentId);
	    auto transform = parent->getComponent<Transform>();
	    if (transform) {
            auto bounds = Gfx::getInstance()->getTextureSize(label);
            position.x = transform->position.x - (bounds.w/2);
        }
    }

    void setOnCenterY() {
        auto parent = EntityManager::getInstance()->getEntity(parentId);
	    auto transform = parent->getComponent<Transform>();
	    if (transform) {
            auto bounds = Gfx::getInstance()->getTextureSize(label);
            position.y = transform->position.y - (bounds.h/2);
        }
    }

    void setOnScreenCenter() {
        auto bounds = Gfx::getInstance()->getTextureSize(label);
        position.x = float(Defs::SCREEN_H_WIDTH - (bounds.w/2));
        position.y = float(Defs::SCREEN_H_HEIGHT - (bounds.h/2));
    }

    void setOnScreenCenterX() {
        auto bounds = Gfx::getInstance()->getTextureSize(label);
        position.x = float(Defs::SCREEN_H_WIDTH - (bounds.w/2));
    }

    void setOnScreenCenterY() {
        auto bounds = Gfx::getInstance()->getTextureSize(label);
        position.y = float(Defs::SCREEN_H_HEIGHT - (bounds.h/2));
    }

    ~TextLabel() = default;
};
