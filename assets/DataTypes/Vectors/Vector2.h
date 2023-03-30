#pragma once
#include <math.h>


struct Vector2
{
    float x, y;

    Vector2()
    {
        this->x = 0;
        this->y = 0;
    }

    Vector2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    Vector2 operator+(Vector2 &other)
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(Vector2 &other)
    {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator*(float other)
    {
        return Vector2(x * other, y * other);
    }

    Vector2 operator/(float &other)
    {
        return Vector2(x / other, y / other);
    }

    float Magnitude()
    {
        return sqrt(x * x + y * y);
    }

    Vector2 Normalized()
    {
        float magnitude = Magnitude();
        return Vector2(x / magnitude, y / magnitude);
    }
};
