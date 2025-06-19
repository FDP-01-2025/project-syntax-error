#include <iostream>
#include <conio.h>       // Para leer teclas del teclado (getch)
#include <windows.h>     // Para cambiar el color del texto en la consola
#include <vector>       // Para usar listas de datos (como arreglos mejorados)

#include "./headers/Pokemon.h"      // Archivo con la definición de qué es un Pokémon (nombre, tipo, ataques)
#include "./headers/PokemonType.h"  // Archivo con la definición de los tipos de Pokémon (nombre y color)

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
    {"Scorbunny", "Fuego",},
    {"Flareon", "Fuego",},
    {"Squirtle", "Agua", 44, 43, 20, 15, 25},
    {"Blastoise", "Agua", },
    {"Gyarados" "Agua",},
    {"Psyduck", "Agua", 50, 55, 22, 18, 30},
    {"Bulbasaur", "Planta", 45, 45, 18, 14, 27},
    {"Oddish", "Planta", 45, 30, 15, 15, 28},
    {"Leafeon", "Planta",},
    {"Grookey", "Planta",},
    {"Pikachu", "Electrico", 35, 90, 25, 20, 40},
    {"Jolteon", "Electrico", 45, 75, 20, 26, 50},
    {"Gengar", "Electrico", 25, 45, 30, 25, 35},
    {"Haunter", "Electrico",},
    {"Eevee", "Normal", 55, 55, 23, 18, 28},
    {"Snorlax", "Normal", },
    {"Pidgey", "Normal",},
    {"Meowth", "Normal", 40, 90, 20, 17, 25},
    {"Sandshrew", "Tierra", 50, 40, 20, 15, 25},
    {"Diglett", "Tierra", 10, 95, 25, 20, 30},
    {"Cubone", "Tierra",},
    {"Onix", "Tierra"}
};

// Variables para moverse en el menú
int typeCursor = 0;     // en qué tipo estás parado
int pokemonCursor = 0;  // en qué Pokémon estás parado
char key;               // qué tecla presionaste
string selectedType;    // qué tipo elegiste
string selectedPokemon; // qué Pokémon elegiste

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

void showPokemonsOfType(const vector<Pokemon>& filteredPokemons, int cursor, int color)
{
    system("cls");
    cout << "Elige un pokémon de tipo ";
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

    // Buscar el Pokémon seleccionado
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

    // TO DO: hacer el llamado de la funcion seleccion



    return 0;
}

