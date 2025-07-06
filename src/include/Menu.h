#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;
// Cambiar color texto consola
void setColor(int color);

// Mover cursor a (x, y)
void setCursorPosition(int x, int y);

// Imprime texto con efecto máquina de escribir (sin salto de línea automático)
void animatedPrint(const string& text, int ms = 30);

// Imprime opciones con cursor resaltado a partir de startY
// Cambiado para recibir arreglo estático y tamaño
void showOptions(const string options[], int optionsSize, int cursor, int startY);

// Función para seleccionar modo de juego con bienvenida animada solo UNA VEZ
int selectGamemode();

#endif
