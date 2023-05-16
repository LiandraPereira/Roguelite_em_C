#include "biblioteca.h"

const int MAP_HEIGHT = 25; //50
const int MAP_WIDTH = 100; // 150

Entidade* jogador;
Peca** mapa;


int main()
{   
    Posicao pos_inicial;
    bool compatibleTerminal;

    compatibleTerminal = cursesSetup();

    if (compatibleTerminal)
    {   
        srand(time(NULL)); // Retorna uma semente diferente sempre que inicia-se o jogo.

        desenhaMenu();

        mapa = criaMapaPecas(); // Cria o mapa

        pos_inicial = constroiSalasMapa(); // Posiciona o jogador na primeira sala criada

        jogador = criaJogador(pos_inicial); //Desenha o jogador no mapa

        gameLoop();

        closeGame();
    }
    else
    {
        endwin();
    }

    return 0;
}