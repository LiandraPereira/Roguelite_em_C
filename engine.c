#include "biblioteca.h"
#include "mapa.h"
#include "jogador.h"


/**
 * \brief 
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
 * \brief
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
 * \brief 
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
 * \brief 
*/
void fimJogo ()
{ 
    endwin();
    freeMap();
    free(jogador);
    exit(0);
}