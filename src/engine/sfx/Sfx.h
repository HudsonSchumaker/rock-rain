/**
* @file Sfx.h
* @author Hudson Schumaker
* @brief Defines the Sfx class.
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
#include "../../Pch.h"

class Sfx final {
private:
    inline static Sfx* instance = nullptr;
    Mix_Music* music = nullptr;
	Sfx() = default;
	
public:
    ~Sfx();
    /**
    * @brief Returns the singleton instance of the Sfx class.
    * @return Pointer to the singleton instance.
    */
    static Sfx* getInstance();

    void setSfxContext();
    Mix_Chunk* loadSound(const std::string& filePath);

    /**
    * @brief Play a sound.
    *
    * @param name The name of the sound.
    * @return The channel on which the sound is played.
    */
    int playSound(Mix_Chunk* sound);

    /**
    * @brief Play a sound with looping.
    *
    * @param name The name of the sound.
    * @param loop The number of times to loop the sound. -1 for infinite loop.
    * @return The channel on which the sound is played.
    */
    int playSound(Mix_Chunk* sound, int loop);

    /**
    * @brief Stop a sound.
    * @param channel The channel on which the sound is playing.
    */
    void stopSound(int channel);

    /**
    * @brief Stop a sound after a delay.
    *
    * @param channel The channel on which the sound is playing.
    * @param delay The delay in milliseconds before the sound is stopped.
    */
    void stopSound(int channel, int delay);

    /**
    * @brief Pause a sound.
    * @param channel The channel on which the sound is playing.
    */
    void pauseSound(int channel);

    /**
    * @brief Unpause a sound.
    * @param channel The channel on which the sound is paused.
    */
    void unPauseSound(int channel);

    /**
    * @brief Play music.
    * @param loop The number of times to loop the music. -1 for infinite loop.
    * @param filePath The file path of the music.
    */
    void playMusic(const std::string& filePath, int loop);

    /**
    * @brief Stop the music.
    */
    void stopMusic();

    /**
    * @brief Stop the music after a delay.
    * @param delay The delay in milliseconds before the music is stopped.
    */
    void stopMusic(int delay);

    /**
    * @brief Pause the music.
    */
    void pauseMusic();

    /**
    * @brief Unpause the music.
    */
    void unPauseMusic();
};
