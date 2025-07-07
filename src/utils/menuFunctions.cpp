#include "../include/Menu.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setCursorPosition(int x, int y)
{
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void animatedPrint(const string &text, int ms)
{
    for (char c : text)
    {
        cout << c << flush;
        Sleep(ms);
    }
}

void showOptions(const string options[], int optionsSize, int cursor, int startY)
{
    for (int i = 0; i < optionsSize; i++)
    {
        setCursorPosition(0, startY + i);
        if (i == cursor)
        {
            setColor(112);
            cout << " > " << options[i] << " <  ";
            setColor(7);
        }
        else
        {
            cout << "   " << options[i] << "    ";
        }
    }
}

int selectGamemode()
{
    const int optionsSize = 2;
    string options[optionsSize] = {
        "2 Players Battle",
        "1 Player Battle"};

    system("cls");

    // Welcome animation (only ONCE)
    setColor(6);
    animatedPrint("(\\_/)\n", 50);
    animatedPrint("(•.•)\n", 50);
    animatedPrint("(>  ", 50);  
    animatedPrint("Welcome to the Pokemon Arena!  \n\n", 25);

    setColor(11);
    animatedPrint("Select your battle mode:\n", 20);
    setColor(7);
    cout << "Navigate using the arrow keys and confirm your option with [Enter].";

    int cursor = 0;
    const int optionsStartY = 7; // Vertical position where options start

    showOptions(options, optionsSize, cursor, optionsStartY);

    while (true)
    {
        int key = _getch();

        if (key == 0 || key == 224) // Special keys (arrows)
        {
            key = _getch();
            if (key == 72) // Up arrow
            {
                cursor--;
                if (cursor < 0)
                    cursor = optionsSize - 1;
            }
            else if (key == 80) // Down arrow
            {
                cursor++;
                if (cursor >= optionsSize)
                    cursor = 0;
            }
        }
        else if (key == 13) // Enter
        {
            setCursorPosition(0, optionsStartY + optionsSize + 1);
            setColor(10);
            cout << "Mode selected! Preparing your adventure...\n";
            setColor(7);
            return cursor + 1;
        }

        showOptions(options, optionsSize, cursor, optionsStartY);
    }
}
