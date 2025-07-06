#include "../include/PokemonType.h"
#include "../include/Menu.h"  // Para setColor
#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;

// Devuelve el índice del tipo seleccionado (int), recibe playerNum para mostrarlo
int SelectPokemonType(const PokemonType types[], int typesCount, int playerNum)
{
    int cursor = 0;
    char key;

    while (true)
    {
        system("cls");
        cout << "\nPlayer " << playerNum << " 🌀 \n" ;
        cout << "¡Es momento de elegir tu tipo de Pokémon!\n";
        cout << "Cada tipo tiene sus ventajas. ¡Elige el que más te guste y prepárate para la batalla!\n";

        for (int i = 0; i < typesCount; i++)
        {
            setColor(types[i].color);
            cout << (i == cursor ? " > " : "   ") << types[i].name << (i == cursor ? " <\n" : "\n");
            setColor(7);
        }

        key = _getch();

        switch (key)
        {
            case 72: // Flecha arriba
                cursor = (cursor - 1 + typesCount) % typesCount;
                break;
            case 80: // Flecha abajo
                cursor = (cursor + 1) % typesCount;
                break;
            case 13: // Enter
                return cursor;
        }
    }
}
