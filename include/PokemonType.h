#ifndef POKEMONTYPE_H
#define POKEMONTYPE_H

#include <string>

struct PokemonType
{
    std::string name;
    int color;
};

int seleccionarTipoPokemon(const PokemonType tipos[], int tiposCount);

#endif
