#include <vector>
#include <math.h>
#include "Matrix.h"

class Matrices
{
public:
    static const Matrix ProjectionMatrix()
    {
        return Matrix({{1, 0, 0},
                       {0, 1, 0},
                       {0, 0, 0}});
    }

    static Matrix RotationMatrixAboutX(float x)
    {
        return Matrix({{1, 0, 0},
                       {0, cos(x), sin(x)},
                       {0, -sin(x), cos(x)}});
    }

    static Matrix RotationMatrixAboutY(float y)
    {
        return Matrix({{cos(y), 0, sin(y)},
                       {0, 1, 0},
                       {-sin(y), 0, cos(y)}});
    }

    static Matrix RotationMatrixAboutZ(float z)
    {
        return Matrix({{cos(z), sin(z), 0},
                       {-sin(z),cos(z), 0},
                       {0, 0, 1}});
    }

    const Matrix UnitVector = Matrix({{1, 1, 1}});
};