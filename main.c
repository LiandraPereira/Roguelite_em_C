/**
 * @file main.c
 *
 * Neste ficheiro está contida a função principal do jogo.
 */

#include "biblioteca.h"
#include "mapa.h"
#include "jogador.h"
#include "monstro.h"


const int MAP_HEIGHT = 45; 
const int MAP_WIDTH = 120; 

ENTIDADE *jogador;
PECA **mapa;
GAMEINFO game_info;

/**
 * \brief Esta é a função principal do programa
 *
 * @returns O.
 */

int main()
{   
    POSICAO pos_inicial;
    bool compatibleTerminal;

    time_t tempoInicial = time(NULL);
    game_info.tempoInicial = tempoInicial;

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