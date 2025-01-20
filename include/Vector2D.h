#pragma once

#include <cmath>

class Vector2D {
public:
    float x, y;

    Vector2D(float x = 0, float y = 0) : x(x), y(y) {}
    Vector2D operator+(const Vector2D& other) const { return {x + other.x, y + other.y}; }
    Vector2D operator-(const Vector2D& other) const { return {x - other.x, y - other.y}; }
    Vector2D operator*(float scalar) const { return {x * scalar, y * scalar}; }
    float magnitude() const { return std::sqrt(x * x + y * y); }
    Vector2D normalized() const {
        float mag = magnitude();
        return (mag == 0) ? Vector2D(0, 0) : Vector2D(x / mag, y / mag);
    }
};
