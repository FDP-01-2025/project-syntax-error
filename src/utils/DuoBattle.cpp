#include "../include/DuoBattle.h"
#include "../include/Menu.h"
#include "../include/PokemonType.h"
#include "../include/SolitaryBattle.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

Pokemon selectPokemonPlayer(
    const Pokemon pokemonList[], int pokemonsCount,
    const PokemonType types[], int typesCount,
    int playerNum)
{
    const int maxFiltered = 50;
    Pokemon filteredPokemon[maxFiltered];

    system("cls");
    int selectedType = SelectPokemonType(types, typesCount, playerNum);
    PokemonType chosenType = types[selectedType];

    string type = chosenType.name;
    int color = chosenType.color;

    int filteredQuantity = getPokemonsOfType(pokemonList, pokemonsCount, type, filteredPokemon, maxFiltered);

    int cursor = 0;
    string selectedName = "";

    while (selectedName == "")
    {
        showPokemonsOfType(filteredPokemon, filteredQuantity, cursor, color);
        char key = _getch();

        if (key == 72) // Up
            cursor = (cursor - 1 + filteredQuantity) % filteredQuantity;
        else if (key == 80) // Down
            cursor = (cursor + 1) % filteredQuantity;
        else if (key == 13) // Enter
            selectedName = filteredPokemon[cursor].name;
    }

    system("cls");
    cout << "Player " << playerNum << " chooses ";
    setColor(color);
    cout << selectedName;
    setColor(7);
    cout << " of type " << type << "!\n";

    Pokemon chosen;
    for (int i = 0; i < filteredQuantity; i++)
    {
        if (filteredPokemon[i].name == selectedName)
        {
            chosen = filteredPokemon[i];
            break;
        }
    }

    chosen.ShowStats();

    if (confirmPokemonCatch(chosen.name))
        return chosen;
    else
        return Pokemon{"", "", 0, 0, 0, 0, 0}; // Selection cancelled
}

bool doubleMatch(Pokemon player1, Pokemon player2, int round)
{
    int hpPlayer1 = player1.hp;
    int hpPlayer2 = player2.hp;

    system("cls");
    cout << "╭─────────────────────────────────╮\n";
    cout << "│ Round: " << round << " - Battle begins! │\n";
    cout << "╰─────────────────────────────────╯\n";

    system("pause");

    int turn = (player1.speed >= player2.speed) ? 1 : 2;

    while (hpPlayer1 > 0 && hpPlayer2 > 0)
    {
        if (turn == 1)
        {
            system("cls");
            cout << "Turn of Player 1 (" << player1.name << ")\n";
            int player1Attack = selectAttack(player1);
            int damage = (player1Attack == 1) ? player1.fastattack : (player1Attack == 2) ? player1.normalattack
                                                                                          : player1.specialattack;
            string attackName = (player1Attack == 1) ? "Fast attack" : (player1Attack == 2) ? "Normal attack"
                                                                                              : "Special attack";

            cout << player1.name << " uses " << attackName << " and causes" << damage << " damage.\n";  
            hpPlayer2 -= damage;
            if (hpPlayer2 < 0)
                hpPlayer2 = 0;
            cout << player2.name << " has " << hpPlayer2 << " HP left.\n"; 
            system("pause");

            if (hpPlayer2 == 0)
                break;
            turn = 2;
        }
        else
        {
            system("cls");
            cout << "Turn of Player 2 (" << player2.name << ")\n";
            int player2Attack = selectAttack(player2);
            int damage = (player2Attack == 1) ? player2.fastattack : (player2Attack == 2) ? player2.normalattack
                                                                                          : player2.specialattack;
            string attackName = (player2Attack == 1) ? "Fast attack" : (player2Attack == 2) ? "Normal attack"
                                                                                              : "Special attack";

            cout << player2.name << " uses " << attackName << " and causes " << damage << " damage.\n";
            hpPlayer1 -= damage;
            if (hpPlayer1 < 0)
                hpPlayer1 = 0;
            cout << player1.name << " has " << hpPlayer1 << " HP left.\n";
            system("pause");

            if (hpPlayer1 == 0)
                break;
            turn = 1;
        }
    }

    system("cls");
    if (hpPlayer1 > hpPlayer2)
    {
        cout << "\n🎉 The winner is Player 1 with " << player1.name << "!\n";
        return true;
    }
    else
    {
        cout << "\n🎉 The winner is Player 2 with " << player2.name << "!\n";
        return false;
    }
}

void start2PMode(const Pokemon &player1, const Pokemon &player2)
{
    int pointsPlayer1 = 0;
    int pointsPlayer2 = 0;

    for (int round = 1; round <= 3; round++)
    {
        bool winPlayer1 = doubleMatch(player1, player2, round);
        if (winPlayer1)
        {
            pointsPlayer1++;
        }
        else
        {
            pointsPlayer2++;
        }
        cout << "\n🏁 Current score: Player 1 = " << pointsPlayer1 << " | Player 2 = " << pointsPlayer2 << "\n";
        system("pause");
    }

    system("cls");
    cout << "╭─────────────────────────────────╮\n";
    cout << "│   Final result of the battle!   │\n";
    cout << "╰─────────────────────────────────╯\n";

    if (pointsPlayer1 > pointsPlayer2)
    {
        cout << "🏆 Player 1 wins the game with " << pointsPlayer1 << " rounds!\n";
    }
    else if (pointsPlayer2 > pointsPlayer1)
    {
        cout << "🏆 Player 2 wins the game with " << pointsPlayer2 << " rounds!\n";
    }
    else
    {
        cout << "🤝 It's a draw! Both players won " << pointsPlayer1 << " rounds.\n";
    }
    system("pause");
}

void start2PModeFlow(
    const Pokemon pokemonList[], int pokemonsCount,
    const PokemonType types[], int typesCount,
    const Pokemon &player1)
{
    Pokemon player2 = selectPokemonPlayer(pokemonList, pokemonsCount, types, typesCount, 2);

    if (player2.name != "")
    {
        system("pause");
        start2PMode(player1, player2);
    }
    else
    {
        cout << "Player 2 canceled the selection. Returning to the menu...\n";
        system("pause");
    }
}
