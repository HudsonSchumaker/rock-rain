/**
* @file ParallaxVertical.cpp
* @author Hudson Schumaker
* @brief Implements the ParallaxVertical class.
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
#include "ParallaxVertical.h"
#include "../gfx/Gfx.h"
#include "AssetManager.h"

ParallaxVertical::ParallaxVertical(std::string parallaxName) {
	backRect = { 0, 0, 0, 0 };

	texture = AssetManager::getInstance()->getTexture(parallaxName);
	size = { 0, 0 };
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);

	rectA = { 0, 0, size.x, size.y };
	rectB = { -size.x, 0, size.x, size.y };
}

ParallaxVertical::ParallaxVertical(std::string bgName, std::string parallaxName) {
	background = AssetManager::getInstance()->getTexture(bgName);
	backRect = Gfx::getInstance()->getTextureBounds(background);

	texture = AssetManager::getInstance()->getTexture(parallaxName);
	size = { 0, 0 };
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);

	rectA = { 0, 0, size.x, size.y };
	rectB = { 0, -size.y, size.x, size.y };
}

ParallaxVertical::~ParallaxVertical() {
	background = nullptr;
	texture = nullptr;
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(texture);
}

void ParallaxVertical::update() {
	if (rectA.y >= size.y) {
		rectA = { 0, 0, size.x, size.y };
		rectB = { 0, -size.y, size.x, size.y };
	}

	rectA.y += 1;
	rectB.y += 1;
}

void ParallaxVertical::render(SDL_Renderer* renderer) {
	if (background != nullptr) {
		SDL_RenderCopy(renderer, background, NULL, &backRect);
	}
	SDL_RenderCopy(renderer, texture, NULL, &rectA);
	SDL_RenderCopy(renderer, texture, NULL, &rectB);
}
