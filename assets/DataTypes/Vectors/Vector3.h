#pragma once

#include <math.h>
#include <sstream>
#include <Matrix.h>
#include <Vector2.h>

struct Matrix;

struct Vector3
{
    float x, y, z;

    Vector3();

    Vector3(float x, float y, float z);

    operator Vector2() const;

    Vector3 operator+(Vector3 other);

    Vector3 operator-(Vector3 other);

    Vector3 operator*(float other);

    Vector3 operator/(float other);

    Matrix operator*(Matrix other);

    Matrix ToMatrix();

    float Magnitude();

    Vector3 Normalized();
};
