#include <iostream>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "DataTypes/Vector2Int.h"

class GameConsole
{
private:
    int width = 240;
    int height = 60;
    float aspect = (float)width / height;
    float pixelAspect = 11.0f / 24.0f;
    char gradient[18] = " .:!/r(l1Z4H9W8$@";
    int gradientSize = std::size(gradient) - 2;


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

    void DrawLine(Vector2Int start, Vector2Int end){
        
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

};
