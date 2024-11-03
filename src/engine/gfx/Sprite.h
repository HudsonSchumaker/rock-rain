/**
* @file Sprite.h
* @author Hudson Schumaker
* @brief Defines the Sprite class.
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
#include "../ecs/Entity.h"
#include "../math/Dimension.h"
#include "../ecs/component/Component.h"

/**
 * @class Sprite
 * @brief The Sprite component.
 * 
 * This class provides functionality for creating and manipulating a sprite.
 */
class Sprite final : public Component {
public:
	float w = 0.0f;
	float h = 0.0f;
	SDL_Rect srcRect;
	bool flipX = false;
	bool flipY = false;
	bool isFixed = false;
	SDL_Texture* texture = nullptr;

	Sprite(const std::string& name);
	Sprite(const std::string& name, bool isFixed);
	Sprite(const std::string& name, int srcX, int srcY, int w, int h);
	Sprite(const std::string& name, int srcX, int srcY, int w, int h, bool isFixed);
	~Sprite() = default;

	void setOnCenter();
	void setOnCenterX();
	void setOnCenterY();
	Dimension<int> getSize() const;
	void setW(float w); // to update the srcRect also.
	void setH(float h); // to update the srcRect also.
};
