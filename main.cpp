#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

#include "include/Menu.h"
#include "include/Pokemon.h"
#include "include/PokemonType.h"

using namespace std;

vector<PokemonType> pokemonTypes = {
    {"Agua", 3},
    {"Fuego", 12},
    {"Tierra", 5},
    {"Planta", 2},
    {"Electrico", 6},
    {"Normal", 7},
};

vector<Pokemon> listaPokemons = {
    {"Charmander", "Fuego", 39, 65, 22, 17, 30},
    {"Growlithe", "Fuego", 55, 60, 25, 20, 35},
    {"Scorbunny", "Fuego", 50, 60, 80, 90, 10},
    {"Flareon", "Fuego", 44, 43, 20, 15, 25},
    {"Squirtle", "Agua", 44, 45, 2, 15, 5},
    {"Blastoise", "Agua", 44, 43, 20, 15, 25 },
    {"Gyarados", "Agua", 44, 43, 20, 15, 25},
    {"Psyduck", "Agua", 50, 55, 22, 18, 30},
    {"Bulbasaur", "Planta", 45, 45, 18, 14, 27},
    {"Oddish", "Planta", 45, 30, 15, 15, 28},
    {"Leafeon", "Planta", 44, 43, 20, 15, 25},
    {"Grookey", "Planta", 44, 43, 20, 15, 25},
    {"Pikachu", "Electrico", 35, 90, 25, 20, 40},
    {"Jolteon", "Electrico", 45, 75, 20, 26, 50},
    {"Gengar", "Electrico", 25, 45, 30, 25, 35},
    {"Haunter", "Electrico", 44, 43, 20, 15, 25},
    {"Eevee", "Normal", 55, 55, 23, 18, 28},
    {"Snorlax", "Normal", 44, 43, 20, 15, 25 },
    {"Pidgey", "Normal", 44, 43, 20, 15, 25},
    {"Meowth", "Normal", 40, 90, 20, 17, 25},
    {"Sandshrew", "Tierra", 50, 40, 20, 15, 25},
    {"Diglett", "Tierra", 10, 95, 25, 20, 30},
    {"Cubone", "Tierra", 44, 43, 20, 15, 25},
    {"Onix", "Tierra",  44, 43, 20, 15, 25}
};

int main()
{
    int modo = seleccionarModoJuego();
    system("pause");

    string selectedType;
    string selectedPokemon;

    while (true)
    {
        selectedType = "";
        selectedPokemon = "";

        // Selección de tipo usando función interactiva
        int tipoSeleccionado = seleccionarTipoPokemon(pokemonTypes);
        selectedType = pokemonTypes[tipoSeleccionado].name;
        int colorSeleccionado = pokemonTypes[tipoSeleccionado].color;

        // Filtrar pokémon por tipo
        vector<Pokemon> pokemonsFiltrados = getPokemonsOfType(listaPokemons, selectedType);

        // Selección de pokémon usando función interactiva
        int pokemonCursor = 0;
        while (selectedPokemon == "")
        {
            showPokemonsOfType(pokemonsFiltrados, pokemonCursor, colorSeleccionado);
            char key = getch();
            switch (key)
            {
            case 72: // Flecha arriba
                pokemonCursor--;
                if (pokemonCursor < 0)
                    pokemonCursor = pokemonsFiltrados.size() - 1;
                break;
            case 80: // Flecha abajo
                pokemonCursor++;
                if (pokemonCursor >= pokemonsFiltrados.size())
                    pokemonCursor = 0;
                break;
            case 13: // Enter
                selectedPokemon = pokemonsFiltrados[pokemonCursor].name;
                break;
            default:
                break;
            }
        }

        system("cls");
        cout << "Has seleccionado a ";
        setColor(colorSeleccionado);
        cout << selectedPokemon;
        setColor(7);
        cout << " de tipo " << selectedType << "!" << endl;

        // Buscar el Pokémon seleccionado con sus estadisticas 
        Pokemon elegido;
        for (const auto& p : pokemonsFiltrados)
        {
            if (p.name == selectedPokemon)
            {
                elegido = p;
                break;
            }
        }

        // Mostrar los stats
        elegido.mostrarStats();

        // Confirmar selección
        bool confirmado = confirmarSeleccionDivertida(elegido.name);
        if (confirmado)
        {
            break;
        }
        else
        {
            cout << "\nRegresando al menu para que elijas otro Pokemon...\n";
            system("pause");
        }
    }

// PARA COMPLIAR EL PROYECTO HASTA ESTE AVANCE, SE NECESITA ESTE COMANDO:
// g++ .\main.cpp .\utils\menuFunctions.cpp .\utils\pokemon.cpp .\utils\pokemonType.cpp {} -o main

// SI SE CREAN MAS COSAS, SE AGREGA AQUI (QUITEN {} -------------------------------------↑
    return 0;
}

