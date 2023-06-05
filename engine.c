/**
 * @file engine.c
 *
 * Neste ficheiro estão as funções que tratam de todas as configurações do jogo no terminal.
 */

#include "biblioteca.h"
#include "mapa.h"
#include "jogador.h"


/**
 * \brief Configura o terminal com auxílio da biblioteca ncurses.
*/
bool cursorSetup ()
{
    initscr();
    noecho();
    curs_set(0);

    if (has_colors())
    {
        start_color();

        init_pair(COR_VISIVEL,COLOR_WHITE, COLOR_BLACK);
        init_pair(COR_VISTA, COLOR_YELLOW, COLOR_BLACK);
        init_pair(COR_MONSTRO,COLOR_RED, COLOR_BLACK);
        init_pair(COR_COMIDA,COLOR_GREEN, COLOR_BLACK);
        init_pair(COR_ARMADILHA,COLOR_RED, COLOR_BLACK);
        init_pair(COR_JOGADOR,COLOR_CYAN, COLOR_BLACK);
        init_pair(COR_MORTO,COLOR_MAGENTA, COLOR_BLACK);

        return true;
    }
    else
    {
        mvprintw(20, 50, "Your system doesn't support color. Can't start game!");
        getch();
        return false;
    }
}

/**
 * \brief Ciclo do jogo.
*/
void cicloJogo ()
{
    
    
    int tecla;

    modificaEstadoPeca(jogador);
    desenhaJogo();

    while((tecla = getch()))
    {   
        
        if (tecla == 'q')
        {
            break;
        }
        
        direcao(tecla);
        desenhaJogo();
        
    }
    desenhaMenuFinal();    
}

/**
 * \brief Reinicia o jogo.
*/
void reiniciaJogo()
{   
    freeMap();
    free(jogador);


    time_t tempoInicial = time(NULL);
    game_info.tempoInicial = tempoInicial;
    mapa = criaMapaPecas(); //Cria novo Mapa
    POSICAO pos_inicial = constroiSalasMapa(); 
    jogador = criaJogador(pos_inicial); //Cria novo Jogador
    cicloJogo();
}

/**
 * \brief Finaliza o jogo com auxílio da biblioteca ncurses.
*/
void fimJogo ()
{ 
    endwin();
    freeMap();
    free(jogador);
    exit(0);
}