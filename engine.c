#include "biblioteca.h"

bool cursesSetup()
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

        return true;
    }
    else
    {
        mvprintw(20, 50, "Your system doesn't support color. Can't start game!");
        getch();
        return false;
    }
}

void gameLoop()
{
    int tecla;

    modificaEstadoPeca(jogador);
    desenhaAmbos();

    while((tecla = getch()))
    {   
        
        if (tecla == 'q')
        {
            break;
        }
        
        direcao(tecla);
        desenhaAmbos();
        
    }
}

void closeGame()
{
    endwin();
    free(jogador);
}