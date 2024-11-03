/**
* @file Vec2.cpp
* @author Hudson Schumaker
* @brief Implements the Vec2 class.
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
#include "Vec2.h"
#include "DeMath.h"

Vec2::Vec2() : x(0.0f), y(0.0f) {}
Vec2::Vec2(float value) : x(value), y(value) {}
Vec2::Vec2(float x, float y) : x(x), y(y) {}

void Vec2::add(const Vec2& b) {
	x += b.x;
	y += b.y;
}

void Vec2::sub(const Vec2& b) {
	x -= b.x;
	y -= b.y;
}

void Vec2::scale(const float n) {
	x *= n;
	y *= n;
}

Vec2 Vec2::rotate(const float angle) const {
	float sine   = std::sinf(angle);
	float cosine = std::cosf(angle);

	Vec2 result;
	result.x = x * cosine - y * sine;
	result.y = x * sine   + y * cosine;
	return result;
}

float Vec2::magnitude() const {
	float magnitude = 0.1f;
	if (x != 0 || y != 0) { // To avoid division by zero
		magnitude = std::sqrtf(x * x + y * y);
	}
	return magnitude;
}

float Vec2::magnitudeSquared() const {
	return (x * x + y * y);
}

Vec2& Vec2::normalize() {
	float length = magnitude();
	if (length != 0.0) {
		x /= length;
		y /= length;
	}
	return *this;
}

Vec2 Vec2::unitVector() const {
	Vec2 result = Vec2(0, 0);
	float length = magnitude();
	if (length != 0.0) {
		result.x = x / length;
		result.y = y / length;
	}
	return result;
}

Vec2 Vec2::normal() const {
	return Vec2(y, -x).normalize();
}

float Vec2::dot(const Vec2& b) const {
	return (x * b.x) + (y * b.y);
}

float Vec2::cross(const Vec2& b) const {
	return (x * b.y) - (y * b.x);
}

float Vec2::distance(const Vec2& a) const { // b.distance(a)
	float dx = x - a.x;
	float dy = y - a.y;
	return std::sqrtf(dx * dx + dy * dy);
}

float Vec2::angle(const Vec2& b) const {
	return std::atan2(cross(b), dot(b));
}

Vec2& Vec2::operator = (const Vec2& b) {
	x = b.x;
	y = b.y;
	return *this;
}

bool Vec2::operator == (const Vec2& b) const {
	return x == b.x && y == b.y;
}

bool Vec2::operator != (const Vec2& b) const {
	return !(*this == b);
}

Vec2 Vec2::operator + (const Vec2& b) const {
	Vec2 result;
	result.x = x + b.x;
	result.y = y + b.y;
	return result;
}

Vec2 Vec2::operator - (const Vec2& b) const {
	Vec2 result;
	result.x = x - b.x;
	result.y = y - b.y;
	return result;
}

Vec2 Vec2::operator * (const float n) const {
	Vec2 result;
	result.x = x * n;
	result.y = y * n;
	return result;
}

Vec2 Vec2::operator / (const float n) const {
	Vec2 result;
	result.x = x / n;
	result.y = y / n;
	return result;
}

Vec2& Vec2::operator += (const Vec2& b) {
	x += b.x;
	y += b.y;
	return *this;
}

Vec2& Vec2::operator -= (const Vec2& b) {
	x -= b.x;
	y -= b.y;
	return *this;
}

Vec2& Vec2::operator *= (const float n) {
	x *= n;
	y *= n;
	return *this;
}

Vec2& Vec2::operator /= (const float n) {
	x /= n;
	y /= n;
	return *this;
}

Vec2 Vec2::operator - () {
	Vec2 result;
	result.x = x * -1;
	result.y = y * -1;
	return result;
}
