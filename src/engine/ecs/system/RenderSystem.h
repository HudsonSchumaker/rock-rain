/**
* @file RenderSystem.h
* @author Hudson Schumaker
* @brief Defines the RenderSystem class.
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
#include "System.h"
#include "../EntityManager.h"
#include "../../core/Camera.h"
#include "../../gfx/GfxTypes.h"
#include "../component/Transform.h"

/**
* @class RenderSystem
* @brief Responsible for rendering entities in the game.
*
* The RenderSystem class is part of the game's rendering system. It collects all the renderable entities in the game, sorts them based on their layer and z-order, and then renders them to the screen.
*/
class RenderSystem final : public System {
private:
	using renderable_t = std::tuple<Entity*, Transform*, RenderType>;
	using renderables_t = std::vector<renderable_t>;

	SDL_Renderer* renderer = nullptr;

	/**
	* @brief Collects all the renderable entities in the game.
	* @param renderables A pointer to a vector where the collected renderable entities will be stored.
	 */
	void getRenderables(renderables_t* renderables);
	
	/**
	* @brief Sorts the renderable entities based on their layer and z-order.
	* @param background A pointer to a vector where the background renderable entities will be stored.
	* @param middleground A pointer to a vector where the middleground renderable entities will be stored.
	* @param foreground A pointer to a vector where the foreground renderable entities will be stored.
	*/
	void sortRenderables(renderables_t* background, renderables_t* middleground, renderables_t* foreground);

	/**
	* @brief Calls the appropriate render function for the given renderable entity.
	* @param renderable The renderable entity to be rendered.
	* @param camera A pointer to the camera used for rendering.
	*/
	void renderCaller(renderable_t& renderable, const Camera* camera);

	/**
	 * @brief Renders a sprite entity.
	 * @param renderable The renderable entity to be rendered.
	 * @param camera A pointer to the camera used for rendering.
	 */
	void renderSprite(renderable_t& renderable, const Camera* camera);
	
	/**
	 * @brief Renders a text entity.
	 * @param renderable The renderable entity to be rendered.
	 * @param camera A pointer to the camera used for rendering.
	 */
	void renderAnimation(renderable_t& renderable, const Camera* camera);
	
	/**
	 * @brief Renders a text entity.
	 * @param renderable The renderable entity to be rendered.
	 * @param camera A pointer to the camera used for rendering.
	 */
	void renderAnimationController(renderable_t& renderable, const Camera* camera);

public:
	RenderSystem();
	~RenderSystem() = default;

	/**
	* @brief Updates the RenderSystem, collecting, sorting, and rendering all renderable entities.
	* @param camera A pointer to the camera used for rendering.
	*/
	void update(const Camera* camera);
};
