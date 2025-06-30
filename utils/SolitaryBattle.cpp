#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "pokemon.h"
#include "SolitaryBattle.h"

using namespace std;

const int UP = 72, DOWN = 80, ENTER = 13;

int seleccionarAtaqueConFlechas(const Pokemon& p) {
    int opcion = 0;
    const char* nombres[] = {"Ataque rápido", "Ataque normal", "Ataque especial"};
    int danos[] = {p.fastattack, p.normalattack, p.specialattack};

    while (true) {
        system("cls");
        cout << "🔥 ¡Turno de " << p.name << "! 🔥\n";
        cout << "Selecciona tu ataque:\n\n";

        for (int i = 0; i < 3; i++) {
            cout << (i == opcion ? "> " : "  ") << nombres[i] << " (" << danos[i] << " daño)\n";
        }

        int tecla = getch();
        if (tecla == 0 || tecla == 224) {
            tecla = getch();
            if (tecla == UP)
                opcion = (opcion + 2) % 3;
            else if (tecla == DOWN)
                opcion = (opcion + 1) % 3;
        } else if (tecla == ENTER) {
            system("cls");
            return opcion + 1;
        }
    }
}

void iniciarModoSolitario(const Pokemon listaPokemons[], int pokemonsCount, const Pokemon& jugadorFijo) {
    srand(time(0));
    int victoriasJugador = 0, victoriasCPU = 0;

    for (int ronda = 1; ronda <= 3; ronda++) {
        system("cls");
        cout << "╭─────────────────────────────────╮\n";
        cout << "│ Ronda " << ronda << " - ¡Comienza la batalla! │\n";
        cout << "╰─────────────────────────────────╯\n";

        int cpuIndex;
        do {
            cpuIndex = rand() % pokemonsCount;
        } while (listaPokemons[cpuIndex].name == jugadorFijo.name);
        Pokemon cpu = listaPokemons[cpuIndex];

        cout << "💥 La CPU envía a " << cpu.name << " al campo de batalla. ¡Prepárate!\n\n";
        system("pause");

        int hpJugador = jugadorFijo.hp;
        int hpCPU = cpu.hp;

        while (hpJugador > 0 && hpCPU > 0) {
            // Turno jugador
            int atk = seleccionarAtaqueConFlechas(jugadorFijo);
            int danioJugador;
            string nombreAtaque;

            if (atk == 1) {
                danioJugador = jugadorFijo.fastattack;
                nombreAtaque = "Ataque rápido";
            } else if (atk == 2) {
                danioJugador = jugadorFijo.normalattack;
                nombreAtaque = "Ataque normal";
            } else {
                danioJugador = jugadorFijo.specialattack;
                nombreAtaque = "Ataque especial";
            }

            system("cls");
            cout << "\n🗯️  " << jugadorFijo.name << " usa " << nombreAtaque << " y causa " << danioJugador << " de daño a " << cpu.name << "!\n";
            hpCPU -= danioJugador;
            if (hpCPU < 0) hpCPU = 0;
            cout << "💢 " << cpu.name << " queda con " << hpCPU << " HP.\n";
            system("pause");

            if (hpCPU == 0) {
                system("cls");
                cout << "\n🎉 ¡" << jugadorFijo.name << " ha vencido a " << cpu.name << " en esta ronda!\n\n";
                victoriasJugador++;
                break;
            }

            // Turno CPU
            int atkCPU = 1 + rand() % 3;
            int danioCPU;
            string nombreAtaqueCPU;

            if (atkCPU == 1) {
                danioCPU = cpu.fastattack;
                nombreAtaqueCPU = "Ataque rápido";
            } else if (atkCPU == 2) {
                danioCPU = cpu.normalattack;
                nombreAtaqueCPU = "Ataque normal";
            } else {
                danioCPU = cpu.specialattack;
                nombreAtaqueCPU = "Ataque especial";
            }

            cout << "\n⚠️  ¡" << cpu.name << " contraataca con " << nombreAtaqueCPU << " causando " << danioCPU << " de daño!\n";
            hpJugador -= danioCPU;
            if (hpJugador < 0) hpJugador = 0;
            cout << "😬 " << jugadorFijo.name << " queda con " << hpJugador << " HP.\n";
            system("pause");

            if (hpJugador == 0) {
                system("cls");
                cout << "\n💀 " << jugadorFijo.name << " ha caído... ¡La CPU gana esta ronda!\n\n";
                victoriasCPU++;
                break;
            }
        }

        system("cls");
        cout << "\n🏁 Marcador actual: Jugador " << victoriasJugador << " - CPU " << victoriasCPU << "\n\n";
        system("pause");
    }

    system("cls");
    cout << "╭─────────────────────────────────╮\n";
    cout << "│ ¡Resultado final de la batalla! │\n";
    cout << "╰─────────────────────────────────╯\n";

    if (victoriasJugador > victoriasCPU)
        cout << "✨ ¡Felicidades, entrenador! ¡Has ganado la batalla solitaria! ✨\n";
    else if (victoriasCPU > victoriasJugador)
        cout << "👾 La CPU se lleva la victoria. ¡Sigue entrenando!\n";
    else
        cout << "🤝 ¡Ha sido un empate digno de campeones!\n";
}

