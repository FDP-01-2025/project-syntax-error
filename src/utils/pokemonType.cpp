#include "../include/PokemonType.h"
#include "../include/Menu.h"  // For setColor
#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;

// Returns the index (int) of the selected type, receives playerNum to display it
int SelectPokemonType(const PokemonType types[], int typesCount, int playerNum)
{
    int cursor = 0;
    char key;

    while (true)
    {
        system("cls");
        cout << "\nPlayer " << playerNum << " 🌀 \n";
        cout << "It's time to choose your Pokemon type!\n";
        cout << "Each type has its advantages. Choose the one you like best and get ready for battle!\n";

        for (int i = 0; i < typesCount; i++)
        {
            setColor(types[i].color);
            cout << (i == cursor ? " > " : "   ") << types[i].name << (i == cursor ? " <\n" : "\n");
            setColor(7);
        }

        key = _getch();

        switch (key)
        {
            case 72: // Up arrow
                cursor = (cursor - 1 + typesCount) % typesCount;
                break;
            case 80: // Down arrow
                cursor = (cursor + 1) % typesCount;
                break;
            case 13: // Enter
                return cursor;
        }
    }
}
