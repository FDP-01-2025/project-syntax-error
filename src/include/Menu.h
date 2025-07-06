#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;
// Color change (0-7)
void setColor(int color);

// Move cursor to position x, y
void setCursorPosition(int x, int y);

// Print text with animated typing effect
void animatedPrint(const string& text, int ms = 30);

// Prints options with cursor highlighted from startY
// Changed to receive static array and size
void showOptions(const string options[], int optionsSize, int cursor, int startY);

// Function to select a game mode
int selectGamemode();

#endif
