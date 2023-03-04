#pragma once
#include <vector>

using namespace std;

struct Matrix
{
    Matrix(int rows, int columns)
    {
        matrix.resize(rows);
        for (int i = 0; i < rows; i++)
        {
            matrix[i].resize(columns);
        }
    }

    Matrix(int dimension)
    {
        Matrix(dimension, dimension);
    }

    vector<vector<float>> matrix;
};