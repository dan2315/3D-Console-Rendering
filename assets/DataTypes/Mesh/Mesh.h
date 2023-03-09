#include <vector>
#include "../Vectors/Vector3.h"
#include "Triangle.h"

struct Mesh
{
    vector<Vector3> vertices;
    vector<Triangle> triangles;
    vector<int> simpleConnections;

public:
    static Mesh InitializeCube()
    {
        Mesh cube;
        cube.vertices = {
            Vector3(-0.5, -0.5, -0.5), Vector3(0.5, -0.5, -0.5), Vector3(-0.5, 0.5, -0.5), Vector3(0.5, 0.5, -0.5),
            Vector3(-0.5, -0.5, 0.5), Vector3(0.5, -0.5, 0.5), Vector3(-0.5, 0.5, 0.5), Vector3(0.5, 0.5, 0.5)};
        cube.simpleConnections = {0, 1, 0, 2, 0, 4, 7, 3, 7, 5, 7, 6, 2, 3, 2, 6, 5, 1, 5, 4, 1, 3, 4, 6};
        cube.triangles = {
            Triangle(0, 2, 1),
            Triangle(1, 2, 3),
            Triangle(1, 3, 5),
            Triangle(5, 3, 7),
            Triangle(5, 7, 4),
            Triangle(4, 7, 6),
            Triangle(4, 6, 0),
            Triangle(0, 6, 4),
            Triangle(1, 5, 4),
            Triangle(4, 0, 1),
            Triangle(2, 6, 7),
            Triangle(7, 3, 2),
        };

        return cube;
    }
};
