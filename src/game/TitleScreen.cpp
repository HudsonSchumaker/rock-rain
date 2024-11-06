/**
* @file TitleScreen.cpp
* @author Hudson Schumaker
* @brief Implements the TitleScreen class.
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
#include "TitleScreen.h"
#include "../engine/gfx/Box.h"
#include "../engine/gfx/Circle.h"
#include "../engine/gfx/Sprite.h"
#include "../engine/ecs/EntityManager.h"
#include "../engine/ecs/component/Waypoint.h"
#include "../engine/ecs/component/RigidBody.h"
#include "../engine/ecs/system/RenderSystem.h"
#include "../engine/ecs/system/PrimitiveRenderSystem.h"
#include "../engine/ecs/system/WaypointNavigationSystem.h"

TitleScreen::TitleScreen() : Scene() {}
TitleScreen::~TitleScreen() {
	unload();
}

void TitleScreen::load() {
	nextScene = "0";
	logoTexture = Gfx::getInstance()->loadTexture(std::string(IMAGE_FOLDER) + "title.png");
	Dimension<int> size = Gfx::getInstance()->getTextureSize(logoTexture);
	rect = {
		23, // x
		0,  // y
		size.w, // w 
		size.h  // h
	};

	isRunning = true;
}

short TitleScreen::run() {
	load();
	while (isRunning) {
		input();
		update();
		render();
	}
	return exit;
}

void TitleScreen::input() {
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

void TitleScreen::update() {
	float dt = calculateDeltaTime();
}

void TitleScreen::render() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, logoTexture, NULL, &rect);
	SDL_RenderPresent(renderer);

}

void TitleScreen::unload() {
	isLoaded = false;
	SDL_DestroyTexture(logoTexture);
}
