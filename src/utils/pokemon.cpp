#include "../include/pokemon.h"
#include "../include/Menu.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void Pokemon::ShowStats() const {
    cout << "\n+---------------------------------+\n";

    string title = " Stats of " + name + " ";
    int totalLength = 31;
    int spaces = totalLength - title.length();
    int left = spaces / 2;
    int right = spaces - left;

    cout << "|" << string(left, ' ') << title << string(right, ' ') << "   |\n";
    cout << "+---------------------------------+\n";

    cout << "| Type:             " << type << string(14 - type.length(), ' ') << "|\n";
    cout << "| HP:               " << hp << string(14 - to_string(hp).length(), ' ') << "|\n";
    cout << "| Speed:            " << speed << string(14 - to_string(speed).length(), ' ') << "|\n";
    cout << "| Fast Attack:      " << fastattack << string(14 - to_string(fastattack).length(), ' ') << "|\n";
    cout << "| Normal Attack:    " << normalattack << string(14 - to_string(normalattack).length(), ' ') << "|\n";
    cout << "| Special Attack:   " << specialattack << string(14 - to_string(specialattack).length(), ' ') << "|\n";
    cout << "+---------------------------------+\n\n";
}

// Filters Pokemon by type, fills the filtered array, and returns the count
int getPokemonsOfType(const Pokemon pokemonList[], int listSize, const string& type, Pokemon filtered[], int maxFiltered) {
    int count = 0;
    for (int i = 0; i < listSize && count < maxFiltered; i++) {
        if (pokemonList[i].type == type) {
            filtered[count++] = pokemonList[i];
        }
    }
    return count;
}

// Menu to display filtered Pokemon by type
void showPokemonsOfType(const Pokemon filteredPokemons[], int filteredCount, int cursor, int color) {
    system("cls");
    if (filteredCount == 0) return;

    cout << "Choose a " << filteredPokemons[0].type << "-type Pokemon!\n" << endl;
    // setColor(color);

    for (int i = 0; i < filteredCount; i++) {
        if (i == cursor) {
            setColor(color);
            cout << " > " << filteredPokemons[i].name << " <" << endl;
            setColor(7);
        } else {
            cout << "   " << filteredPokemons[i].name << endl;
        }
    }
}

void showPokemonsNameByType(const Pokemon pokemonList[], int listSize, const string& searchedType) {
    cout << "Pokemon of type " << searchedType << ":\n";
    for (int i = 0; i < listSize; i++) {
        if (pokemonList[i].type == searchedType) {
            cout << "  > " << pokemonList[i].name << "\n";
        }
    }
}

bool confirmPokemonCatch(const string& pokemonName) {
    char answer;
    cout << "Trainer! Are you sure you want to catch " << pokemonName << "? 🌟 \n\n";
    cout << "Press 'y' to throw a Pokéball or 'n' to think a little more:\n";
    cin >> answer;

    answer = tolower(answer);

    if (answer == 'y') {
        cout << "Great! 🎉  " << pokemonName << " is now part of your team. Let’s go battle!\n\n";
        return true;
    } else {
        cout << "\n🤔 . . . That’s okay, think carefully about your strategy. The perfect team awaits!\n";
        return false;
    }
}
