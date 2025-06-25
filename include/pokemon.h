#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Pokemon
{
    string name;
    string type;
    int hp;
    int speed;
    int fastattack;
    int normalattack;
    int specialattack;

    void mostrarStats() const;
};

vector<Pokemon> getPokemonsOfType(const vector<Pokemon>& pokemonList, const string& type);
void showPokemonsOfType(const vector<Pokemon>& filteredPokemons, int cursor, int color);
void showPokemonsNameByType(const vector<Pokemon>& listaPokemons, const string& tipoBuscado);
bool confirmarSeleccionDivertida(const string& nombrePokemon);

#endif