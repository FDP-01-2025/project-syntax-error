#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

#include "include/Menu.h"
#include "include/Pokemon.h"
#include "include/PokemonType.h"
#include "include/SolitaryBattle.h" 
#include "include/DuoBattle.h"

using namespace std;

// Lista de tipos de Pokémon
PokemonType pokemonTypes[] = {
    {"Agua", 3},
    {"Fuego", 12},
    {"Tierra", 5},
    {"Planta", 2},
    {"Electrico", 6},
    {"Normal", 7},
};

const int tiposCount = sizeof(pokemonTypes) / sizeof(pokemonTypes[0]);

// Lista de Pokémon
Pokemon listaPokemons[] = {
    {"Charmander", "Fuego", 90, 65, 15, 30, 45},
    {"Growlithe", "Fuego", 96, 60, 14, 28, 42},
    {"Scorbunny", "Fuego", 94, 69, 17, 35, 52},
    {"Flareon", "Fuego", 101, 65, 12, 25, 38},
    {"Squirtle", "Agua", 91, 43, 10, 18, 30},
    {"Blastoise", "Agua", 104, 78, 15, 30, 45},
    {"Gyarados", "Agua", 107, 81, 20, 40, 60},
    {"Psyduck", "Agua", 94, 55, 11, 22, 33},
    {"Bulbasaur", "Planta", 92, 45, 10, 20, 30},
    {"Oddish", "Planta", 92, 30, 8, 15, 22},
    {"Leafeon", "Planta", 101, 65, 14, 28, 42},
    {"Grookey", "Planta", 94, 65, 14, 28, 42},
    {"Pikachu", "Electrico", 89, 90, 18, 35, 50},
    {"Jolteon", "Electrico", 101, 100, 20, 40, 60},
    {"Gengar", "Electrico", 99, 95, 19, 38, 57},
    {"Haunter", "Electrico", 92, 78, 15, 30, 45},
    {"Eevee", "Normal", 96, 55, 11, 22, 33},
    {"Snorlax", "Normal", 120, 30, 12, 25, 38},
    {"Pidgey", "Normal", 90, 56, 10, 20, 30},
    {"Meowth", "Normal", 90, 90, 18, 35, 50},
    {"Sandshrew", "Tierra", 94, 40, 10, 20, 30},
    {"Diglett", "Tierra", 80, 95, 19, 38, 57},
    {"Cubone", "Tierra", 94, 35, 10, 20, 30},
    {"Onix", "Tierra", 89, 70, 13, 25, 38}
};

const int pokemonsCount = sizeof(listaPokemons) / sizeof(listaPokemons[0]);

int main(){
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // Para permitir tildes y emojis en Windows
#endif

    int modo = seleccionarModoJuego();
    system("pause");

    string selectedType;
    string selectedPokemon;

    const int maxFiltrados = 50;
    Pokemon pokemonsFiltrados[maxFiltrados];

    while (true){
        selectedType = "";
        selectedPokemon = "";

        // Selección del tipo
        int tipoSeleccionado = seleccionarTipoPokemon(pokemonTypes, tiposCount, 1);
        selectedType = pokemonTypes[tipoSeleccionado].name;
        int colorSeleccionado = pokemonTypes[tipoSeleccionado].color;

        // Filtrar pokémon por tipo

        int cantidadFiltrados = getPokemonsOfType(listaPokemons, pokemonsCount, selectedType, pokemonsFiltrados, maxFiltrados);

        // Selección de pokémon
        int pokemonCursor = 0;
        while (selectedPokemon == "")
        {
            showPokemonsOfType(pokemonsFiltrados, cantidadFiltrados, pokemonCursor, colorSeleccionado);
            char key = _getch();
            switch (key)
            {
                case 72: // Arriba
                    pokemonCursor = (pokemonCursor - 1 + cantidadFiltrados) % cantidadFiltrados;
                    break;
                case 80: // Abajo
                    pokemonCursor = (pokemonCursor + 1) % cantidadFiltrados;
                    break;
                case 13: // Enter
                    selectedPokemon = pokemonsFiltrados[pokemonCursor].name;
                    break;
            }
        }

        system("cls");
        cout << "¡Has seleccionado a ";
        setColor(colorSeleccionado);
        cout << selectedPokemon;
        setColor(7);
        cout << " de tipo " << selectedType << "!" << endl;

        // Mostrar stats del seleccionado
        Pokemon elegido;
        for (int i = 0; i < cantidadFiltrados; i++)
        {
            if (pokemonsFiltrados[i].name == selectedPokemon)
            {
                elegido = pokemonsFiltrados[i];
                break;
            }
        }

        elegido.mostrarStats();

        if (confirmarSeleccionDivertida(elegido.name))
        {
            system("pause");

            if (modo == 2) // Solo iniciar modo solitario si modo seleccionado es 2 (Solitario)
            {
                iniciarModoSolitario(listaPokemons, pokemonsCount, elegido);
                return 0; // Termina programa cuando acaba la batalla
            }
            else if (modo == 1)
            {
                iniciarModoDuoFlujo(listaPokemons, pokemonsCount, pokemonTypes, tiposCount, elegido);
                return 0; // Termina programa cuando acaba la batalla
            }
        }
        else
        {
            cout << "\nRegresando al menú para que elijas otro Pokémon...\n";
            system("pause");
        }
    }

    //Para ejecutar g++ main.cpp utils/*.cpp -Iinclude -o juego.exe   
    // .\juego.exe


    return 0;
}
