#include <math.h>
#include <sstream>

struct Vector3
{
    float x, y, z;

    Vector3()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Vector3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    operator Vector2() const { return Vector2(x, y); }

    Vector3 operator+(Vector3 other)
    {
        return Vector3(x + other.x, y + other.y,z + other.z );
    }

    Vector3 operator-(Vector3 other)
    {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 operator*(float other)
    {
        return Vector3(x * other, y * other, z * other);
    }

    Vector3 operator/(float other)
    {
        return Vector3(x / other, y / other, z/ other);
    }

    Matrix operator*(Matrix other)
    {
        return this->ToMatrix() * other;
    }

    Matrix ToMatrix()
    {
        return Matrix({{x,y,z}});
    }

    float Magnitude()
    {
        return sqrt(x * x + y * y);
    }

    Vector3 Normalized()
    {
        float magnitude = Magnitude();
        return Vector3(x / magnitude, y / magnitude, z/ magnitude);
    }
};
