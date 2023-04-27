#include "biblioteca.h"

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;

Jogador* jogador;
Peca** mapa;

int main(void)
{
    Posicao start_pos;
    bool compatibleTerminal;

    compatibleTerminal = cursesSetup();

    if (compatibleTerminal)
    {
        srand(time(NULL));

        mapa = criaMapaPecas();
        start_pos = setupMap();
        jogador = criaJogador(start_pos);

        gameLoop();

        closeGame();
    }
    else
    {
        endwin();
    }

    return 0;
}