#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
// Cambiar color texto consola
void setColor(int color);

// Mover cursor a (x, y)
void setCursorPosition(int x, int y);

// Imprime texto con efecto máquina de escribir (sin salto de línea automático)
void imprimirAnimado(const string& texto, int ms = 30);

// Imprime opciones con cursor resaltado a partir de startY
void imprimirOpciones(const vector<string>& opciones, int cursor, int startY);

// Función para seleccionar modo de juego con bienvenida animada solo UNA VEZ
int seleccionarModoJuego();

#endif