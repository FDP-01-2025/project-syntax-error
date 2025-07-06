#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "../include/pokemon.h"
#include "../include/SolitaryBattle.h"

using namespace std;

const int UP = 72, DOWN = 80, ENTER = 13;

int selectAttack(const Pokemon& p) {
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

        int key = getch();
        if (key == 0 || key == 224) {
            key = getch();
            if (key == UP)
                opcion = (opcion + 2) % 3;
            else if (key == DOWN)
                opcion = (opcion + 1) % 3;
        } else if (key == ENTER) {
            system("cls");
            return opcion + 1;
        }
    }
}

void start1PMode(const Pokemon pokemonList[], int pokemonsCount, const Pokemon& jugadorFijo) {
    srand(time(0));
    int victoriasPlayer = 0, victoriasCPU = 0;

    for (int round = 1; round <= 3; round++) {
        system("cls");
        cout << "╭─────────────────────────────────╮\n";
        cout << "│ Ronda " << round << " - ¡Comienza la batalla! │\n";
        cout << "╰─────────────────────────────────╯\n";

        int cpuIndex;
        do {
            cpuIndex = rand() % pokemonsCount;
        } while (pokemonList[cpuIndex].name == jugadorFijo.name);
        Pokemon cpu = pokemonList[cpuIndex];

        cout << "💥 La CPU envía a " << cpu.name << " al campo de batalla. ¡Prepárate!\n\n";
        system("pause");

        int hpPlayer = jugadorFijo.hp;
        int hpCPU = cpu.hp;

        while (hpPlayer > 0 && hpCPU > 0) {
            // Turno jugador
            int atk = selectAttack(jugadorFijo);
            int danioPlayer;
            string nombreAtaque;

            if (atk == 1) {
                danioPlayer = jugadorFijo.fastattack;
                nombreAtaque = "Ataque rápido";
            } else if (atk == 2) {
                danioPlayer = jugadorFijo.normalattack;
                nombreAtaque = "Ataque normal";
            } else {
                danioPlayer = jugadorFijo.specialattack;
                nombreAtaque = "Ataque especial";
            }

            system("cls");
            cout << "\n🗯️  " << jugadorFijo.name << " usa " << nombreAtaque << " y causa " << danioPlayer << " de daño a " << cpu.name << "!\n";
            hpCPU -= danioPlayer;
            if (hpCPU < 0) hpCPU = 0;
            cout << "💢 " << cpu.name << " queda con " << hpCPU << " HP.\n";
            system("pause");

            if (hpCPU == 0) {
                system("cls");
                cout << "\n🎉 ¡" << jugadorFijo.name << " ha vencido a " << cpu.name << " en esta round!\n\n";
                victoriasPlayer++;
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
            hpPlayer -= danioCPU;
            if (hpPlayer < 0) hpPlayer = 0;
            cout << "😬 " << jugadorFijo.name << " queda con " << hpPlayer << " HP.\n";
            system("pause");

            if (hpPlayer == 0) {
                system("cls");
                cout << "\n💀 " << jugadorFijo.name << " ha caído... ¡La CPU gana esta round!\n\n";
                victoriasCPU++;
                break;
            }
        }

        system("cls");
        cout << "\n🏁 Marcador actual: Player = " << victoriasPlayer << " - CPU = " << victoriasCPU << "\n\n"; 
        system("pause");
    }

    system("cls");
    cout << "╭─────────────────────────────────╮\n";
    cout << "│ ¡Resultado final de la batalla! │\n";
    cout << "╰─────────────────────────────────╯\n";

    if (victoriasPlayer > victoriasCPU)
        cout << "✨ ¡Felicidades, entrenador! ¡Has ganado la batalla solitaria! ✨\n";
    else if (victoriasCPU > victoriasPlayer)
        cout << "👾 La CPU se lleva la victoria. ¡Sigue entrenando!\n";
    else
        cout << "🤝 ¡Ha sido un empate digno de campeones!\n";
}

