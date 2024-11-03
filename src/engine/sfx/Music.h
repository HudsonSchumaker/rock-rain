/**
* @file Music.h
* @author Hudson Schumaker
* @brief Defines the Music class.
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

/**
* @class Music
* @brief The music component.
*
* This class represents an music component that can be attached to a game object.
* It uses the AudioManager to play, pause, and stop music.
*/
class Music final : public Component {
private:
	bool paused = false;

public:
	std::string musicPath;
	int loops = 0;
	bool playOnAwake = false;
	int channel = -1;
	int delay = 0;

	/**
	* @brief Constructor that initializes the musicPath.
	* @param musicPath The path of the music to play.
	*/
	Music(std::string musicPath) {
		this->musicPath = musicPath;
	}

	/**
	* @brief Constructor that initializes the musicPath, playOnAwake, and loops. If playOnAwake is true, the music will start playing immediately.
	* @param musicPath The path of the music to play.
	* @param playOnAwake Whether the music should start playing immediately.
	* @param loop The number of times the music should loop. If loop is -1, the music will loop indefinitely.
	*/
	Music(std::string musicPath, bool playOnAwake, int loop) {
		this->musicPath = musicPath;
		this->playOnAwake = playOnAwake;
		this->loops = loop;

		if (playOnAwake) { play(); }
	}

	/**
	* @brief Destructor that stops the music. If delay is non-zero, the music will fade out over the specified delay.
	*/
	~Music() {
		if (delay != 0) {
			stop(delay);
		}
		else {
			stop();
		}
	}

	/**
	* @brief Starts playing the music with the specified number of loops.
	*/
	void play() {
		Sfx::getInstance()->playMusic(musicPath, loops);
	}

	/**
	* @brief Starts playing the music with the specified number of loops.
	* @param loop The number of times the music should loop. If loop is -1, the music will loop indefinitely.
	*/
	void play(int loop) {
		this->loops = loop;
		Sfx::getInstance()->playMusic(musicPath, loops);
	}

	/**
	* @brief Toggles the paused state of the music. If the music is currently playing, it will be paused. If it's currently paused, it will be resumed.
	*/
	void pause() {
		paused = paused == false ? true : false;

		if (paused) {
			Sfx::getInstance()->pauseMusic();
		}
		else {
			Sfx::getInstance()->unPauseMusic();
		}
	}

	/**
	* @brief Stops the music immediately.
	*/
	void stop() {
		Sfx::getInstance()->stopMusic();
	}

	/**
	* @brief Stops the music after the specified delay.
	* @param delay The delay in milliseconds before the music stops.
	*/
	void stop(int delay) {
		Sfx::getInstance()->stopMusic(delay);
	}
};
