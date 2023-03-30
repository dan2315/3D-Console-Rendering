#pragma once

#include <vector>
#include <Vector3.h>

using namespace std;

struct Vector3;

struct Matrix
{
    vector<vector<float>> matrix;

    Matrix(vector<vector<float>> matrix);

    Matrix(int rows, int columns);

    Matrix(int dimension);

    ~Matrix();

    operator Vector3() const;

    Matrix operator*(Matrix other);
};