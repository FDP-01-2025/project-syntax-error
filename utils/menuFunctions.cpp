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

void imprimirAnimado(const string &texto, int ms)
{
    for (char c : texto)
    {
        cout << c << flush;
        Sleep(ms);
    }
}

// Cambiamos a arreglo estático con tamaño fijo
void imprimirOpciones(const string opciones[], int opcionesSize, int cursor, int startY)
{
    for (int i = 0; i < opcionesSize; i++)
    {
        setCursorPosition(0, startY + i);
        if (i == cursor)
        {
            setColor(112); // Fondo azul claro, texto blanco
            cout << " > " << opciones[i] << " <  ";
            setColor(7);
        }
        else
        {
            cout << "   " << opciones[i] << "    ";
        }
    }
}

int seleccionarModoJuego()
{
    const int opcionesSize = 2;
    string opciones[opcionesSize] = {
        "Modo Dúo",
        "Modo Solitario"};

    system("cls");

    // Animación bienvenida (solo UNA VEZ)
    setColor(6);
    imprimirAnimado("¡Bienvenido a la Arena Pokémon!  \n\n", 25);

    setColor(11);
    imprimirAnimado("Selecciona tu modo de batalla:\n", 20);
    setColor(7);
    cout << "Navega usando las flechas del teclado y confirma tu opción con [Enter].";

    int cursor = 0;
    const int opcionesStartY = 5; // Posición vertical donde comienzan las opciones

    imprimirOpciones(opciones, opcionesSize, cursor, opcionesStartY);

    while (true)
    {
        int tecla = _getch();

        if (tecla == 0 || tecla == 224) // Teclas especiales (flechas)
        {
            tecla = _getch();
            if (tecla == 72) // Flecha arriba
            {
                cursor--;
                if (cursor < 0)
                    cursor = opcionesSize - 1;
            }
            else if (tecla == 80) // Flecha abajo
            {
                cursor++;
                if (cursor >= opcionesSize)
                    cursor = 0;
            }
        }
        else if (tecla == 13) // Enter
        {
            setCursorPosition(0, opcionesStartY + opcionesSize + 1);
            setColor(10);
            cout << "¡Modo seleccionado! Preparando tu aventura...\n";
            setColor(7);
            return cursor + 1;
        }

        imprimirOpciones(opciones, opcionesSize, cursor, opcionesStartY);
    }
}
