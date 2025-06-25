#include "../include/PokemonType.h"
#include "../include/Menu.h" // Para setColor
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int seleccionarTipoPokemon(const vector<PokemonType>& tipos)
{
    int cursor = 0;
    char key;
    while (true)
    {
        system("cls");
        cout << "Jugador 1:" << endl;
        cout << "Selecciona el tipo de Pokemon que deseas:" << endl;

        for (int i = 0; i < tipos.size(); i++)
        {
            if (i == cursor)
            {
                setColor(tipos[i].color);
                cout << " > " << tipos[i].name << " <" << endl;
                setColor(7);
            }
            else
            {
                setColor(tipos[i].color);
                cout << "   " << tipos[i].name << endl;
                setColor(7);
            }
        }

        key = _getch();
        switch (key)
        {
        case 72: // Flecha arriba
            cursor--;
            if (cursor < 0)
                cursor = tipos.size() - 1;
            break;
        case 80: // Flecha abajo
            cursor++;
            if (cursor >= tipos.size())
                cursor = 0;
            break;
        case 13: // Enter
            return cursor;
        default:
            break;
        }
    }
}