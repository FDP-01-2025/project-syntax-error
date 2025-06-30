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

bool batallaDuo(Pokemon jugador1, Pokemon jugador2, int ronda)
{
    int hpJugador1 = jugador1.hp;
    int hpJugador2 = jugador2.hp;

    system("cls");
    cout << "╭─────────────────────────────────╮\n";
    cout << "│ Ronda " << ronda << " - ¡Comienza la batalla! │\n";
    cout << "╰─────────────────────────────────╯\n";

    system("pause");

    int turno = (jugador1.speed >= jugador2.speed) ? 1 : 2;

    while (hpJugador1 > 0 && hpJugador2 > 0)
    {
        if (turno == 1)
        {
            system("cls");
            cout << "Turno de Jugador 1 (" << jugador1.name << ")\n";
            int ataqueJugador1 = seleccionarAtaqueConFlechas(jugador1);
            int danio = (ataqueJugador1 == 1) ? jugador1.fastattack :
                        (ataqueJugador1 == 2) ? jugador1.normalattack : jugador1.specialattack;
            string nombreAtaque = (ataqueJugador1 == 1) ? "Ataque rápido" :
                                   (ataqueJugador1 == 2) ? "Ataque normal" : "Ataque especial";

            cout << jugador1.name << " usa " << nombreAtaque << " y causa " << danio << " de daño.\n";
            hpJugador2 -= danio;
            if (hpJugador2 < 0) hpJugador2 = 0;
            cout << jugador2.name << " tiene " << hpJugador2 << " HP restantes.\n";
            system("pause");

            if (hpJugador2 == 0) break;
            turno = 2;
        }
        else
        {
            system("cls");
            cout << "Turno de Jugador 2 (" << jugador2.name << ")\n";
            int ataqueJugador2 = seleccionarAtaqueConFlechas(jugador2);
            int danio = (ataqueJugador2 == 1) ? jugador2.fastattack :
                        (ataqueJugador2 == 2) ? jugador2.normalattack : jugador2.specialattack;
            string nombreAtaque = (ataqueJugador2 == 1) ? "Ataque rápido" :
                                   (ataqueJugador2 == 2) ? "Ataque normal" : "Ataque especial";

            cout << jugador2.name << " usa " << nombreAtaque << " y causa " << danio << " de daño.\n";
            hpJugador1 -= danio;
            if (hpJugador1 < 0) hpJugador1 = 0;
            cout << jugador1.name << " tiene " << hpJugador1 << " HP restantes.\n";
            system("pause");

            if (hpJugador1 == 0) break;
            turno = 1;
        }
    }
    
    system("cls");
    if (hpJugador1 > hpJugador2)
    {
        cout << "\n🎉 ¡Jugador 1 gana esta ronda con " << jugador1.name << "!\n";
        return true;
    }
    else
    {
        cout << "\n🎉 Jugador 2 gana esta ronda con " << jugador2.name << "!\n";
        return false;
    }
}

void iniciarModoDuo(const Pokemon& jugador1, const Pokemon& jugador2)
{
    int puntosJugador1 = 0;
    int puntosJugador2 = 0;

    for (int ronda = 1; ronda <= 3; ronda++)
    {
        bool ganaJugador1 = batallaDuo(jugador1, jugador2, ronda);
        if (ganaJugador1)
            puntosJugador1++;
        else
            puntosJugador2++;

        cout << "\n🏁 Marcador actual: Jugador 1" << puntosJugador1 << " | Jugador 2 = " << puntosJugador2 << "\n";
        system("pause");
    }

    system("cls");
    cout << "╭─────────────────────────────────╮\n";
    cout << "│ ¡Resultado final de la batalla! │\n";
    cout << "╰─────────────────────────────────╯\n";


    if (puntosJugador1 > puntosJugador2)
        cout << "🏆 ¡Jugador 1 gana la partida con " << puntosJugador1 << " rondas ganadas!\n";
    else if (puntosJugador2 > puntosJugador1)
        cout << "🏆 ¡Jugador 2 gana la partida con " << puntosJugador2 << " rondas ganadas!\n";
    else
        cout << "🤝 ¡Empate! Ambos jugadores ganaron " << puntosJugador1 << " rondas.\n";

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
