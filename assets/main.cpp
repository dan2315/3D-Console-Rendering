#include <iostream>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <Camera.h>
#include <GameConsole.h>
#include <Mesh.h>
#include <Matrices.h>

int main()
{
    GameConsole console;
    Camera camera = Camera(90, console.AspecRatio(), 1, 50);

    Vector2 projectedPoint = camera.GetPointProjection(Vector3(-10, 10, 20));

    Mesh cube = Mesh::InitializeCube();

    float rotation = 0;
    while (1)
    {
        console.ClearScreen();
        for (int i = 0; i < cube.simpleConnections.size(); i += 2)
        {
            int firstIndex = cube.simpleConnections[i];
            int secondIndex = cube.simpleConnections[i + 1];

            Matrix* rotationMatrixX = Matrices::RotationMatrixAboutX(rotation);
            Matrix* rotationMatrixY = Matrices::RotationMatrixAboutY(rotation / 2);
            Matrix* rotationMatrixZ = Matrices::RotationMatrixAboutZ(rotation / 4);

            // Vector3 projectedVertex1 = camera.GetPointProjection(cube.vertices[firstIndex]);
            // Vector3 projectedVertex2 = camera.GetPointProjection(cube.vertices[secondIndex]);
            // Matrix rotatedVertex1 = projectedVertex1 * rotationMatrixY * rotationMatrixZ * rotationMatrixX;
            // Matrix rotatedVertex2 = projectedVertex2 * rotationMatrixY * rotationMatrixZ * rotationMatrixX;

            Matrix rotatedVertex1 = cube.vertices[firstIndex] * *rotationMatrixY * *rotationMatrixZ * *rotationMatrixX;
            Matrix rotatedVertex2 = cube.vertices[secondIndex] * *rotationMatrixY * *rotationMatrixZ * *rotationMatrixX;
            Vector3 projectedVertex1 = camera.GetPointProjection(rotatedVertex1);
            Vector3 projectedVertex2 = camera.GetPointProjection(rotatedVertex2);

            console.DrawLine(projectedVertex1, projectedVertex2);
            delete rotationMatrixX;
            delete rotationMatrixY;
            delete rotationMatrixZ;
        }
        console.Draw();
        rotation += 0.001;
    }
}
