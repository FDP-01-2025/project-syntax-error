#include <iostream>
#include <conio.h>       // Para leer teclas del teclado (getch)
#include <windows.h>     // Para cambiar el color del texto en la consola
#include <vector>       // Para usar listas de datos (como arreglos mejorados)

#include "src/Pokemon.h"      // Archivo con la definición de qué es un Pokémon (nombre, tipo, ataques)
#include "src/PokemonType.h"  // Archivo con la definición de los tipos de Pokémon (nombre y color)
#include "src/Menu.h"

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

// Variables para moverse en el menú
int typeCursor = 0;     // en qué tipo estás parado
int pokemonCursor = 0;  // en qué Pokémon estás parado
char key;               // qué tecla presionaste
string selectedType;    // qué tipo elegiste
string selectedPokemon; // qué Pokémon elegiste


void showPokemonTypes()
{
    system("cls");
    cout << "Jugador 1:" << endl;
    cout << "Selecciona el tipo de Pokemon que deseas:" << endl;

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


int main()
{

    int modo = seleccionarModoJuego();
    system("pause");




       while (true)   //Este bucle se repite hasta que el usuario confirme la seleccion de un Pokémon
    {
        //Limpiamos las variables para que el usuario pueda elegir de nuevo
        selectedType = "";    
        selectedPokemon = "";

        // Selección de tipo
        while (selectedType == "")  //Mientras no haya elegido un tipo 
        {
            showPokemonTypes();  // Se muestra en pantalla los tipos de pokémon

            key = getch(); // Espera que el usuario seleccione una tecla 

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

        // Ahora que ya eligió un tipo, filtramos solo los Pokémon que son de ese tipo
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

        system("cls"); // Limpia la pantalla
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
            // Confirmó, salimos del ciclo y seguimos el programa
            break;
        }
        else
        {
            // No confirmó, mostramos mensaje y repetimos todo el proceso (tipo y Pokémon)
            cout << "\nRegresando al menu para que elijas otro Pokemon...\n";
            system("pause");
        }
    }

    // Aquí continúa el programa luego de confirmar selección




    return 0;
}

