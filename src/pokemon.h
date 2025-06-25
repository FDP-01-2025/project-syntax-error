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

    void mostrarStats() const
    {
        cout << "\n+---------------------------------+\n";

        // Línea del nombre del Pokémon, alineada
        string titulo = " Estadisticas de " + name + " ";
        int largoTotal = 31;
        int espacios = largoTotal - titulo.length();
        int izquierda = espacios / 2;
        int derecha = espacios - izquierda;

        cout << "|" << string(izquierda, ' ') << titulo << string(derecha, ' ') << "  |\n";
        cout << "+---------------------------------+\n";

        // Campos alineados
        cout << "| Tipo:             " << type << string(14 - type.length(), ' ') << "|\n";
        cout << "| HP:               " << hp << string(14 - to_string(hp).length(), ' ') << "|\n";
        cout << "| Velocidad:        " << speed << string(14 - to_string(speed).length(), ' ') << "|\n";
        cout << "| Ataque rapido:    " << fastattack << string(14 - to_string(fastattack).length(), ' ') << "|\n";
        cout << "| Ataque normal:    " << normalattack << string(14 - to_string(normalattack).length(), ' ') << "|\n";
        cout << "| Ataque especial:  " << specialattack << string(14 - to_string(specialattack).length(), ' ') << "|\n";

        cout << "+---------------------------------+\n";
    }
};

// Función para mostrar nombres de Pokémon por tipo
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

// Función divertida para confirmar la selección de un Pokémon
bool confirmarSeleccionDivertida(const string& nombrePokemon)
{
    char respuesta;
    cout << "Entrenador! Seguro que quieres atrapar a " << nombrePokemon << "? \n";
    cout << "Presiona 's' para lanzarle la Pokeball o 'n' para pensar un poco mas: ";
    cin >> respuesta;

    respuesta = tolower(respuesta);

    if (respuesta == 's')
    {
        cout << "Genial! " << nombrePokemon << " es ahora parte de tu equipo. ¡Vamos a la batalla! \n";
        return true;
    }
    else
    {
        cout << ". . . Esta bien, piensa bien tu estrategia. El equipo perfecto te espera!\n";
        return false;
    }
}



#endif
