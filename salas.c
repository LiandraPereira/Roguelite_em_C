#include "biblioteca.h"

/**
 * \brief Cria e inicializada a estrututa de uma sala. 
 * \param y 
 * \param x
 * \param altura
 * \param largura 
 * \return Sala 
*/
Sala criaSala (int y, int x, int altura, int largura)
{
    Sala novaSala;

    novaSala.pos.y = y;
    novaSala.pos.x = x;
    novaSala.altura = altura;
    novaSala.largura = largura;
    novaSala.centro.y = y + (int)(altura / 2);
    novaSala.centro.x = x + (int)(largura / 2);

    return novaSala;
}

/**
 * \brief Adiciona uma sala no mapa com auxílio da posição da sala. 
 * \param novaSala 
*/
void adicionaSalaMapa (Sala novaSala)
{
    for (int y = novaSala.pos.y; y < novaSala.pos.y + novaSala.altura; y++)
    {
        for (int x = novaSala.pos.x; x < novaSala.pos.x + novaSala.largura; x++)
        {
            mapa[y][x].imagem = '.';
            mapa[y][x].podeAndar = true;
            mapa[y][x].transparente = true;
        }
    }
}

/**
 * \brief Cria corredores conectando o centro de duas salas do mapa.
 * \param centro1
 * \param centro2 
*/
void connectaCentroSalas (Posicao centro1, Posicao centro2)
{
    Posicao novaPos;
    novaPos.x = centro1.x;
    novaPos.y = centro1.y;

    while (true)
    {
        if (abs((novaPos.x - 1) - centro2.x) < abs(novaPos.x - centro2.x))
            novaPos.x--;
        else if (abs((novaPos.x + 1) - centro2.x) < abs(novaPos.x - centro2.x))
            novaPos.x++;
        else if (abs((novaPos.y + 1) - centro2.y) < abs(novaPos.y - centro2.y))
            novaPos.y++;
        else if (abs((novaPos.y - 1) - centro2.y) < abs(novaPos.y - centro2.y))
            novaPos.y--;
        else
            break;

        mapa[novaPos.y][novaPos.x].imagem = '.';
        mapa[novaPos.y][novaPos.x].podeAndar = true;
        mapa[novaPos.y][novaPos.x].transparente = true;
    }
}
