#ifndef DUOBATTLE_H
#define DUOBATTLE_H

#include "PokemonType.h"
#include "Pokemon.h"

Pokemon selectPokemonPlayer(
    const Pokemon pokemonList[], int pokemonsCount,
    const PokemonType types[], int typesCount,
    int playerNum);

void start2PMode(const Pokemon &player1, const Pokemon &player2);

void start2PModeFlow(
    const Pokemon pokemonList[], int pokemonsCount,
    const PokemonType types[], int typesCount,
    const Pokemon &player1);

#endif // DUOBATTLE_H
