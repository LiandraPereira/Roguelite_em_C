#include "biblioteca.h"

bool cursesSetup(void)
{
    initscr();
    noecho();
    curs_set(0);

    if (has_colors())
    {
        start_color();

        init_pair(COR_VISIVEL, COLOR_WHITE, COLOR_BLACK);
        init_pair(COR_VISTA, COLOR_GREEN, COLOR_BLACK);

        return true;
    }
    else
    {
        mvprintw(20, 50, "Your system doesn't support color. Can't start game!");
        getch();
        return false;
    }
}

void gameLoop(void)
{
    int ch;

    modificaEstadoPeca(jogador);
    desenhaAmbos();

    while((ch = getch()))
    {
        if (ch == 'q')
        {
            break;
        }

        direcao(ch);
        desenhaAmbos();
    }
}

void closeGame(void)
{
    endwin();
    free(jogador);
}