#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "../include/pokemon.h"
#include "../include/SolitaryBattle.h"
#include "../include/Menu.h"

using namespace std;

const int UP = 72, DOWN = 80, ENTER = 13;

// Let the player choose an attack
int selectAttack(const Pokemon& p) {
    int option = 0;
    const char* attackNames[] = {"Fast Attack", "Normal Attack", "Special Attack"};
    int damages[] = {p.fastattack, p.normalattack, p.specialattack};

    while (true) {
        system("cls");
        cout << "🔥 " << p.name << "'s Turn! 🔥\n";
        cout << "Choose your attack:\n\n";

        for (int i = 0; i < 3; i++) {
            cout << (i == option ? "> " : "  ") << attackNames[i] << " (" << damages[i] << " damage)\n";
        }

        int key = getch();
        if (key == 0 || key == 224) {
            key = getch();
            if (key == UP)
                option = (option + 2) % 3;
            else if (key == DOWN)
                option = (option + 1) % 3;
        } else if (key == ENTER) {
            system("cls");
            return option + 1;
        }
    }
}

// Starts a 1-player mode battle against CPU
void start1PMode(const Pokemon pokemonList[], int pokemonsCount, const Pokemon& fixedPlayer) {
    srand(time(0));
    int playerWins = 0, cpuWins = 0;

    for (int round = 1; round <= 3; round++) {
        system("cls");
        cout << "╭───────────────────────────────────────────────╮\n";
        cout << "│ Round " << round << " - Let the battle begin ‼️              │\n";
        cout << "╰───────────────────────────────────────────────╯\n";

        int cpuIndex;
        do {
            cpuIndex = rand() % pokemonsCount;
        } while (pokemonList[cpuIndex].name == fixedPlayer.name);
        Pokemon cpu = pokemonList[cpuIndex];

        cout << "💥 CPU sends out " << cpu.name << " to the battlefield. Get ready!\n\n";
        system("pause");

        int hpPlayer = fixedPlayer.hp;
        int hpCPU = cpu.hp;

        while (hpPlayer > 0 && hpCPU > 0) {
            // Player's turn
            int atk = selectAttack(fixedPlayer);
            int playerDamage;
            string attackName;

            if (atk == 1) {
                playerDamage = fixedPlayer.fastattack;
                attackName = "Fast Attack";
            } else if (atk == 2) {
                playerDamage = fixedPlayer.normalattack;
                attackName = "Normal Attack";
            } else {
                playerDamage = fixedPlayer.specialattack;
                attackName = "Special Attack";
            }

            system("cls");
            setColor(5);
            cout << "┌──────────────────────────────────────────────┐\n";
            cout << "│ " << fixedPlayer.name << " attacks!                        \n";
            cout << "│ Used " << attackName << "!                                \n";
            cout << "│ ⚡ Damage dealt: " << playerDamage << "                            \n";
            cout << "└──────────────────────────────────────────────┘\n";
            setColor(3);
            hpCPU -= playerDamage;
            if (hpCPU < 0) hpCPU = 0;
            cout << "💢 " << cpu.name << " HP ➜ " << hpCPU << "\n";
            setColor(7);
            system("pause");

            if (hpCPU == 0) {
                system("cls");
                cout << "\n🎉 " << fixedPlayer.name << " has defeated " << cpu.name << " this round!\n\n";
                playerWins++;
                break;
            }

            // CPU's turn
            int atkCPU = 1 + rand() % 3;
            int cpuDamage;
            string cpuAttackName;

            if (atkCPU == 1) {
                cpuDamage = cpu.fastattack;
                cpuAttackName = "Fast Attack";
            } else if (atkCPU == 2) {
                cpuDamage = cpu.normalattack;
                cpuAttackName = "Normal Attack";
            } else {
                cpuDamage = cpu.specialattack;
                cpuAttackName = "Special Attack";
            }

            setColor(3);
            cout << "\n┌──────────────────────────────────────────────┐\n";
            cout << "│ " << cpu.name << " strikes back!                   \n";
            cout << "│ Used " << cpuAttackName << "!                           \n";
            cout << "│ 🔥 Damage dealt: " << cpuDamage << "                           \n";
            cout << "└──────────────────────────────────────────────┘\n";
            setColor(5);
            hpPlayer -= cpuDamage;
            if (hpPlayer < 0) hpPlayer = 0;
            cout << "😬 " << fixedPlayer.name << " HP ➜ " << hpPlayer << "\n\n";
            setColor(7);
            system("pause");

            if (hpPlayer == 0) {
                system("cls");
                cout << "\n💀 " << fixedPlayer.name << " has fallen... CPU wins this round!\n\n";
                cpuWins++;
                break;
            }
        }

    system("cls");
    string message;
    
    if (hpPlayer > hpCPU) {
    setColor(5); // 
    message = "\n🎉 The winner is you with " + fixedPlayer.name + "!\n";
} else {
    setColor(3); // 
    message = "\n🎉 The winner is the CPU with " + cpu.name + "!\n";
}
animatedPrint(message, 40); 
setColor(7);
system("pause");

cout << "\nCurrent score... 🕹️\n";
cout << fixedPlayer.name << " = " << playerWins << " | CPU = " << cpuWins << "\n";
system("pause");

    }

    system("cls");
    cout << "╭─────────────────────────────────╮\n";
    cout << "│       Final Battle Result       │\n"; 
    cout << "╰─────────────────────────────────╯\n";

    if (playerWins > cpuWins)
        animatedPrint("🥇 Congratulations, trainer! You won the solitary battle! 🥇 \n", 40);
    else if (cpuWins > playerWins)
        animatedPrint("👾 CPU takes the victory. Keep training!", 40);
    else
        animatedPrint("🤝 It's a draw worthy of champions!", 40);
}
