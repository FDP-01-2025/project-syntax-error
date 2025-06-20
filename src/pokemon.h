#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>
#include <vector>
#include "pokemonType.h"

class Pokemon
{
private:
    std::string name;
    int level;
    PokemonType type;
    std::vector<std::string> moves;

public:
    // Constructor con inicialización de lista
    Pokemon(const std::string &name, int level, PokemonType type);

    // Getters y setters combinados en una sola línea
    std::string getName() const { return name; }
    int getLevel() const { return level; }
    PokemonType getType() const { return type; }

    void setName(const std::string &newName) { name = newName; }
    void setLevel(int newLevel) { level = newLevel > 0 ? newLevel : level; } // Validación básica
    void setType(PokemonType newType) { type = newType; }

    // Método para agregar movimientos con validación
    void addMove(const std::string &move);

    // Mostrar información del Pokémon
    void displayInfo() const;

    // Sobrecarga del operador << para imprimir objetos fácilmente
    friend std::ostream &operator<<(std::ostream &os, const Pokemon &pokemon);
};

#endif
