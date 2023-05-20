#include <math.h>
#include "biblioteca.h"

/**
 * \brief  DE VISAO
*/

void modificaEstadoPeca (ENTIDADE * jogador)
{
    int y, x, distance;
    int RAIO = 8;
    POSICAO destino;

    mapa[jogador->pos.y][jogador->pos.x].visivel = true;
    mapa[jogador->pos.y][jogador->pos.x].visto = true;

    for (y = jogador->pos.y - RAIO; y < jogador->pos.y + RAIO; y++)
    {
        for (x = jogador->pos.x - RAIO; x < jogador->pos.x + RAIO; x++)
        {
            destino.y = y;
            destino.x = x;
            distance = levaDistancia(jogador->pos, destino);

            if (distance < RAIO)
            {
                if (posicaoDentroMapa(y, x) && linhaVisao(jogador->pos, destino))
                {
                    mapa[y][x].visivel = true;
                    mapa[y][x].visto = true;
                }
            }
        }
    }
}

/**
 * \brief 
*/
void estadoNormalPeca(ENTIDADE * jogador)
{
    int y, x;
    int RAIO = 8;

    for (y = jogador->pos.y - RAIO; y < jogador->pos.y + RAIO; y++)
    {
        for (x = jogador->pos.x - RAIO; x < jogador->pos.x + RAIO; x++)
        {
            if (posicaoDentroMapa(y, x))
                mapa[y][x].visivel = false;
        }
    }
}

/**
 * \brief Calcula a distãncia euclidiana entre dois pontos, nomeadamente, posições no mapa.
 * \param origem
 * \param destino
 * \return Distãncia entre dois pontos cartesianos.
*/
int levaDistancia(POSICAO origem, POSICAO destino)
{
    double dy, dx;
    int distance;

    dx = destino.x - origem.x;
    dy = destino.y - origem.y;

    distance = floor(sqrt((dx * dx) + (dy * dy)));

    return distance;
}

/**
 * \brief Verifica se as coordenadas estão dentro do mapa.
 * \param y
 * \param x
 * \return True ou False
*/
bool posicaoDentroMapa(int y, int x)
{
    if ((0 < y && y < MAP_HEIGHT - 1) && (0 < x && x < MAP_WIDTH - 1))
    {
        return true;
    }
    return false;
}

/**
 * ESTUDAR ALGORITMO DE BRESENHAM
*/
bool linhaVisao(POSICAO origem, POSICAO destino)
{
    int t, x, y, abs_delta_x, abs_delta_y, sign_x, sign_y, delta_x, delta_y;

    delta_x = origem.x - destino.x;
    delta_y = origem.y - destino.y;

    abs_delta_x = abs(delta_x);
    abs_delta_y = abs(delta_y);

    sign_x = conheceSinal(delta_x);
    sign_y = conheceSinal(delta_y);

    x = destino.x;
    y = destino.y;

    if (abs_delta_x > abs_delta_y)
    {
        t = abs_delta_y * 2 - abs_delta_x;

        do
        {
            if (t >= 0)
            {
                y += sign_y;
                t -= abs_delta_x * 2;
            }

            x += sign_x;
            t += abs_delta_y * 2;

            if (x == origem.x && y == origem.y)
            {
                return true;
            }
        }
        while (mapa[y][x].transparente);

        return false;
    }
    else
    {
        t = abs_delta_x * 2 - abs_delta_y;

        do
        {
            if (t >= 0)
            {
                x += sign_x;
                t -= abs_delta_y * 2;
            }

            y += sign_y;
            t += abs_delta_x * 2;

            if (x == origem.x && y == origem.y)
            {
                return true;
            }
        }
        while (mapa[y][x].transparente);

        return false;
    }
}

/**
 * \brief Verifica o sinal de um número.
 * \param numero
 * \return True ou False 
*/
int conheceSinal(int numero)
{
    if (numero < 0)return -1;
    else return 1;
}