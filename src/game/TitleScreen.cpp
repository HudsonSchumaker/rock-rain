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
	logoTexture = Gfx::getInstance()->loadTexture("dodoi.png");
	Dimension<int> size = Gfx::getInstance()->getTextureSize(logoTexture);
	rect = {
		Defs::SCREEN_H_WIDTH - (size.w / 2) - 20,  // x
		Defs::SCREEN_H_HEIGHT - (size.h / 2) - 20, // y
		size.w,                                    // w 
		size.h                                     // h
	};

	//for (int i = 0; i < 100000; i++) {
	//	auto entity = EntityManager::getInstance()->createEntity(1 + i * 2, 1 + i * 2, Tag::COIN);
	//	entity->addComponent(new Box(30, 30, false, Color::getWhite()))->isFilled = false;
	//	entity->layer = Layer::MIDDLEGROUND; // Set layer to BACKGROUND
	//	entity->zIndex = i; // Set z-order
	//}

	//for (int i = 0; i < 100000; i++) {
	//	auto entity = EntityManager::getInstance()->createEntity(10 + i * 10, 10 + i * 10, Tag::COIN);
	//	entity->addComponent(new Box(30, 30, false, Color::getGold()))->isFilled = false;
	//	entity->layer = Layer::BACKGROUND; // Set layer to BACKGROUND
	//	entity->zIndex = i; // Set z-order
	//}

	for (int i = 0; i < 1000; i++) {
		auto a = EntityManager::getInstance()->createEntity(i, i, Tag::COIN);
		a->addComponent(new Sprite("avatarShadow"));
		a->layer = Layer::MIDDLEGROUND; // Set layer to BACKGROUND
		a->addComponent(new RigidBody(32.0f, 32.0f));
		auto w = a->addComponent(new Waypoint({ 300,456 }));
		w->addPoint({ 100,600 });
		w->addPoint({ 500,455 });
		w->addPoint({ 300,100 });

		auto b = EntityManager::getInstance()->createEntity(i, i, Tag::COIN);
		b->addComponent(new Box(50, 50, false, Color::getGreen()))->isFilled = true;
		b->layer = Layer::MIDDLEGROUND; // Set layer to BACKGROUND
		b->addComponent(new RigidBody(18.0f, 18.0f));
		b->addComponent(new Waypoint({ 500,456 }));

		auto c = EntityManager::getInstance()->createEntity(i, i, Tag::COIN);
		c->addComponent(new Box(50, 50, false, Color::getBrown()))->isFilled = true;
		c->layer = Layer::MIDDLEGROUND; // Set layer to BACKGROUND
		c->addComponent(new RigidBody(18, 18));
		c->addComponent(new Waypoint({ 900,100 }));

		auto d = EntityManager::getInstance()->createEntity(i, i, Tag::COIN);
		d->addComponent(new Circle(25, false, false, Color::getRed()))->isDashed = true;
		d->layer = Layer::FOREGROUND; // Set layer to BACKGROUND
		d->zIndex = 3; // Set z-order
		d->addComponent(new RigidBody(18.0f, 18.0f));
		d->addComponent(new Waypoint({ 456,399 }));
	}

	// Create a new box
	auto a = EntityManager::getInstance()->createEntity(70, 67, Tag::COIN);
	a->addComponent(new Box(50, 50, false, Color::getGray()))->isFilled = true;
	a->layer = Layer::BACKGROUND; // Set layer to BACKGROUND
	/*a->addComponent(new RigidBody(28.0f, 28.0f));
	auto waypoint = a->addComponent(new Waypoint({300,456}));
	waypoint->addPoint({ 100,200 });*/

	auto b = EntityManager::getInstance()->createEntity(55, 55, Tag::COIN);
	b->addComponent(new Box(50, 50, false, Color::getMagenta()))->isFilled = true;
	b->layer = Layer::MIDDLEGROUND; // Set layer to BACKGROUND
	b->zIndex = 1; // Set z-order
	b->addComponent(new RigidBody(18.0f, 18.0f));
	b->addComponent(new Waypoint({ 500,456 }));

	auto c = EntityManager::getInstance()->createEntity(60, 60, Tag::COIN);
	c->addComponent(new Box(50, 50, false, Color::getOrange()))->isFilled = true;
	c->layer = Layer::MIDDLEGROUND; // Set layer to BACKGROUND
	c->zIndex = 8; // Set z-order
	c->addComponent(new RigidBody(18, 18));
	c->addComponent(new Waypoint({ 900,100 }));

	auto d = EntityManager::getInstance()->createEntity(100, 60, Tag::COIN);
	d->addComponent(new Circle(25, false, false, Color::getPurple()))->isDashed = true;
	d->layer = Layer::FOREGROUND; // Set layer to BACKGROUND
	d->zIndex = 3; // Set z-order
	d->addComponent(new RigidBody(18.0f, 18.0f));

	isRunning = true;
}

short TitleScreen::run() {
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
	WaypointNavigationSystem nav;
	nav.update(dt);
}

void TitleScreen::render() {
	beginRender();
	{
		//SDL_RenderCopy(renderer, logoTexture, NULL, &rect);
		PrimitiveRenderSystem render;
		render.update(&camera);

		RenderSystem renderSystem;
		renderSystem.update(&camera);
	}
	endRender();
}

void TitleScreen::unload() {
	isLoaded = false;
	SDL_DestroyTexture(logoTexture);
}
