/**
* @file AnimationController.h
* @author Hudson Schumaker
* @brief Defines the AnimationController class.
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
#include "Animation.h"
#include "../ecs/component/Component.h"

class AnimationController final : public Component {
public:
	short actualAnimation = -1;
	std::string actualAnimationName;
	std::vector<Animation*> animations;
	std::map<std::string, short> animationNames;

	AnimationController() = default;
	~AnimationController() = default;

	void createAnimation(std::string name, const std::string& assetName, short numFrames, int frameSpeedRate);
	void createAnimation(std::string name, const std::string& assetName, short numFrames, int frameSpeedRate, bool isLoop);
	void addAnimation(std::string name, Animation* animation);
	void playAnimation();
	void playAnimation(std::string name);
	void playAnimation(short index);
	void stopAnimation();
	Animation* getActive();
	std::string getActiveName();
};
