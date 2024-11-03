/**
* @file AnimationController.cpp
* @author Hudson Schumaker
* @brief Implements the AnimationController class.
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
#include "AnimationController.h"

void AnimationController::createAnimation(std::string name, const std::string& assetName, short numFrames, int frameSpeedRate) {
	createAnimation(name, assetName, numFrames, frameSpeedRate, true);
}

void AnimationController::createAnimation(std::string name, const std::string& assetName, short numFrames, int frameSpeedRate, bool isLoop) {
	Animation* animation = new Animation(assetName, numFrames, frameSpeedRate, isLoop);
	addAnimation(name, animation);
}

void AnimationController::addAnimation(std::string name, Animation* animation) {
	animations.push_back(animation);
	int index = int(animations.size() - 1);
	animationNames[name] = index;
	actualAnimationName = name;
}

void AnimationController::playAnimation() {
	if (actualAnimation > -1) {
		playAnimation(actualAnimation);
	}
}

void AnimationController::playAnimation(std::string name) {
	if (animationNames.count(name) > 0) {
		actualAnimationName = name;
		playAnimation(animationNames[name]);
	}
}

void AnimationController::playAnimation(short index) {
	if (index < animations.size()) {
		actualAnimation = index;
		animations[actualAnimation]->play();
	}
}

void AnimationController::stopAnimation() {
	animations[actualAnimation]->stop();
}

Animation* AnimationController::getActive() {
	return animations[actualAnimation];
}

std::string AnimationController::getActiveName() {
	return actualAnimationName;
}
