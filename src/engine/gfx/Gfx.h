/**
* @file Gfx.h
* @author Hudson Schumaker
* @brief Defines the Gfx class.
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
#include "../math/Dimension.h"

/**
* @class Gfx
* @brief The graphics hanlder class.
*
* This class provides functionality for creating and manipulating graphics.
*/
class Gfx final {
private:
    inline static Gfx* instance = nullptr;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    Gfx() = default;

public:
    ~Gfx();

    /**
    * @brief Returns the singleton instance of the Gfx class.
    * @return Pointer to the singleton instance.
    */
    static Gfx* getInstance();

    /**
    * @brief Initializes the SDL library and creates the SDL_Window and SDL_Renderer.
    */
    void setGfxContext();

    /**
    * @brief Returns the SDL_Window.
    * @return Pointer to the SDL_Window.
    */
    SDL_Window* getWindow();

    /**
    * @brief Returns the SDL_Renderer.
    * @return Pointer to the SDL_Renderer.
    */
    SDL_Renderer* getRenderer();

    /**
    * @brief Shows or hides the mouse cursor.
    * @param value If true, the mouse cursor is shown. If false, the mouse cursor is hidden.
    */
    void showMouseCursor(bool value);

    /**
    * @brief Creates an SDL_Texture from a string of text.
    * @param fontName The name of the font to use.
    * @param text The text to render.
    * @param size The size of the text.
    * @param color The color of the text.
    * @return Pointer to the created SDL_Texture.
    */
    SDL_Texture* createText(const std::string& fontName, std::string text, short size, SDL_Color color);

    /**
    * @brief Loads an image file into an SDL_Texture.
    * @param name The name (path) of the image file.
    * @return Pointer to the loaded SDL_Texture.
    */
    SDL_Texture* loadTexture(const std::string& filePath);

    /**
    * @brief Returns the size of an SDL_Texture.
    * @param texture Pointer to the SDL_Texture.
    * @return The size of the texture as a Dimension<int>.
    */
    Dimension<int> getTextureSize(SDL_Texture* texture);

    /**
    * @brief Returns the bounds of an SDL_Texture as an SDL_Rect.
    * @param texture Pointer to the SDL_Texture.
    * @return The bounds of the texture as an SDL_Rect.
    */
    SDL_Rect getTextureBounds(SDL_Texture* texture);

    /**
    * @brief Returns the bounds of an SDL_Texture as an SDL_FRect.
    * @param texture Pointer to the SDL_Texture.
    * @return The bounds of the texture as an SDL_FRect.
    */
    SDL_FRect getTextureFBounds(SDL_Texture* texture);

    // Primitives
    /**
    * @brief Draws a line on the renderer.
    * @param x0 The x-coordinate of the start point of the line.
    * @param y0 The y-coordinate of the start point of the line.
    * @param x1 The x-coordinate of the end point of the line.
    * @param y1 The y-coordinate of the end point of the line.
    * @param color The color of the line.
    */
    void drawLine(const int x0, const int y0, const int x1, const int y1, const SDL_Color& color);

    /**
    * @brief Draws a circle on the renderer.
    * @param centerX The x-coordinate of the center of the circle.
    * @param centerY The y-coordinate of the center of the circle.
    * @param radius The radius of the circle.
    * @param color The color of the circle.
    */
    void drawCircle(const int centerX, const int centerY, const int radius, const SDL_Color& color);

    /**
    * @brief Draws a filled circle on the renderer.
    * @param centerX The x-coordinate of the center of the circle.
    * @param centerY The y-coordinate of the center of the circle.
    * @param radius The radius of the circle.
    * @param color The color of the circle.
    */
    void drawFillCircle(const int centerX, const int centerY, const int radius, const SDL_Color& color);

    /**
    * @brief Draws a dashed circle on the renderer.
    * @param centerX The x-coordinate of the center of the circle.
    * @param centerY The y-coordinate of the center of the circle.
    * @param radius The radius of the circle.
    * @param dashLength The length of the dashes.
    * @param color The color of the circle.
    */
    void drawDashedCircle(const int centerX, const int centerY, const int radius, const int dashLength, const SDL_Color& color);

    /**
    * @brief Draws a box on the renderer.
    * @param rect The SDL_FRect defining the box.
    * @param color The color of the box.
    */
    void drawBox(const SDL_FRect& rect, const SDL_Color& color);

    /**
    * @brief Draws a filled box on the renderer.
    * @param rect The SDL_FRect defining the box.
    * @param color The color of the box.
    */
    void drawFillBox(const SDL_FRect& rect, const SDL_Color& color);
};
