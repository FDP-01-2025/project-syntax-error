#ifndef POKEMONTYPE_H
#define POKEMONTYPE_H

#include <string>

struct PokemonType
{
    std::string name;
    int color;
};

// Ahora devuelve un PokemonType, no un índice
int seleccionarTipoPokemon(const PokemonType tipos[], int tiposCount, int jugadorNum);

#endif
