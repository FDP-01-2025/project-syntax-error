#ifndef POKEMON_H
#define POKEMON_H

#include <string>
using namespace std;

struct Pokemon {
    string name;
    string type;
    int hp;
    int speed;
    int fastattack;
    int normalattack;
    int specialattack;

    void ShowStats() const;
};

// Functions declarations
int getPokemonsOfType(const Pokemon list[], int listSize, const string& type, Pokemon filtered[], int maxFiltered);
void showPokemonsOfType(const Pokemon filtered[], int count, int cursor, int color);
void showPokemonsNameByType(const Pokemon list[], int listSize, const string& type);
bool confirmPokemonCatch(const string& nombrePokemon);

#endif
