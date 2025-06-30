#include "../include/DuoBattle.h"
#include "../include/Menu.h"
#include "../include/PokemonType.h"
#include "../include/SolitaryBattle.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

Pokemon seleccionarPokemonJugador(const Pokemon listaPokemons[], int pokemonsCount,
                                  const PokemonType tipos[], int tiposCount,
                                  int jugadorNum)
{
    const int maxFiltrados = 50;
    Pokemon pokemonsFiltrados[maxFiltrados];

    system("cls");
    // Usamos la función actualizada que devuelve el PokemonType
    int tipoSeleccionado = seleccionarTipoPokemon(tipos, tiposCount, jugadorNum);
    PokemonType tipoElegido = tipos[tipoSeleccionado];

    string tipo = tipoElegido.name;
    int color = tipoElegido.color;

    int cantidadFiltrados = getPokemonsOfType(listaPokemons, pokemonsCount, tipo, pokemonsFiltrados, maxFiltrados);

    int cursor = 0;
    string nombreSeleccionado = "";

    while (nombreSeleccionado == "")
    {
        showPokemonsOfType(pokemonsFiltrados, cantidadFiltrados, cursor, color);
        char tecla = _getch();

        if (tecla == 72) // Arriba
            cursor = (cursor - 1 + cantidadFiltrados) % cantidadFiltrados;
        else if (tecla == 80) // Abajo
            cursor = (cursor + 1) % cantidadFiltrados;
        else if (tecla == 13) // Enter
            nombreSeleccionado = pokemonsFiltrados[cursor].name;
    }

    system("cls");
    cout << "Jugador " << jugadorNum << " seleccionó a ";
    setColor(color);
    cout << nombreSeleccionado;
    setColor(7);
    cout << " de tipo " << tipo << "!\n";

    Pokemon elegido;
    for (int i = 0; i < cantidadFiltrados; i++)
    {
        if (pokemonsFiltrados[i].name == nombreSeleccionado)
        {
            elegido = pokemonsFiltrados[i];
            break;
        }
    }

    elegido.mostrarStats();

    if (confirmarSeleccionDivertida(elegido.name))
        return elegido;
    else
        return Pokemon{"", "", 0, 0, 0, 0, 0}; // Selección cancelada
}

void iniciarModoDuo(const Pokemon& jugador1, const Pokemon& jugador2)
{
    int hpJugador1 = jugador1.hp;
    int hpJugador2 = jugador2.hp;

    // Determinar quién empieza según velocidad
    int turno = (jugador1.speed >= jugador2.speed) ? 1 : 2;

    while (hpJugador1 > 0 && hpJugador2 > 0)
    {
        if (turno == 1)
        {
            system("cls");
            cout << "Turno de Jugador 1 (" << jugador1.name << ")\n";
            int ataqueJugador1 = seleccionarAtaqueConFlechas(jugador1);
            int danioJugador1 = 0;
            string nombreAtaque1;

            if (ataqueJugador1 == 1) {
                danioJugador1 = jugador1.fastattack;
                nombreAtaque1 = "Ataque rápido";
            }
            else if (ataqueJugador1 == 2) {
                danioJugador1 = jugador1.normalattack;
                nombreAtaque1 = "Ataque normal";
            }
            else {
                danioJugador1 = jugador1.specialattack;
                nombreAtaque1 = "Ataque especial";
            }

            system("cls");
            cout << "Jugador 1 - " << jugador1.name << " usa " << nombreAtaque1 << " y causa " << danioJugador1 << " de daño.\n";
            hpJugador2 -= danioJugador1;
            if (hpJugador2 < 0) hpJugador2 = 0;
            cout << "Jugador 2 - " << jugador2.name << " tiene " << hpJugador2 << " HP restantes.\n";
            system("pause");

            if (hpJugador2 == 0) break;

            turno = 2; // pasa al jugador 2
        }
        else // turno == 2
        {
            system("cls");
            cout << "Turno de Jugador 2 (" << jugador2.name << ")\n";
            int ataqueJugador2 = seleccionarAtaqueConFlechas(jugador2);
            int danioJugador2 = 0;
            string nombreAtaque2;

            if (ataqueJugador2 == 1) {
                danioJugador2 = jugador2.fastattack;
                nombreAtaque2 = "Ataque rápido";
            }
            else if (ataqueJugador2 == 2) {
                danioJugador2 = jugador2.normalattack;
                nombreAtaque2 = "Ataque normal";
            }
            else {
                danioJugador2 = jugador2.specialattack;
                nombreAtaque2 = "Ataque especial";
            }

            system("cls");
            cout << "Jugador 2 - " << jugador2.name << " usa " << nombreAtaque2 << " y causa " << danioJugador2 << " de daño.\n";
            hpJugador1 -= danioJugador2;
            if (hpJugador1 < 0) hpJugador1 = 0;
            cout << "Jugador 1 - " << jugador1.name << " tiene " << hpJugador1 << " HP restantes.\n";
            system("pause");

            if (hpJugador1 == 0) break;

            turno = 1; // pasa al jugador 1
        }
    }

    system("cls");
     cout << "╭─────────────────────────────────╮\n";
     cout << "│ ¡Resultado final de la batalla! │\n";
     cout << "╰─────────────────────────────────╯\n";

    if (hpJugador1 > hpJugador2)
        cout << " ✨ ¡Felicidades, jugador 1! ¡Has ganado la batalla solitaria con " << jugador1.name << "! ✨\n";
    else if (hpJugador2 > hpJugador1)
         cout << " ✨ ¡Felicidades, jugador 2! ¡Has ganado la batalla solitaria con " << jugador2.name << "!\n ✨";
    else
        cout << "¡Empate entre ambos jugadores!\n";

    system("pause");
}

void iniciarModoDuoFlujo(const Pokemon listaPokemons[], int pokemonsCount,
                         const PokemonType tipos[], int tiposCount,
                         const Pokemon& jugador1)
{
    Pokemon jugador2 = seleccionarPokemonJugador(listaPokemons, pokemonsCount, tipos, tiposCount, 2);

    if (jugador2.name != "")
    {
        system("pause");
        iniciarModoDuo(jugador1, jugador2);
    }
    else
    {
        cout << "Jugador 2 canceló la selección. Regresando al menú...\n";
        system("pause");
    }
}
