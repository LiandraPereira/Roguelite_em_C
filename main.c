#include "biblioteca.h"

const int MAP_HEIGHT = 45; //50
const int MAP_WIDTH = 120; // 150

Entidade* jogador;
Peca** mapa;


int main()
{   
    Posicao pos_inicial;
    bool compatibleTerminal;

    compatibleTerminal = cursorSetup();

    if (compatibleTerminal)
    {   
        srand(time(NULL)); // Retorna uma semente diferente sempre que inicia-se o jogo.

        desenhaMenu();

        mapa = criaMapaPecas(0,0); // Cria o mapa

        pos_inicial = constroiSalasMapa(); // Posiciona o jogador na primeira sala criada

        jogador = criaJogador(pos_inicial); //Desenha o jogador no mapa

        cicloJogo();

        fimJogo();
    }
    else
    {
        endwin();
    }

    return 0;
}