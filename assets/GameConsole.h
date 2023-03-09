#include <iostream>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "DataTypes/Vectors/Vector2.h"
#include "DataTypes/Matrices/Matrix.h"

class GameConsole
{
private:
    int width = 240;
    int height = 60;
    float aspect = (float)width / height;
    float pixelAspect = 11.0f / 24.0f;
    char gradient[18] = " .:!/r(l1Z4H9W8$@";
    int gradientSize = std::size(gradient) - 2;
    int ASS_Counter = 0;

    wchar_t *screen;
    HANDLE hConsole;
    DWORD dwBytesWritten;

    void SetWindow(int Width, int Height)
    {
        COORD coord;
        coord.X = Width;
        coord.Y = Height;
        _SMALL_RECT Rect;
        Rect.Top = 0;
        Rect.Left = 0;
        Rect.Bottom = Height - 1;
        Rect.Right = Width - 1;
        HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

        WINBOOL SetBufferResult;
        WINBOOL SetInfoResult;

        SetBufferResult = SetConsoleScreenBufferSize(Handle, coord);
        DWORD error = GetLastError();
        SetInfoResult = SetConsoleWindowInfo(Handle, TRUE, &Rect);
    }

public:
    GameConsole()
    {
        SetWindow(width, height);
        screen = new wchar_t[width * height];
        hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        SetConsoleActiveScreenBuffer(hConsole);
        dwBytesWritten = 0;
    }

    void ClearScreen()
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                screen[y * width + x] = ' ';
            }
        }

        screen[width * height - 1] = '\0';
        WriteConsoleOutputCharacterW(hConsole, screen, width * height, {0, 0}, &dwBytesWritten);
    }

    void DrawLine(Vector2 start, Vector2 end)
    {
        start = Vector2((start.x + 1) * width / 2, (start.y + 1) * height / 2);
        end = Vector2((end.x + 1) * width / 2, (end.y + 1) * height / 2);
        Vector2 direction = end - start;

        if (abs(direction.y / direction.x) <= 1) // case when we can draw line along XXXXX axis
        {
            if (start.x > end.x)
            {
                Vector2 temp = start;
                start = end;
                end = temp;
            }

            for (int x = start.x; x < end.x; x++)
            {
                float k = direction.y / direction.x;
                float l = start.y - start.x * k;
                int y = k * x + l;
                if (ASS_Counter <= 0)
                {
                    screen[y * width + x] = 'A';
                    ASS_Counter = 1;
                }
                else if (ASS_Counter == 1)
                {
                    screen[y * width + x] = 'S';
                    ASS_Counter = 2;
                }
                else if (ASS_Counter >= 2)
                {
                    screen[y * width + x] = 'S';
                    ASS_Counter = 0;
                }
            }
        }
        else // case when we can draw line along YYYYY axis
        {
            if (start.y > end.y)
            {
                Vector2 temp = start;
                start = end;
                end = temp;
            }

            for (int y = start.y; y < end.y; y++)
            {
                float k = direction.x / direction.y;
                float l = start.x - start.y * k;
                int x = k * y + l;
                if (ASS_Counter <= 0)
                {
                    screen[y * width + x] = 'A';
                    ASS_Counter = 1;
                }
                else if (ASS_Counter == 1)
                {
                    screen[y * width + x] = 'S';
                    ASS_Counter = 2;
                }
                else if (ASS_Counter >= 2)
                {
                    screen[y * width + x] = 'S';
                    ASS_Counter = 0;
                }
            }
        }
    }

    void DrawLine(Matrix start, Matrix end)
    {
        DrawLine(Vector2(start.matrix[0][0], start.matrix[0][1]),
                 Vector2(end.matrix[0][0], end.matrix[0][1]));
    }

    void DrawCube(int squareSize)
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (squareSize > abs(width / 2 - x) && squareSize * pixelAspect > abs(height / 2 - y))
                {
                    screen[y * width + x] = 'H';
                }
                else
                {
                    screen[y * width + x] = ' ';
                }
            }
        }

        screen[width * height - 1] = '\0';
        WriteConsoleOutputCharacterW(hConsole, screen, width * height, {0, 0}, &dwBytesWritten);
    }

    void Draw()
    {
        screen[width * height - 1] = '\0';
        WriteConsoleOutputCharacterW(hConsole, screen, width * height, {0, 0}, &dwBytesWritten);
    }
};
