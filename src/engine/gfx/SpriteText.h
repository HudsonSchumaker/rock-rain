/**
* @file SpriteText.h
* @author Hudson Schumaker
* @brief Defines the SpriteText class.
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
#include "Gfx.h"
#include "../math/Vec2.h"
#include "../ecs/component/Component.h"

/**
 * @class SpriteText
 * @brief The SpriteText component.
 * 
 * This class provides functionality for creating and manipulating a text sprite.
 */
class SpriteText final : public Component {
public:
	std::string fontName;
    SDL_Texture* label;
    bool isFixed;
    Vec2 offSet;
	Vec2 position;
    std::string text;
    short size;
    SDL_Color color;
    int w = 0;
    int h = 0;

	SpriteText(const std::string fontName, bool isFixed, float offsetX, float offsetY, std::string text, short size, SDL_Color color):
	SpriteText(fontName, isFixed, {offsetX, offsetY}, text, size, color) {}

	SpriteText(const std::string fontName, bool isFixed, Vec2 offSet, std::string text, short size, SDL_Color color) {
		this->fontName = fontName;
        this->isFixed = isFixed;
        this->text = text;
        this->size = size;
        this->offSet = offSet;
        this->color = color;

        this->label = Gfx::getInstance()->createText(fontName, text, size, color);
        SDL_QueryTexture(label, NULL, NULL, &w, &h);
	}

    ~SpriteText() = default;
};
