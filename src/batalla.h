#ifndef BATALLA_H
#define BATALLA_H

#include <vector>
#include <string>
#include "pokemon.h"
#include "pokemonType.h"

// Filtra los Pokémon por tipo
std::vector<Pokemon> getPokemonsOfType(const std::vector<Pokemon>& lista, const std::string& tipo);

// Muestra los tipos de Pokémon con color y cursor
void showPokemonTypes(const std::vector<PokemonType>& tipos, int cursor);

// Muestra los Pokémon filtrados por tipo con color y cursor
void showPokemonsOfType(const std::vector<Pokemon>& listaFiltrada, int cursor, int color);

// Confirmación divertida del Pokémon seleccionado
bool confirmarSeleccionDivertida(const std::string& nombrePokemon);

// Función para elegir el modo de juego
int seleccionarModoJuego();

#endif

