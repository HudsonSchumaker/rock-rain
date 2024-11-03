/**
* @file RenderTextSystem.h
* @author Hudson Schumaker
* @brief Defines the RenderTextSystem class.
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
#include "../../core/Camera.h"

/**
 * @class RenderTextSystem
 * @brief Responsible for rendering text entities in the game.
 * 
 * The RenderTextSystem class is part of the game's rendering system. It collects all the text entities in the game and renders them to the screen.
 */
class RenderTextSystem final : public System {
private:
	SDL_Renderer* renderer = nullptr;
	void renderTextLabel(Camera* camera);
	void renderSpriteText(Camera* camera);

public:
	RenderTextSystem();
	~RenderTextSystem() = default;
	void update(Camera* camera);
};
