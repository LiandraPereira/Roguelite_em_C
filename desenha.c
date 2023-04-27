#include "biblioteca.h"

void desenhaMapa(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if (mapa[y][x].visivel)
            {
                mvaddch(y, x, mapa[y][x].imagem | mapa[y][x].imagem);
            }
            else if (mapa[y][x].vista)
            {
                mvaddch(y, x, mapa[y][x].imagem | COLOR_PAIR(COR_VISTA));
            }
            else
            {
                mvaddch(y, x, ' ');
            }
        }
    }
}

void desenhaJogador(Jogador* jog)
{
    mvaddch(jog->pos.y, jog->pos.x, jog->imagem | jog->cor);
}

void desenhaAmbos(void)
{
    clear();
    desenhaMapa();
    desenhaJogador(jogador);
}