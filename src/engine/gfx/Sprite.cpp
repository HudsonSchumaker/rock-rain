/**
* @file Sprite.cpp
* @author Hudson Schumaker
* @brief Implements the Sprite class.
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
#include "Gfx.h"
#include "Sprite.h"
#include "../core/AssetManager.h"
#include "../ecs/EntityManager.h"
#include "../ecs/component/Transform.h"

Sprite::Sprite(const std::string& name) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = Gfx::getInstance()->getTextureBounds(texture);
	w = (float)srcRect.w;
	h = (float)srcRect.h;
}

Sprite::Sprite(const std::string& name, bool isFixed) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = Gfx::getInstance()->getTextureBounds(texture);
	w = (float)srcRect.w;
	h = (float)srcRect.h;
	this->isFixed = isFixed;
}

Sprite::Sprite(const std::string& name, int srcX, int srcY, int w, int h) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = {
		srcX,
		srcY,
		w,
		h
	};

	this->w = (float)srcRect.w;
	this->h = (float)srcRect.h;
}

Sprite::Sprite(const std::string& name, int srcX, int srcY, int w, int h, bool isFixed) {
	texture = AssetManager::getInstance()->getTexture(name);
	srcRect = {
		srcX,
		srcY,
		w,
		h
	};

	this->w = (float)srcRect.w;
	this->h = (float)srcRect.h;
	this->isFixed = isFixed;
}

void Sprite::setOnCenter() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		auto bounds = Gfx::getInstance()->getTextureSize(texture);

		transform->position.x = (float)(Defs::SCREEN_H_WIDTH - (bounds.w / 2));
		transform->position.y = (float)(Defs::SCREEN_H_HEIGHT - (bounds.h / 2));
	}
}

void Sprite::setOnCenterX() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		auto bounds = Gfx::getInstance()->getTextureSize(texture);
		transform->position.x = (float)(Defs::SCREEN_H_WIDTH - (bounds.w / 2));
	}
}

void Sprite::setOnCenterY() {
	auto parent = EntityManager::getInstance()->getEntity(parentId);
	auto transform = parent->getComponent<Transform>();
	if (transform) {
		auto bounds = Gfx::getInstance()->getTextureSize(texture);
		transform->position.y = (float)(Defs::SCREEN_H_HEIGHT - (bounds.h / 2));
	}
}

void Sprite::setW(float w) {
	this->w = w;
	srcRect.w = (int)w;
}

void Sprite::setH(float h) {
	this->h = h;
	srcRect.h = (int)h;
}

Dimension<int> Sprite::getSize() const {
	return Dimension((int)w, (int)h);
}
