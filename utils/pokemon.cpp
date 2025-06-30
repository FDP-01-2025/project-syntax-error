#include "../include/pokemon.h"
#include "../include/Menu.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void Pokemon::ShowStats() const {
    cout << "\n+---------------------------------+\n";

    string title = " Estadísticas de " + name + " ";
    int largoTotal = 31;
    int espacios = largoTotal - title.length();
    int izquierda = espacios / 2;
    int derecha = espacios - izquierda;

    cout << "|" << string(izquierda, ' ') << title << string(derecha, ' ') << "   |\n";
    cout << "+---------------------------------+\n";

    cout << "| Tipo:             " << type << string(14 - type.length(), ' ') << "|\n";
    cout << "| HP:               " << hp << string(14 - to_string(hp).length(), ' ') << "|\n";
    cout << "| Velocidad:        " << speed << string(14 - to_string(speed).length(), ' ') << "|\n";
    cout << "| Ataque rápido:    " << fastattack << string(14 - to_string(fastattack).length(), ' ') << "|\n";
    cout << "| Ataque normal:    " << normalattack << string(14 - to_string(normalattack).length(), ' ') << "|\n";
    cout << "| Ataque especial:  " << specialattack << string(14 - to_string(specialattack).length(), ' ') << "|\n";
    cout << "+---------------------------------+\n\n";
}

// Filtra Pokémon por tipo, llenando arreglo filtrado y devolviendo la cantidad
int getPokemonsOfType(const Pokemon pokemonList[], int listSize, const string& type, Pokemon filtrados[], int maxFiltered) {
    int count = 0;
    for (int i = 0; i < listSize && count < maxFiltered; i++) {
        if (pokemonList[i].type == type) {
            filtrados[count++] = pokemonList[i];
        }
    }
    return count;
}

// Menú para mostrar Pokémon filtrados por tipo
void showPokemonsOfType(const Pokemon filteredPokemons[], int filteredCount, int cursor, int color) {
    system("cls");
    if (filteredCount == 0) return;

    cout << "Elige un pokémon de tipo ";
    setColor(color);
    cout << filteredPokemons[0].type << "!\n" << endl;
    setColor(7);

    for (int i = 0; i < filteredCount; i++) {
        if (i == cursor) {
            setColor(color);
            cout << " > " << filteredPokemons[i].name << " <" << endl;
            setColor(7);
        } else {
            cout << "   " << filteredPokemons[i].name << endl;
        }
    }
}

void showPokemonsNameByType(const Pokemon pokemonList[], int listSize, const string& tipoBuscado) {
    cout << "Pokémons tipo " << tipoBuscado << " \n";
    for (int i = 0; i < listSize; i++) {
        if (pokemonList[i].type == tipoBuscado) {
            cout << "  > " << pokemonList[i].name << "\n";
        }
    }

}

bool confirmPokemonCatch(const string& nombrePokemon) {
    char respuesta;
    cout << "¡Entrenador! ¿Seguro que quieres atrapar a " << nombrePokemon << "? 🌟 \n\n";
    cout << "Presiona 's' para lanzarle la Pokéball o 'n' para pensar un poco más:\n";
    cin >> respuesta;

    respuesta = tolower(respuesta);

    if (respuesta == 's') {
        cout << "¡Genial! 🎉  " << nombrePokemon << " es ahora parte de tu equipo. ¡Vamos a la batalla!\n\n";
        return true;
    } else {
        cout << "\n🤔 . . . Está bien, piensa bien tu estrategia. ¡El equipo perfecto te espera!\n";
        return false;
    }
}
