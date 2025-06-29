#include "../include/PokemonType.h"
#include "../include/Menu.h" // Para setColor
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int seleccionarTipoPokemon(const PokemonType tipos[], int tiposCount)
{
    int cursor = 0;
    char key;

    while (true)
    {
        system("cls");
        cout << "🌀 ¡Es momento de elegir tu tipo de Pokémon!\n";
        cout << "Cada tipo tiene sus ventajas. ¡Elige el que más te guste y prepárate para la batalla!\n";

        for (int i = 0; i < tiposCount; i++)
        {
            setColor(tipos[i].color);
            cout << (i == cursor ? " > " : "   ") << tipos[i].name << (i == cursor ? " <\n" : "\n");
            setColor(7);
        }

        key = _getch();

        switch (key)
        {
            case 72: // Flecha arriba
                cursor = (cursor - 1 + tiposCount) % tiposCount;
                break;
            case 80: // Flecha abajo
                cursor = (cursor + 1) % tiposCount;
                break;
            case 13: // Enter
                return cursor;
        }
    }
}
