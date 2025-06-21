#ifndef JUEGO_H
#define JUEGO_H

#include <string>
#include <vector>
#include "pokemon.h"
#include "pokemonType.h"

// Muestra el mensaje inicial del juego (opcional si se usa)
void mostrarBienvenida();

// Muestra el menú de selección de tipo de Pokémon (esperado como showPokemonTypes)
void showPokemonTypes(const std::vector<PokemonType>& tipos, int cursor);

// Devuelve la lista de pokémon filtrados por tipo (esperado como getPokemonsOfType)
std::vector<Pokemon> getPokemonsOfType(const std::vector<Pokemon>& pokemons, const std::string& tipo);

// Muestra los Pokémon filtrados por tipo con el cursor resaltado (esperado como showPokemonsOfType)
void showPokemonsOfType(const std::vector<Pokemon>& pokemonsFiltrados, int cursor, int color);

// Muestra los stats del Pokémon elegido (opcional, puede estar en Pokemon::mostrarStats)
void mostrarStatsPokemon(const Pokemon& p);

// Confirma la selección del Pokémon con una interacción divertida (usada en main)
bool confirmarSeleccionDivertida(const std::string& nombrePokemon);

// Selección de modo de juego (usada en main)
int seleccionarModoJuego();

#endif
