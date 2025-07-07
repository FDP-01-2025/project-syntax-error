#ifndef POKEMONTYPE_H
#define POKEMONTYPE_H

#include <string>

struct PokemonType
{
    std::string name;
    int color;
};

// Now returns a PokemonType, not an index
int SelectPokemonType(const PokemonType types[], int typesCount, int playerNum);

#endif
