/**
* @file Color.cpp
* @author Hudson Schumaker
* @brief Defines the Color class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
*
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
#include "Color.h"

Color::Color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}

Uint32 Color::createRGBA(SDL_Color color) {
    return createRGBA(color.r, color.g, color.b, color.a);
}

Uint32 Color::createRGBA(int r, int g, int b, int a) {
    return ((r & 0xff) << 24)
        + ((g & 0xff) << 16)
        + ((b & 0xff) << 8)
        + (a & 0xff);
}

Uint32 Color::createARGB(SDL_Color color) {
    return createARGB(color.a, color.r, color.g, color.b);
}

Uint32 Color::createARGB(int a, int r, int g, int b) {
    return ((a & 0xff) << 24)
        + ((r & 0xff) << 16)
        + ((g & 0xff) << 8)
        + (b & 0xff);
}

Uint32 Color::getHexRGBA() {
    return createRGBA(this->r, this->g, this->b, this->a);
}

Uint32 Color::getHexRGBA(SDL_Color color) {
    return createRGBA(color);
}

Uint32 Color::getHexARGB() {
    return createARGB(this->a, this->r, this->g, this->b);
}

Uint32 Color::getHexARGB(SDL_Color color) {
    return createARGB(color);
}

SDL_Color Color::fromHexRGBA(Uint32 hex) {
    SDL_Color color;
    color.r = (hex >> 16) & 0xFF;
    color.g = (hex >> 8) & 0xFF;
    color.b = hex & 0xFF;
    color.a = (hex >> 24) & 0xFF;
    return color;
}

SDL_Color Color::fromHexARGB(Uint32 hex) {
    SDL_Color color;
    color.r = (hex >> 24) & 0xFF;
    color.g = (hex >> 16) & 0xFF;
    color.b = (hex >> 8) & 0xFF;
    color.a = hex & 0xFF;
    return color;
}

void Color::changeColorIntensity(Uint32* color, float factor) {
    Uint32 a = (*color & 0xFF000000);
    Uint32 r = static_cast<Uint32>(((*color & 0x00FF0000) >> 16) * factor);
    Uint32 g = static_cast<Uint32>(((*color & 0x0000FF00) >> 8) * factor);
    Uint32 b = static_cast<Uint32>((*color & 0x000000FF) * factor);

    *color = a | ((r & 0x000000FF) << 16) | ((g & 0x000000FF) << 8) | (b & 0x000000FF);
}

SDL_Color Color::getRed() {
    SDL_Color red = { 255, 0, 0, 255 };
    return red;
}

SDL_Color Color::getGreen() {
    SDL_Color green = { 0, 255, 0, 255 };
    return green;
}

SDL_Color Color::getBlue() {
    SDL_Color blue = { 0, 0, 255, 255 };
    return blue;
}

SDL_Color Color::getWhite() {
    SDL_Color white = { 255, 255, 255, 255 };
    return white;
}

SDL_Color Color::getBlack() {
    SDL_Color black = { 0, 0, 0, 255 };
    return black;
}

SDL_Color Color::getGray() {
    SDL_Color gray = { 128, 128, 128, 255 };
    return gray;
}

SDL_Color Color::getOrange() {
    SDL_Color orange = { 255, 200, 0, 255 };
    return orange;
}

SDL_Color Color::getYellow() {
    SDL_Color yellow = { 255, 255, 0, 255 };
    return yellow;
}

SDL_Color Color::getPink() {
    SDL_Color pink = { 255, 175, 175, 255 };
    return pink;
}

SDL_Color Color::getBrown() {
    SDL_Color brown = { 78, 53, 36, 255 };
    return brown;
}

SDL_Color Color::getPurple() {
    SDL_Color purple = { 128, 0, 128, 255 };
    return purple;
}

SDL_Color Color::getTeal() {
    SDL_Color teal = { 0, 128, 128, 255 };
    return teal;
}

SDL_Color Color::getLime() {
    SDL_Color lime = { 0, 255, 0, 255 };
    return lime;
}

SDL_Color Color::getMaroon() {
    SDL_Color maroon = { 128, 0, 0, 255 };
    return maroon;
}

SDL_Color Color::getOlive() {
    SDL_Color olive = { 128, 128, 0, 255 };
    return olive;
}

SDL_Color Color::getNavy() {
    SDL_Color navy = { 0, 0, 128, 255 };
    return navy;
}

SDL_Color Color::getMagenta() {
    SDL_Color magenta = { 255, 0, 255, 255 };
    return magenta;
}

SDL_Color Color::getCyan() {
    SDL_Color cyan = { 0, 255, 255, 255 };
    return cyan;
}

SDL_Color Color::getSilver() {
    SDL_Color silver = { 192, 192, 192, 255 };
    return silver;
}

SDL_Color Color::getGold() {
    SDL_Color gold = { 255, 215, 0, 255 };
    return gold;
}

SDL_Color Color::getBeige() {
    SDL_Color beige = { 245, 245, 220, 255 };
    return beige;
}

SDL_Color Color::getCoral() {
    SDL_Color coral = { 255, 127, 80, 255 };
    return coral;
}

SDL_Color Color::getCrimson() {
    SDL_Color crimson = { 220, 20, 60, 255 };
    return crimson;
}

SDL_Color Color::getIndigo() {
    SDL_Color indigo = { 75, 0, 130, 255 };
    return indigo;
}

SDL_Color Color::getIvory() {
    SDL_Color ivory = { 255, 255, 240, 255 };
    return ivory;
}

SDL_Color Color::getKhaki() {
    SDL_Color khaki = { 240, 230, 140, 255 };
    return khaki;
}

SDL_Color Color::getLavender() {
    SDL_Color lavender = { 230, 230, 250, 255 };
    return lavender;
}

SDL_Color Color::getMint() {
    SDL_Color mint = { 189, 252, 201, 255 };
    return mint;
}

SDL_Color Color::getPeach() {
    SDL_Color peach = { 255, 218, 185, 255 };
    return peach;
}

SDL_Color Color::getPlum() {
    SDL_Color plum = { 221, 160, 221, 255 };
    return plum;
}

SDL_Color Color::getSalmon() {
    SDL_Color salmon = { 250, 128, 114, 255 };
    return salmon;
}

SDL_Color Color::getTurquoise() {
    SDL_Color turquoise = { 64, 224, 208, 255 };
    return turquoise;
}

SDL_Color Color::getViolet() {
    SDL_Color violet = { 238, 130, 238, 255 };
    return violet;
}
