#ifndef POKEMONTYPE_H
#define POKEMONTYPE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct PokemonType
{
    string name;
    int color;
};

int seleccionarTipoPokemon(const vector<PokemonType>& tipos);

#endif