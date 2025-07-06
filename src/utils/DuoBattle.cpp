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

        if (key == 72) // Arriba
            cursor = (cursor - 1 + filteredQuantity) % filteredQuantity;
        else if (key == 80) // Abajo
            cursor = (cursor + 1) % filteredQuantity;
        else if (key == 13) // Enter
            selectedName = filteredPokemon[cursor].name;
    }

    system("cls");
    cout << "Player " << playerNum << " seleccionó a ";
    setColor(color);
    cout << selectedName;
    setColor(7);
    cout << " de tipo " << type << "!\n";

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
        return Pokemon{"", "", 0, 0, 0, 0, 0}; // Selección cancelada
}

bool doubleMatch(Pokemon player1, Pokemon player2, int round)
{
    int hpPlayer1 = player1.hp;
    int hpPlayer2 = player2.hp;

    system("cls");
    cout << "╭─────────────────────────────────╮\n";
    cout << "│ Ronda " << round << " - ¡Comienza la batalla! │\n";
    cout << "╰─────────────────────────────────╯\n";

    system("pause");

    int turn = (player1.speed >= player2.speed) ? 1 : 2;

    while (hpPlayer1 > 0 && hpPlayer2 > 0)
    {
        if (turn == 1)
        {
            system("cls");
            cout << "Turno de Player 1 (" << player1.name << ")\n";
            int player1Attack = selectAttack(player1);
            int damage = (player1Attack == 1) ? player1.fastattack : (player1Attack == 2) ? player1.normalattack
                                                                                          : player1.specialattack;
            string attackName = (player1Attack == 1) ? "Ataque rápido" : (player1Attack == 2) ? "Ataque normal"
                                                                                              : "Ataque especial";

            cout << player1.name << " usa " << attackName << " y causa " << damage << " de daño.\n";
            hpPlayer2 -= damage;
            if (hpPlayer2 < 0)
                hpPlayer2 = 0;
            cout << player2.name << " tiene " << hpPlayer2 << " HP restantes.\n";
            system("pause");

            if (hpPlayer2 == 0)
                break;
            turn = 2;
        }
        else
        {
            system("cls");
            cout << "Turno de Player 2 (" << player2.name << ")\n";
            int player2Attack = selectAttack(player2);
            int damage = (player2Attack == 1) ? player2.fastattack : (player2Attack == 2) ? player2.normalattack
                                                                                          : player2.specialattack;
            string attackName = (player2Attack == 1) ? "Ataque rápido" : (player2Attack == 2) ? "Ataque normal"
                                                                                              : "Ataque especial";

            cout << player2.name << " usa " << attackName << " y causa " << damage << " de daño.\n";
            hpPlayer1 -= damage;
            if (hpPlayer1 < 0)
                hpPlayer1 = 0;
            cout << player1.name << " tiene " << hpPlayer1 << " HP restantes.\n";
            system("pause");

            if (hpPlayer1 == 0)
                break;
            turn = 1;
        }
    }

    system("cls");
    if (hpPlayer1 > hpPlayer2)
    {
        cout << "\n🎉 ¡Player 1 gana esta round con " << player1.name << "!\n";
        return true;
    }
    else
    {
        cout << "\n🎉 Player 2 gana esta round con " << player2.name << "!\n";
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
        cout << "\n🏁 Marcador actual: Player 1 = " << pointsPlayer1 << " | Player 2 = " << pointsPlayer2 << "\n";
        system("pause");
    }

    system("cls");
    cout << "╭─────────────────────────────────╮\n";
    cout << "│ ¡Resultado final de la batalla! │\n";
    cout << "╰─────────────────────────────────╯\n";

    if (pointsPlayer1 > pointsPlayer2)
    {
        cout << "🏆 ¡Player 1 gana la partida con " << pointsPlayer1 << " rounds ganadas!\n";
    }
    else if (pointsPlayer2 > pointsPlayer1)
    {
        cout << "🏆 ¡Player 2 gana la partida con " << pointsPlayer2 << " rounds ganadas!\n";
    }
    else
    {
        cout << "🤝 ¡Empate! Ambos jugadores ganaron " << pointsPlayer1 << " rounds.\n";
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
        cout << "Player 2 canceló la selección. Regresando al menú...\n";
        system("pause");
    }
}
