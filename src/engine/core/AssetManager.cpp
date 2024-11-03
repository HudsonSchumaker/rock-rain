/**
* @file AssetManager.cpp
* @author Hudson Schumaker
* @brief Implements the AssetManager class.
* @version 1.0.0
*
* Dodoi Engine is a game engine developed by Dodoi-Lab.
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
#include "../gfx/Gfx.h"
#include "../sfx/Sfx.h"
#include "AssetManager.h"
#include "../io/FileUtils.h"

AssetManager::~AssetManager() {
    clearAssets();
}

AssetManager* AssetManager::getInstance() {
    if (instance == nullptr) {
        instance = new AssetManager();
    }

    return instance;
}

void AssetManager::addTexture(const std::string& name, const short value, const std::string& filePath) {
    SDL_Texture* texture = Gfx::getInstance()->loadTexture(filePath);

    std::pair pair = { value, texture };
    this->textures.emplace(name, pair);
}

void AssetManager::addSound(const std::string& name, const std::string& filePath) {
	Mix_Chunk* sound = Sfx::getInstance()->loadSound(filePath);
	this->sounds.emplace(name, sound);
}

SDL_Texture* AssetManager::getTexture(const std::string& name) {
    return textures[name].second;
}

Mix_Chunk* AssetManager::getSound(const std::string& name) {
	return sounds[name];
}

int AssetManager::textureCount() const {
    return (int)textures.size();
}

int AssetManager::soundCount() const {
    return (int)sounds.size();
}

void AssetManager::load() {

    auto imageFuture = std::async(std::launch::async, [&]() {
        auto images = FileUtils::listImageFilesInFolder();
        for (auto& file : images) {
            auto filePath = IMAGE_FOLDER + file;
            addTexture(FileUtils::getClearName(filePath), 0, filePath);
        }
    });
    
    auto audioFuture = std::async(std::launch::async, [&]() {
        auto sounds = FileUtils::listAudioFilesInFolder();
        for (auto& file : sounds) {
		    auto filePath = AUDIO_FOLDER + file;
	    	addSound(FileUtils::getClearName(filePath), filePath);
	    }
    });

	imageFuture.get();
	audioFuture.get();
}

void AssetManager::clearAssets() {
    for (auto& texture : textures) {
        SDL_DestroyTexture(texture.second.second);
    }
    this->textures.clear();

    for (auto& sound : sounds) {
        Mix_FreeChunk(sound.second);
    }
    this->sounds.clear();
}
