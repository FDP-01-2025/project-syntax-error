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

// Cambiamos a arreglo estático con tamaño fijo
void showOptions(const string options[], int optionsSize, int cursor, int startY)
{
    for (int i = 0; i < optionsSize; i++)
    {
        setCursorPosition(0, startY + i);
        if (i == cursor)
        {
            setColor(112); // Fondo azul claro, texto blanco
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
        "Modo Dúo",
        "Modo Solitario"};

    system("cls");

    // Animación bienvenida (solo UNA VEZ)
    setColor(6);
    animatedPrint("¡Bienvenido a la Arena Pokémon!  \n\n", 25);

    setColor(11);
    animatedPrint("Selecciona tu modo de batalla:\n", 20);
    setColor(7);
    cout << "Navega usando las flechas del teclado y confirma tu opción con [Enter].";

    int cursor = 0;
    const int optionsStartY = 5; // Posición vertical donde comienzan las opciones

    showOptions(options, optionsSize, cursor, optionsStartY);

    while (true)
    {
        int key = _getch();

        if (key == 0 || key == 224) // Teclas especiales (flechas)
        {
            key = _getch();
            if (key == 72) // Flecha arriba
            {
                cursor--;
                if (cursor < 0)
                    cursor = optionsSize - 1;
            }
            else if (key == 80) // Flecha abajo
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
            cout << "¡Modo seleccionado! Preparando tu aventura...\n";
            setColor(7);
            return cursor + 1;
        }

        showOptions(options, optionsSize, cursor, optionsStartY);
    }
}
