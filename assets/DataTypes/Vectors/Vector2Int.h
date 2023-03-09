struct Vector2Int
{
    int x, y;

    Vector2Int()
    {
        this->x = 0;
        this->y = 0;
    }

    Vector2Int(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Vector2Int operator+(Vector2Int &other)
    {
        return Vector2Int(x + other.x, y + other.y);
    }

    Vector2Int operator-(Vector2Int &other)
    {
        return Vector2Int(x - other.x, y - other.y);
    }
};
