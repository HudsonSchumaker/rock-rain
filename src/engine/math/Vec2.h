/**
* @file Vec2.h
* @author Hudson Schumaker
* @brief Defines the Vec2 class.
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

/**
* @class Vec2
* @brief A Vector 2D representation.
*/
class Vec2 final {
public:
    float x = 0.0f;
    float y = 0.0f;

    Vec2();
    Vec2(float value);
    Vec2(float x, float y);
    ~Vec2() {}

    /**
    * @brief Returns a vector pointing forward (1,0).
    * @return A vector pointing forward.
    */
    static Vec2 foward() {
        return Vec2(1.0f, 0.0f);
    }

    /**
    * @brief Returns a vector pointing backward (-1,0).
    * @return A vector pointing backward.
    */
    static Vec2 backward() {
        return Vec2(-1.0f, 0.0f);
    }

    /**
    * @brief Returns a vector pointing up (0,-1).
    * @return A vector pointing up.
    */
    static Vec2 up() {
        return Vec2(0.0f, -1.0f);
    }

    /**
    * @brief Returns a vector pointing down (0,1).
    * @return A vector pointing down.
    */
    static Vec2 down() {
        return Vec2(0.0f, 1.0f);
    }

    /**
    * @brief Returns a zero vector (0,0).
    * @return A zero vector.
    */
    static Vec2 zero() {
        return Vec2(0.0f, 0.0f);
    }

    /**
    * @brief Returns a vector with both components set to one (1,1).
    * @return A vector with both components set to one.
    */
    static Vec2 one() {
        return Vec2(1.0f, 1.0f);
    }

    /**
    * @brief Adds a vector to this vector.
    * @param b The vector to add.
    */
    void add(const Vec2& b);                 // a.add(b)

    /**
    * @brief Subtracts a vector from this vector.
    * @param b The vector to subtract.
    */
    void sub(const Vec2& b);                 // a.sub(b)

    /**
    * @brief Scales this vector by a scalar.
    * @param n The scalar to scale by.
    */
    void scale(const float n);               // a.scale(n)

    /**
    * @brief Rotates this vector by a given angle.
    * @param angle The angle to rotate by.
    * @return The rotated vector.
    */
    Vec2 rotate(const float angle) const;    // a.rotate(angle)

    /**
    * @brief Calculates the magnitude of this vector.
    * @return The magnitude of this vector.
    */
    float magnitude() const;                 // a.magnitude()

    /**
    * @brief Calculates the squared magnitude of this vector.
    * @return The squared magnitude of this vector.
    */
    float magnitudeSquared() const;          // a.magnitudeSquared()

    /**
    * @brief Normalizes this vector.
    * @return A reference to this vector after normalization.
    */
    Vec2& normalize();                       // a.normalize()

    /**
    * @brief Returns a unit vector in the same direction as this vector.
    * @return The unit vector.
    */
    Vec2 unitVector() const;                 // a.unitVector()

    /**
    * @brief Returns a vector that is normal (perpendicular) to this vector.
    * @return The normal vector.
    */
    Vec2 normal() const;                     // n = a.normal()

    /**
    * @brief Calculates the dot product of this vector and another vector.
    * @param b The other vector.
    * @return The dot product.
    */
    float dot(const Vec2& b) const;          // a.dot(b)

    /**
    * @brief Calculates the cross product of this vector and another vector.
    * @param b The other vector.
    * @return The cross product.
    */
    float cross(const Vec2& b) const;        // a.cross(b)

    /**
    * @brief Calculates the distance between this vector and another vector.
    * @param a The other vector.
    * @return The distance.
    */
    float distance(const Vec2& a) const;     // b.distance(a)

    /**
    * @brief Calculates the angle between this vector and another vector.
    * @param b The other vector.
    * @return The angle in radians.
    */
    float angle(const Vec2& b) const;        // a.angle(b)

    /**
    * @brief Assignment operator. Assigns another vector to this vector.
    * @param b The other vector.
    * @return A reference to this vector after the assignment.
    */
    Vec2& operator = (const Vec2& b);        // a = b

    /**
    * @brief Equality operator. Checks if this vector is equal to another vector.
    * @param b The other vector.
    * @return True if the vectors are equal, false otherwise.
    */
    bool operator == (const Vec2& b) const;  // a == b

    /**
    * @brief Inequality operator. Checks if this vector is not equal to another vector.
    * @param b The other vector.
    * @return True if the vectors are not equal, false otherwise.
    */
    bool operator != (const Vec2& b) const;  // a != b

    /**
    * @brief Addition operator. Adds this vector to another vector.
    * @param b The other vector.
    * @return The resulting vector after the addition.
    */
    Vec2 operator + (const Vec2& b) const;   // a + b

    /**
    * @brief Subtraction operator. Subtracts another vector from this vector.
    * @param b The other vector.
    * @return The resulting vector after the subtraction.
    */
    Vec2 operator - (const Vec2& b) const;   // a - b

    /**
    * @brief Multiplication operator. Multiplies this vector by a scalar.
    * @param n The scalar to multiply by.
    * @return The resulting vector after the multiplication.
    */
    Vec2 operator * (const float n) const;   // a * n

    /**
    * @brief Division operator. Divides this vector by a scalar.
    * @param n The scalar to divide by.
    * @return The resulting vector after the division.
    */
    Vec2 operator / (const float n) const;   // a / n

    /**
    * @brief Unary minus operator. Returns a vector with both components negated.
    * @return A vector with both components negated.
    */
    Vec2 operator - ();                      // -a

    /**
    * @brief Addition assignment operator. Adds a vector to this vector.
    * @param b The vector to add.
    * @return A reference to this vector after the addition.
    */
    Vec2& operator += (const Vec2& b);       // a += b

    /**
    * @brief Subtraction assignment operator. Subtracts a vector from this vector.
    * @param b The vector to subtract.
    * @return A reference to this vector after the subtraction.
    */
    Vec2& operator -= (const Vec2& b);       // a -= b

    /**
    * @brief Multiplication assignment operator. Multiplies this vector by a scalar.
    * @param n The scalar to multiply by.
    * @return A reference to this vector after the multiplication.
    */
    Vec2& operator *= (const float n);       // a *= n

    /**
    * @brief Division assignment operator. Divides this vector by a scalar.
    * @param n The scalar to divide by.
    * @return A reference to this vector after the division.
    */
    Vec2& operator /= (const float n);       // a /= n
};
