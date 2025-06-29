#ifndef MENU_H
#define MENU_H

#include <string>

// Cambiar color texto consola
void setColor(int color);

// Mover cursor a (x, y)
void setCursorPosition(int x, int y);

// Imprime texto con efecto máquina de escribir (sin salto de línea automático)
void imprimirAnimado(const std::string& texto, int ms = 30);

// Imprime opciones con cursor resaltado a partir de startY
// Cambiado para recibir arreglo estático y tamaño
void imprimirOpciones(const std::string opciones[], int opcionesSize, int cursor, int startY);

// Función para seleccionar modo de juego con bienvenida animada solo UNA VEZ
int seleccionarModoJuego();

#endif
