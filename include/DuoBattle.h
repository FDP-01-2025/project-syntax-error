#ifndef DUOBATTLE_H
#define DUOBATTLE_H

#include "PokemonType.h"
#include "Pokemon.h"

Pokemon seleccionarPokemonJugador(const Pokemon listaPokemons[], int pokemonsCount,
                                  const PokemonType tipos[], int tiposCount,
                                  int jugadorNum);

void iniciarModoDuo(const Pokemon& jugador1, const Pokemon& jugador2);

void iniciarModoDuoFlujo(const Pokemon listaPokemons[], int pokemonsCount,
                         const PokemonType tipos[], int tiposCount,
                         const Pokemon& jugador1);

#endif
