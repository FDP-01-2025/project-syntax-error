#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "./headers/Pokemon.h"
#include "./headers/PokemonType.h"

using namespace std;

vector<PokemonType> pokemonTypes = {
    {"Agua", 3},
    {"Fuego", 13},
    {"Planta", 2},
    {"Electrico", 14},
    {"Normal", 7},
};

vector<Pokemon> listaPokemons = {
    {"Charmander", "Fuego", 39, 65, 22, 17, 30},
    {"Growlithe", "Fuego", 55, 60, 25, 20, 35},
    {"Squirtle", "Agua", 44, 43, 20, 15, 25},
    {"Psyduck", "Agua", 50, 55, 22, 18, 30},
    {"Bulbasaur", "Planta", 45, 45, 18, 14, 27},
    {"Oddish", "Planta", 45, 30, 15, 15, 28},
    {"Pikachu", "Electrico", 35, 90, 25, 20, 40},
    {"Magnemite", "Electrico", 25, 45, 30, 25, 35},
    {"Eevee", "Normal", 55, 55, 23, 18, 28},
    {"Meowth", "Normal", 40, 90, 20, 17, 25}
};

int typeCursor = 0;
int pokemonCursor = 0;
char key;
string selectedType;
string selectedPokemon;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void showPokemonTypes()
{
    system("cls");
    cout << "Bienvenido a Pokemon Battle!" << endl;
    cout << "Para seleccionar un tipo, presiona la tecla [Enter]." << endl;
    cout << "Para mover el cursor, usa las teclas [Flecha Arriba] o [Flecha Abajo]." << endl;

    for (int i = 0; i < pokemonTypes.size(); i++)
    {
        if (i == typeCursor)
        {
            setColor(pokemonTypes[i].color);
            cout << " > " << pokemonTypes[i].name << " <" << endl;
            setColor(7);
        }
        else
        {
            setColor(pokemonTypes[i].color);
            cout << "   " << pokemonTypes[i].name << endl;
            setColor(7);
        }
    }
}

// Filtra los pokémon por tipo
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

void showPokemonsOfType(const vector<Pokemon>& filteredPokemons, int cursor, int color)
{
    system("cls");
    cout << "Elige un pokémon de tipo ";
    setColor(color);
    cout << filteredPokemons[0].type << endl;
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

int main()
{
    // Selección de tipo
    while (selectedType == "")
    {
        showPokemonTypes();
        key = getch();
        switch (key)
        {
        case 72: // Flecha arriba
            typeCursor--;
            if (typeCursor < 0)
                typeCursor = pokemonTypes.size() - 1;
            break;
        case 80: // Flecha abajo
            typeCursor++;
            if (typeCursor >= pokemonTypes.size())
                typeCursor = 0;
            break;
        case 13: // Enter
            selectedType = pokemonTypes[typeCursor].name;
            break;
        default:
            break;
        }
    }

    // Filtrar pokémon del tipo seleccionado
    vector<Pokemon> pokemonsFiltrados = getPokemonsOfType(listaPokemons, selectedType);
    int colorSeleccionado = pokemonTypes[typeCursor].color;

    // Selección de pokémon
    pokemonCursor = 0;
    while (selectedPokemon == "")
    {
        showPokemonsOfType(pokemonsFiltrados, pokemonCursor, colorSeleccionado);
        key = getch();
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
    cout << "¡Has seleccionado a ";
    setColor(colorSeleccionado);
    cout << selectedPokemon;
    setColor(7);
    cout << " de tipo " << selectedType << "!" << endl;

    return 0;
}