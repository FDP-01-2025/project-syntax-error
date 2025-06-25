#include "../include/pokemon.h"
#include "../include/Menu.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void Pokemon::mostrarStats() const
{
    cout << "\n+---------------------------------+\n";

    string titulo = " Estadisticas de " + name + " ";
    int largoTotal = 31;
    int espacios = largoTotal - titulo.length();
    int izquierda = espacios / 2;
    int derecha = espacios - izquierda;

    cout << "|" << string(izquierda, ' ') << titulo << string(derecha, ' ') << "  |\n";
    cout << "+---------------------------------+\n";

    cout << "| Tipo:             " << type << string(14 - type.length(), ' ') << "|\n";
    cout << "| HP:               " << hp << string(14 - to_string(hp).length(), ' ') << "|\n";
    cout << "| Velocidad:        " << speed << string(14 - to_string(speed).length(), ' ') << "|\n";
    cout << "| Ataque rapido:    " << fastattack << string(14 - to_string(fastattack).length(), ' ') << "|\n";
    cout << "| Ataque normal:    " << normalattack << string(14 - to_string(normalattack).length(), ' ') << "|\n";
    cout << "| Ataque especial:  " << specialattack << string(14 - to_string(specialattack).length(), ' ') << "|\n";
    cout << "+---------------------------------+\n";
}

// Filtra los Pokémon por tipo
vector<Pokemon> getPokemonsOfType(const vector<Pokemon>& pokemonList, const string& type)
{
    vector<Pokemon> filtered;
    for (const auto& p : pokemonList)
    {
        if (p.type == type)
            filtered.push_back(p);
    }
    return filtered;
}

// Menú de selección de Pokémon de un tipo
void showPokemonsOfType(const vector<Pokemon>& filteredPokemons, int cursor, int color)
{
    system("cls");
    cout << "Elige un pokemon de tipo ";
    setColor(color);
    cout << filteredPokemons[0].type << "!" << endl;
    setColor(7);

    for (int i = 0; i < filteredPokemons.size(); i++)
    {
        if (i == cursor)
        {
            setColor(color);
            cout << " > " << filteredPokemons[i].name << " <" << endl;
            setColor(7);
        }
        else
        {
            cout << "   " << filteredPokemons[i].name << endl;
        }
    }
}

void showPokemonsNameByType(const vector<Pokemon>& listaPokemons, const string& tipoBuscado)
{
    cout << "Pokemons tipo " << tipoBuscado << " \n";
    for (const auto& pokemon : listaPokemons)
    {
        if (pokemon.type == tipoBuscado)
        {
            cout << "  > " << pokemon.name << "\n";
        }
    }
    cout << "\nElige y gana!\n";
}

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