/**
* @file AudioManager.cpp
* @author Hudson Schumaker
* @brief Implements the AudioManager class.
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
#include "AudioManager.h"
#include "../io/FileUtils.h"

AudioManager::~AudioManager() {
	clearAssets();
}

AudioManager* AudioManager::getInstance() {
	if (instance == nullptr) {
		instance = new AudioManager();
	}

	return instance;
}

void AudioManager::addSound(const std::string& name, const std::string& filePath) {
	this->sounds.emplace(name, Mix_LoadWAV(filePath.c_str()));
}

int AudioManager::playSound(const std::string& name) {
	return playSound(name, 0);
}

int AudioManager::playSound(const std::string& name, int loop) {
	return Mix_PlayChannel(-1, this->sounds[name], loop);
}

void AudioManager::stopSound(int channel) {
	Mix_HaltChannel(channel);
}

void AudioManager::stopSound(int channel, int delay) {
	Mix_FadeOutChannel(channel, delay);
}

void AudioManager::pauseSound(int channel) {
	Mix_Pause(channel);
}

void AudioManager::unPauseSound(int channel) {
	Mix_Resume(channel);
}

void AudioManager::playMusic(const std::string& filePath, int loop) {
	auto res = std::async(std::launch::async, [&]() {
		music = Mix_LoadMUS(filePath.c_str());
		Mix_PlayMusic(music, loop);
	});
}

void AudioManager::stopMusic() {
	Mix_HaltMusic();
}

void AudioManager::stopMusic(int delay) {
	Mix_FadeOutMusic(delay);
}

void AudioManager::pauseMusic() {
	Mix_PauseMusic();
}

void AudioManager::unPauseMusic() {
	Mix_ResumeMusic();
}

void AudioManager::load() {
	auto files = FileUtils::listAudioFilesInFolder();
	for (auto& file : files) {
		auto filePath = AUDIO_FOLDER + file;
		addSound(FileUtils::getClearName(filePath), filePath);
	}
}

int AudioManager::audioCount() const {
	return (int)sounds.size();
}

void AudioManager::clearAssets() {
	for (auto& sound : sounds) {
		Mix_FreeChunk(sound.second);
	}
	sounds.clear();
	Mix_FreeMusic(music);
}
