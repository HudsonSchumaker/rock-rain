/**
* @file Audio.h
* @author Hudson Schumaker
* @brief Defines the Audio class.
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
#include "../ecs/component/Component.h"
#include "Sfx.h"
#include "../core/AssetManager.h"

/**
* @class Audio
* @brief The audio component.
*
* This class represents an audio component that can be attached to a game object.
* It uses the AudioManager to play, pause, and stop sounds.
*/
class Audio final : public Component {
private:
    bool paused = false;

public:
    Mix_Chunk* sound = nullptr;
    int loops = 0;
    bool playOnAwake = false;
    int channel = -1;
    int delay = 0;

    /**
    * @brief Constructor that initializes the audioId.
    * @param audioId The ID of the audio to play.
    */
	Audio(const std::string& soundId) {
		sound = AssetManager::getInstance()->getSound(soundId);
	}

    /**
    * @brief Constructor that initializes the audioId, playOnAwake, and loops. If playOnAwake is true, the audio will start playing immediately.
    * @param audioId The ID of the audio to play.
    * @param playOnAwake Whether the audio should start playing immediately.
    * @param loop The number of times the audio should loop. If loop is -1, the audio will loop indefinitely.
    */
	Audio(const std::string& soundId, bool playOnAwake, int loop) {
		sound = AssetManager::getInstance()->getSound(soundId);
	}

	~Audio() {
		if (delay != 0) {
			stop(delay);
		}
		else {
			stop();
		}
	}

	void play() {
		channel = Sfx::getInstance()->playSound(sound, loops);
	}

	void play(int loop) {
		channel = Sfx::getInstance()->playSound(sound, loop);
	}

	void pause() {
		paused = paused == false ? true : false;

		if (paused) {
			Sfx::getInstance()->pauseSound(channel);
		}
		else {
			Sfx::getInstance()->unPauseSound(channel);
		}
	}

	void stop() {
		if (channel != -1) {
			Sfx::getInstance()->stopSound(channel);
		}
	}

	void stop(int delay) {
		Sfx::getInstance()->stopSound(channel, delay);
	}
};
