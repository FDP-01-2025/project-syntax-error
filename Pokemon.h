#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Estructura para mostrar un Pokémon con sus stats 
struct Pokemon {
    string nombrePokemon;  
    string tipoPokemon;    // Por ej: "Fuego", "Agua", "Planta"
    int puntosVida;        
    int velocidad;         
    int ataqueRapido;      
    int ataqueNormal;      
    int ataqueEspecial;   
};

/*
Función mostrarNombresDePokemonsPorTipo:

-Sirve para mostrar SOLO los nombres de todos los Pokémon de un tipo específico.
- Parámetros:
    - listaPokemons: vector con todos los Pokémons
    - tipoBuscado: string con el tipo que quieres mostrar, por ejemplo "Fuego".

- Ejemplo de uso en main:

    vector<Pokemon> lista = {
        {"Charmander", "Fuego", 39, 65, 22, 17, 30},
        {"Squirtle", "Agua", 44, 43, 20, 15, 25},
        {"Bulbasaur", "Planta", 45, 45, 18, 14, 27}
    };

    mostrarNombresDePokemonsPorTipo(lista, "Fuego");

- Salida esperada si seleccionan fuego:

    Pokémons tipo Fuego 
    ──────────────────────
     > Charmander

    ¡Elige y gana!
*/
void mostrarNombresDePokemonsPorTipo(const vector<Pokemon>& listaPokemons, const string& tipoBuscado) {
    cout << "Pokémons tipo " << tipoBuscado << " \n";
    cout << "──────────────────────\n";

    for (const auto& pokemon : listaPokemons) {
        if (pokemon.tipoPokemon == tipoBuscado) {
            cout << "  > " << pokemon.nombrePokemon << "\n";
        }
    }

    cout << "\n¡Elige y gana!\n";
}

#endif 

//TODO: Funcion para mostrar stats y confirmar seleccion o retornar 
