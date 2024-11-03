/**
* @file ParallaxHorizontal.h
* @author Hudson Schumaker
* @brief Defines the ParallaxHorizontal class.
* @version 1.0.0
*
* Dodoi Engine is a game engine developed by Dodoi-Lab.
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
#include "../../Pch.h"

/**
* @class ParallaxHorizontal
* @brief The ParallaxHorizontal class.
*/
class ParallaxHorizontal final {
private:
	SDL_Texture* background = nullptr;
	SDL_Texture* texture = nullptr;

	SDL_Rect backRect;
	SDL_Rect rectA;
	SDL_Rect rectB;

	SDL_Point size;

public:
	/**
	 * @brief Construct a new ParallaxHorizontal object.
	 * @param parallaxName The name of the parallax image.
	 */
	ParallaxHorizontal(std::string parallaxName);

	/**
	 * @brief Construct a new ParallaxHorizontal object.
	 * @param bgName The name of the background image.
	 * @param parallaxName The name of the parallax image.
	 */
	ParallaxHorizontal(std::string bgName, std::string parallaxName);
	~ParallaxHorizontal();

	void update();
	void render(SDL_Renderer* renderer);
};
