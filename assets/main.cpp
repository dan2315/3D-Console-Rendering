#include <iostream>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "GameConsole.h"
#include "DataTypes/Matrices/Matrices.h"
#include "DataTypes/Mesh/Mesh.h"

int main()
{
    GameConsole console;
    Mesh cube = Mesh::InitializeCube();

    console.ClearScreen();

    // Matrix M1 = Matrix({{2, 0, 0},
    //                     {0, 2, 0},
    //                     {0, 0, 2}});

    // Vector3 V1 = Vector3(1,1,1);
    
    // Matrix M3 = V1 * M1;

    float rotation = 0;
    while (1)
    {
        Sleep(50);
        console.ClearScreen();
        for (int i = 0; i < cube.simpleConnections.size(); i += 2)
        {
            int firstIndex = cube.simpleConnections[i];
            int secondIndex = cube.simpleConnections[i + 1];
            Matrix rotationMatrixX = Matrices::RotationMatrixAboutX(rotation);
            Matrix rotationMatrixY = Matrices::RotationMatrixAboutY(rotation/2);
            Matrix rotationMatrixZ = Matrices::RotationMatrixAboutZ(rotation/4);
            Matrix rotatedVertex1 = cube.vertices[firstIndex] * rotationMatrixY * rotationMatrixZ * rotationMatrixX;
            // Matrix projectedVertex1 = rotatedVertex1 * Matrices::ProjectionMatrix();

            Matrix rotatedVertex2 = cube.vertices[secondIndex] * rotationMatrixY * rotationMatrixZ * rotationMatrixX;
            // Matrix projectedVertex2 = rotatedVertex1 * Matrices::ProjectionMatrix();

            console.DrawLine(rotatedVertex1, rotatedVertex2);
        }
        console.Draw();
        rotation += 0.05;
    }
}
