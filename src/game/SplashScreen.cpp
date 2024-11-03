/**
* @file SplashScreen.cpp
* @author Hudson Schumaker
* @brief Implements the SplashScreen class.
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
#include "SplashScreen.h"

SplashScreen::SplashScreen() : Scene() {}
SplashScreen::~SplashScreen() {
	unload();
}

void SplashScreen::load() {
	logoTexture = Gfx::getInstance()->loadTexture(std::string(IMAGE_FOLDER) + "logo.png");
	Dimension<int> size = Gfx::getInstance()->getTextureSize(logoTexture);
	rect = {
		Defs::SCREEN_H_WIDTH  - (size.w / 2) - 20, // x
		Defs::SCREEN_H_HEIGHT - (size.h / 2) - 20, // y
		size.w,                                    // w 
		size.h                                     // h
	};
	isRunning = true;
}

short SplashScreen::run() {
	load();
	while (isRunning) {
		input();
		update();
		render();
	}
	return exit;
}

void SplashScreen::input() {
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
		case SDL_QUIT:
			isRunning = false;
			exit = 1; //TODO: Change to an enum
			break;
		}
	}
}

void SplashScreen::update() {
	static char times = 0;
	SDL_Delay(499);
	times++;
	if (times > 6) {
		isRunning = false;
	}
}

void SplashScreen::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, logoTexture, NULL, &rect);
	SDL_RenderPresent(renderer);
}

void SplashScreen::unload() {
	isLoaded = false;
	SDL_DestroyTexture(logoTexture);
}
