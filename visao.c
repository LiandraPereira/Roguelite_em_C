/**
 * @file visao.c
 *
 * Neste ficheiro estão as funções que tratam da visão e iluminação do jogador.
 */

#include <math.h>
#include "biblioteca.h"
#include "mapa.h"
#include "jogador.h"

/**
 * \brief Modifica os estado das peças que estão a volta do jogador formando um pseudo-círculo (círculo não perfeito).
 * 
 * @param jogador 
*/
void modificaEstadoPeca (ENTIDADE *jogador)
{
    int y, x, distancia;
    int RAIO = jogador->raio;
    POSICAO destino;

    mapa[jogador->pos.y][jogador->pos.x].visivel = true;
    mapa[jogador->pos.y][jogador->pos.x].vista = true;

    for (y = jogador->pos.y - RAIO; y < jogador->pos.y + RAIO; y++)
    {
        for (x = jogador->pos.x - RAIO; x < jogador->pos.x + RAIO; x++)
        {
            destino.y = y;
            destino.x = x;
            distancia
     = levaDistancia(jogador->pos, destino);

            if (distancia
     < RAIO)
            {
                if (posicaoDentroMapa(y, x) && linhaVisao(jogador->pos, destino))
                {
                    mapa[y][x].visivel = true;
                    mapa[y][x].vista = true;
                }
            }
        }
    }
}

/**
 * \brief Altera o estado da peças que estão fora do campo de visão do jogador.
 * 
 * @param jogador 
*/
void estadoNormalPeca(ENTIDADE *jogador)
{
    int y, x;
    int RAIO = jogador->raio;

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
 * 
 * @param origem
 * @param destino
 * @returns Distãncia entre dois pontos cartesianos.
*/
int levaDistancia(POSICAO origem, POSICAO destino)
{
    double dy, dx;
    int distancia;

    dx = destino.x - origem.x;
    dy = destino.y - origem.y;

    distancia = floor(sqrt((dx * dx) + (dy * dy)));

    return distancia;
}

/**
 * \brief Verifica se as coordenadas estão dentro do mapa.
 * 
 * @param y
 * @param x
 * @returns True ou False
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
 * \brief Implementa uma variação do algoritmo de Bresenham para determinar se existe uma linha de visão directa entre duas posições no mapa.
 * 
 * @param origem 
 * @param destino 
 * @returns True ou False 
*/
bool linhaVisao(POSICAO origem, POSICAO destino)
{
    int avancoLinha, x, y, abs_diferencaX, abs_diferencaY, sinalX, sinalY, diferencaX, diferencaY;

    diferencaX = origem.x - destino.x;
    diferencaY = origem.y - destino.y;

    abs_diferencaX = abs(diferencaX);
    abs_diferencaY = abs(diferencaY);

    sinalX = conheceSinal(diferencaX);
    sinalY = conheceSinal(diferencaY);

    x = destino.x;
    y = destino.y;

    if (abs_diferencaX > abs_diferencaY)
    {
        avancoLinha = abs_diferencaY * 2 - abs_diferencaX;

        do
        {
            if (avancoLinha >= 0)
            {
                y += sinalY;
                avancoLinha -= abs_diferencaX * 2;
            }

            x += sinalX;
            avancoLinha += abs_diferencaY * 2;

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
        avancoLinha = abs_diferencaX * 2 - abs_diferencaY;

        do
        {
            if (avancoLinha >= 0)
            {
                x += sinalX;
                avancoLinha -= abs_diferencaY * 2;
            }

            y += sinalY;
            avancoLinha += abs_diferencaX * 2;

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
 * 
 * @param numero
 * @returns True ou False 
*/
int conheceSinal(int numero)
{
    if (numero < 0)return -1;
    else return 1;
}