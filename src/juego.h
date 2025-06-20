#ifndef JUEGO_H
#define JUEGO_H

#include "pokemon.h"
#include "pokemonMove.h"
#include "batalla.h"

void mostrarBienvenida();
void seleccionarPokemon(int jugador, Pokemon *pokemonSeleccionado);
void mostrarDetallesPokemon(const Pokemon *p1, const Pokemon *p2);
void jugarRonda(Pokemon *p1, Pokemon *p2, int *marcadorJ1, int *marcadorJ2);
void mostrarMarcador(int marcadorJ1, int marcadorJ2);
bool verificarFinDelJuego(int marcadorJ1, int marcadorJ2);
void mostrarGanadorFinal(int marcadorJ1, int marcadorJ2);
bool preguntarRepetir();

#endif