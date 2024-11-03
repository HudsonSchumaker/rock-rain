/**
* @file PrimitiveRenderSystem.h
* @author Hudson Schumaker
* @brief Defines the PrimitiveRenderSystem class.
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
#include "../../core/Camera.h"
#include "../../gfx/GfxTypes.h"
#include "../component/Transform.h"

/**
* @class PrimitiveRenderSystem
* @brief This class is responsible for rendering primitives in the game.
*
* The PrimitiveRenderSystem class is a part of the game's rendering system. It is responsible for
* collecting all the primitives in the game, sorting them based on their layer and z-order, and then
* rendering them to the screen.
*/
class PrimitiveRenderSystem final : public System {
private:
	using primitive_t = std::tuple<Entity*, Transform*, PrimitiveType>;
	using primitives_t = std::vector<primitive_t>;
	SDL_Renderer* renderer = nullptr;

	/**
	* @brief Collects all the primitives in the game.
	*
	* Iterates over all entities in the game, checks if they have a primitive component, and if so, adds them to the list of primitives.
	* @param primitives A pointer to a vector where the collected primitives will be stored.
	*/
	void getPrimitives(primitives_t* primitives);

	/**
	* @brief Sorts the primitives based on their layer and z-order.
	*
	* Sorts the primitives in each layer (background, middleground, foreground) separately.
	* @param background A pointer to a vector where the background primitives will be stored.
	* @param middleground A pointer to a vector where the middleground primitives will be stored.
	* @param foreground A pointer to a vector where the foreground primitives will be stored.
	*/
	void sortPrimitives(primitives_t* background, primitives_t* middleground, primitives_t* foreground);
	
	/**
	* @brief Calls the appropriate render function for the given primitive.
	*
	* Checks the type of the primitive and calls the corresponding render function (renderLine, renderBox, renderCircle).
	* @param primitive The primitive to be rendered.
	* @param camera A pointer to the camera used for rendering.
	*/
	void renderCaller(primitive_t& primitive, const Camera* camera);
	
	/**
	 * @brief Renders a line primitive.
	 * @param line The line primitive to be rendered.
	 * @param camera A pointer to the camera used for rendering.
	 */
	void renderLine(primitive_t& line, const Camera* camera);
	
	/**
	 * @brief Renders a box primitive.
	 * @param box The box primitive to be rendered.
	 * @param camera A pointer to the camera used for rendering.
	 */
	void renderBox(primitive_t& box, const Camera* camera);
	
	/**
	 * @brief Renders a circle primitive.
	 * @param circle The circle primitive to be rendered.
	 * @param camera A pointer to the camera used for rendering.
	 */
	void renderCircle(primitive_t& circle, const Camera* camera);

public:
	PrimitiveRenderSystem();
	~PrimitiveRenderSystem() = default;

	/**
	* @brief Updates the PrimitiveRenderSystem.
	*
	* Collects all the primitives in the game, sorts them based on their layer and z-order, and then renders them to the screen.
	* @param camera A pointer to the camera used for rendering.
	*/
	void update(const Camera* camera);
};
