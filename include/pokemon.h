#ifndef POKEMON_H
#define POKEMON_H

#include <string>
using namespace std;

struct Pokemon {
    string name;
    string type;
    int hp;
    int speed;
    int fastattack;
    int normalattack;
    int specialattack;

    void mostrarStats() const;
};

// Declaraciones de funciones
int getPokemonsOfType(const Pokemon lista[], int listaSize, const string& tipo, Pokemon filtrados[], int maxFiltrados);
void showPokemonsOfType(const Pokemon filtered[], int count, int cursor, int color);
void showPokemonsNameByType(const Pokemon lista[], int listaSize, const string& tipo);
bool confirmarSeleccionDivertida(const string& nombrePokemon);

#endif
