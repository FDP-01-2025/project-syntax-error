#include "../include/Menu.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
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

void imprimirOpciones(const vector<string> &opciones, int cursor, int startY)
{
    for (size_t i = 0; i < opciones.size(); i++)
    {
        setCursorPosition(0, startY + (int)i);
        if ((int)i == cursor)
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
    vector<string> opciones = {
        "Modo Solitario",
        "Modo Duo"};

    system("cls");

    // Animación bienvenida (solo UNA VEZ)
    setColor(6);
    imprimirAnimado("Bienvenido a la Arena Pokemon!  \n\n", 25);

    setColor(11);
    imprimirAnimado("Selecciona tu modo de batalla:\n", 20);
    setColor(7);
    cout << "Usa las flechas de tu teclado para moverte y presiona [Enter] para seleccionar.";

    int cursor = 0;
    const int opcionesStartY = 6; // Posición vertical donde comienzan las opciones

    imprimirOpciones(opciones, cursor, opcionesStartY);

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
                    cursor = (int)opciones.size() - 1;
            }
            else if (tecla == 80) // Flecha abajo
            {
                cursor++;
                if (cursor >= (int)opciones.size())
                    cursor = 0;
            }
        }
        else if (tecla == 13) // Enter
        {
            setCursorPosition(0, opcionesStartY + (int)opciones.size() + 2);
            setColor(10);
            cout << "\n\nModo seleccionado! Preparando tu aventura...\n";
            setColor(7);
            return cursor + 1;
        }

        imprimirOpciones(opciones, cursor, opcionesStartY);
    }
}