#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Estructura para mostrar un Pokémon con sus stats
struct Pokemon
{
    string name;
    string type; // Por ej: "Fuego", "Agua", "Planta"
    int hp;
    int speed;
    int fastattack;
    int normalattack;
    int specialattack;
};

void showPokemonsNameByType(const vector<Pokemon> &listaPokemons, const string &tipoBuscado)
{
    cout << "Pokemons tipo " << tipoBuscado << " \n";

    for (const auto &pokemon : listaPokemons)
    {
        if (pokemon.type == tipoBuscado)
        {
            cout << "  > " << pokemon.name << "\n";
        }
    }

    cout << "\nElige y gana!\n";
}

#endif

// TODO: Funcion para mostrar stats y confirmar seleccion o retornar
