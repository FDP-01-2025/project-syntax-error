#ifndef BATALLA_H
#define BATALLA_H

#include <memory>
#include "pokemon.h"
#include "pokemonMove.h"

class Batalla
{
private:
    std::shared_ptr<Pokemon> jugador1;
    std::shared_ptr<Pokemon> jugador2;
    int marcadorJugador1;
    int marcadorJugador2;
    int rondasJugadas;
    int turnoActual;
    bool ataqueEspecialJ1;
    bool ataqueEspecialJ2;

    void mostrarEstado() const;
    void ejecutarTurno(std::shared_ptr<Pokemon> &atacante, std::shared_ptr<Pokemon> &defensor, bool &especialUsado);
    bool determinarOrdenDeAtaque() const;
    void mostrarGanadorDeRonda();
    void actualizarMarcador();
    void reiniciarRonda();

public:
    Batalla();

    void iniciarJuego();
    void seleccionarPokemons();
    void iniciarRonda();
    bool finDelJuego() const;
    void mostrarGanadorFinal() const;
};

#endif
