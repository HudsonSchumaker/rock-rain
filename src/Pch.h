/**
* @file Pch.h
* @author Hudson Schumaker
* @brief Pch includes and definitions for the Dodoi-Engine.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* This file includes the necessary C++ and SDL2 libraries that are used throughout the dodoi-engine-ns.
* It also defines constants for the paths to various types of assets.
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
// C++ includes
#include <set>
#include <map>
#include <list>
#include <array>
#include <cmath>
#include <limits>
#include <vector>
#include <random>
#include <chrono>
#include <future>
#include <string>
#include <thread>
#include <variant>
#include <utility>
#include <fstream>
#include <iostream>
#include <typeindex>
#include <algorithm>
#include <filesystem>
#include <functional>
#include <unordered_map>
#include <unordered_set>

// SDL2 includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_gamecontroller.h>

// Dodoi-Engine folders
#define AUDIO_FOLDER "./data/audios/"
#define FONT_FOLDER "./data/fonts/"
#define IMAGE_FOLDER "./data/images/"
#define MAP_FOLDER "./data/maps/"

/**
 * @brief The Defs class contains all the constants used in the Dodoi-Engine.
 * @version 1.0.0
 */
class Defs final {
public:
    inline static const char NAME[] = "Dodoi Engine v.0.60.10-macOS";

    static const int FPS = 125;
    static const int MILLISECS_PER_FRAME = 1000 / FPS;
	
    constexpr static const float PI = 3.14159265358979323846f;
    constexpr static const float TWO_PI = 2.0f * PI;

    static const int SCREEN_WIDTH = 1280;
    static const int SCREEN_H_WIDTH = SCREEN_WIDTH / 2;
    static const int SCREEN_HEIGHT = 720;
    static const int SCREEN_H_HEIGHT = SCREEN_HEIGHT / 2; 
};
