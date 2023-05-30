#include "biblioteca.h"

const int MAP_HEIGHT = 45; //50
const int MAP_WIDTH = 120; // 150

ENTIDADE *jogador;
PECA **mapa;


int main()
{   
    POSICAO pos_inicial;
    bool compatibleTerminal;

    compatibleTerminal = cursorSetup();

    if (compatibleTerminal)
    {   
        srand(time(NULL)); // Retorna uma semente diferente sempre que inicia-se o jogo.

        desenhaMenu();

        mapa = criaMapaPecas(); // Cria o mapa

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