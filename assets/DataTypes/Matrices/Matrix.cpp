#include <Matrix.h>

using namespace std;

Matrix::Matrix(vector<vector<float>> matrix)
{
    this->matrix = matrix;
}

Matrix::Matrix(int rows, int columns)
{
    matrix.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i].resize(columns);
    }
}

Matrix::Matrix(int dimension)
{
    Matrix(dimension, dimension);
}

Matrix::~Matrix()
{
    for (auto row : matrix)
    {
        row.~vector();
    }    
    matrix.~vector();
}

Matrix::operator Vector3() const { return Vector3(matrix[0][0], matrix[0][1], matrix[0][2]); }

Matrix Matrix::operator*(Matrix other)
{
    int resultRows = matrix.size();
    int resultColumns = other.matrix[0].size();
    int width = matrix[0].size();

    Matrix result = Matrix(resultRows, resultColumns);

    for (int r = 0; r < resultRows; r++)
    {
        for (int c = 0; c < resultColumns; c++)
        {
            float sum = 0;
            for (int r_ = 0; r_ < width; r_++)
            {
                float a = matrix[r][r_];
                float b = other.matrix[r_][c];
                sum += a * b;
            }

            result.matrix[r][c] = sum;
        }
    }

    return result;
}