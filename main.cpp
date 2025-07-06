#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

#include "./src/include/Menu.h"
#include "./src/include/Pokemon.h"
#include "./src/include/PokemonType.h"
#include "./src/include/SolitaryBattle.h" 
#include "./src/include/DuoBattle.h"

using namespace std;

// List of Pokemon types
PokemonType pokemonTypes[] = {
    {"Water", 3},
    {"Fire", 12},
    {"Dirt", 5},
    {"Plant", 2},
    {"Electric", 6},
    {"Normal", 7},
};

const int typesCount = sizeof(pokemonTypes) / sizeof(pokemonTypes[0]);

// List of Pokemon
Pokemon pokemonList[] = {
    {"Charmander", "Fire", 90, 65, 15, 30, 45},
    {"Growlithe", "Fire", 96, 60, 14, 28, 42},
    {"Scorbunny", "Fire", 94, 69, 17, 35, 52},
    {"Flareon", "Fire", 101, 65, 12, 25, 38},
    {"Squirtle", "Water", 91, 43, 10, 18, 30},
    {"Blastoise", "Water", 104, 78, 15, 30, 45},
    {"Gyarados", "Water", 107, 81, 20, 40, 60},
    {"Psyduck", "Water", 94, 55, 11, 22, 33},
    {"Bulbasaur", "Plant", 92, 45, 10, 20, 30},
    {"Oddish", "Plant", 92, 30, 8, 15, 22},
    {"Leafeon", "Plant", 101, 65, 14, 28, 42},
    {"Grookey", "Plant", 94, 65, 14, 28, 42},
    {"Pikachu", "Electric", 89, 90, 18, 35, 50},
    {"Jolteon", "Electric", 101, 100, 20, 40, 60},
    {"Gengar", "Electric", 99, 95, 19, 38, 57},
    {"Haunter", "Electric", 92, 78, 15, 30, 45},
    {"Eevee", "Normal", 96, 55, 11, 22, 33},
    {"Snorlax", "Normal", 120, 30, 12, 25, 38},
    {"Pidgey", "Normal", 90, 56, 10, 20, 30},
    {"Meowth", "Normal", 90, 90, 18, 35, 50},
    {"Sandshrew", "Dirt", 94, 40, 10, 20, 30},
    {"Diglett", "Dirt", 80, 95, 19, 38, 57},
    {"Cubone", "Dirt", 94, 35, 10, 20, 30},
    {"Onix", "Dirt", 89, 70, 13, 25, 38}
};

bool isGameOver = false;

const int pokemonsCount = sizeof(pokemonList) / sizeof(pokemonList[0]);

int main(){
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // Para permitir tildes y emojis en Windows
#endif

    int gamemode = selectGamemode();
    system("pause");

    string selectedTypeName;
    string selectedPokemon;

    const int maxFiltered = 50;
    Pokemon filteredPokemon[maxFiltered];

    while (!isGameOver){
        selectedTypeName = "";
        selectedPokemon = "";

        // Type selection
        int selectedType = SelectPokemonType(pokemonTypes, typesCount, 1);
        selectedTypeName = pokemonTypes[selectedType].name;
        int selectedTypeColor = pokemonTypes[selectedType].color;

        // Filter pokemon by type

        int filteredQuantity = getPokemonsOfType(pokemonList, pokemonsCount, selectedTypeName, filteredPokemon, maxFiltered);

        // Selection of pokemon
        int pokemonCursor = 0;
        while (selectedPokemon == "")
        {
            showPokemonsOfType(filteredPokemon, filteredQuantity, pokemonCursor, selectedTypeColor);
            char key = _getch();
            switch (key)
            {
                case 72: // Up
                    pokemonCursor = (pokemonCursor - 1 + filteredQuantity) % filteredQuantity;
                    break;
                case 80: // Down
                    pokemonCursor = (pokemonCursor + 1) % filteredQuantity;
                    break;
                case 13: // Enter
                    selectedPokemon = filteredPokemon[pokemonCursor].name;
                    break;
            }
        }

        system("cls");
        cout << "You have selected ";
        setColor(selectedTypeColor);
        cout << selectedPokemon;
        setColor(7);
        cout << " of type " << selectedTypeName << "!" << endl;

        // Show stats of selected
        Pokemon chosen;
        for (int i = 0; i < filteredQuantity; i++)
        {
            if (filteredPokemon[i].name == selectedPokemon)
            {
                chosen = filteredPokemon[i];
                break;
            }
        }

        chosen.ShowStats();

        if (confirmPokemonCatch(chosen.name))
        {
            system("pause");

            if (gamemode == 2) // Only start solitary mode if gamemode selected is 2 (Solitary)
            {
                start1PMode(pokemonList, pokemonsCount, chosen);
                isGameOver = true;
            }
            else if (gamemode == 1)
            {
                start2PModeFlow(pokemonList, pokemonsCount, pokemonTypes, typesCount, chosen);
                isGameOver = true;
            }
        }
        else
        {
            cout << "\nGoing back to the menu to select another Pokemon...\n";
            system("pause");
        }
    }

    // To compile g++ main.cpp src/utils/*.cpp -Iinclude -o juego.exe
    // To run ./juego.exe


    return 0;
}
