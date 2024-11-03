/**
* @file Scene.cpp
* @author Hudson Schumaker
* @brief Implements the prototype of Scene class.
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
#include "Scene.h"

Scene::Scene() {
    this->renderer = Gfx::getInstance()->getRenderer();
    this->camera = { 0, 0, Defs::SCREEN_WIDTH, Defs::SCREEN_HEIGHT };
}

float Scene::calculateDeltaTime() {
    // Get the current number of ticks since SDL initialization
    long currentTicks = SDL_GetTicks64();

    // Calculate the time difference since the last frame (in milliseconds)
    long frameTime = currentTicks - millisecsPreviousFrame;

    // If we are too fast, wait until we reach the desired frame time
    if (frameTime < Defs::MILLISECS_PER_FRAME) {
        SDL_Delay(Defs::MILLISECS_PER_FRAME - frameTime);
    }

    // Update the current ticks after the delay to reflect the accurate time spent
    currentTicks = SDL_GetTicks();
    
    // Compute the delta time in seconds
    deltaTime = (currentTicks - millisecsPreviousFrame) / 1000.0f;

    // Store the current frame time for the next calculation
    millisecsPreviousFrame = currentTicks;

    return deltaTime;
}

void Scene::loadAsync() {
    loadFuture = std::async(std::launch::async, &Scene::load, this);
}

void Scene::beginRender() {
    SDL_SetRenderDrawColor(renderer, camera.color.r, camera.color.g, camera.color.b, camera.color.a);
    SDL_RenderClear(renderer);
}

void Scene::endRender() {
    SDL_RenderPresent(renderer);
}

void Scene::waitForLoad() {
    if (loadFuture.valid()) {
        loadFuture.get();
        isLoaded = true;
        millisecsPreviousFrame = SDL_GetTicks64();
    }
}

const std::string& Scene::getNextScene() const {
    return nextScene;
}

bool Scene::getIsLoaded() {
    return isLoaded;
}
