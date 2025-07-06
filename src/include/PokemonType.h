#ifndef POKEMONTYPE_H
#define POKEMONTYPE_H

#include <string>

struct PokemonType
{
    std::string name;
    int color;
};

// Ahora devuelve un PokemonType, no un índice
int SelectPokemonType(const PokemonType types[], int typesCount, int playerNum);

#endif
