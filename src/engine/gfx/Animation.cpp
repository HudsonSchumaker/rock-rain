/**
* @file Animation.cpp
* @author Hudson Schumaker
* @brief Implements the Animation class.
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
#include "Animation.h"
#include "../core/AssetManager.h"

Animation::Animation(const std::string& name, short numFrames, int frameSpeedRate, bool isLoop) {
	this->numFrames = numFrames;
	this->frameSpeedRate = frameSpeedRate;
	this->isLoop = isLoop;

	texture = AssetManager::getInstance()->getTexture(name);
	bounds = Gfx::getInstance()->getTextureSize(texture);
	bounds.w = bounds.w / numFrames;
	startTime = SDL_GetTicks();
}

void Animation::play() {
	isPlaying = true;
}

void Animation::stop() {
	isPlaying = false;
}

Dimension<int> Animation::getSize() const {
	return Dimension(bounds.w, bounds.h);
}
