#include "biblioteca.h"

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

void connectaCentroSalas (Posicao centroOne, Posicao centroTwo)
{
    Posicao novaPos;
    novaPos.x = centroOne.x;
    novaPos.y = centroOne.y;

    while (true)
    {
        if (abs((novaPos.x - 1) - centroTwo.x) < abs(novaPos.x - centroTwo.x))
            novaPos.x--;
        else if (abs((novaPos.x + 1) - centroTwo.x) < abs(novaPos.x - centroTwo.x))
            novaPos.x++;
        else if (abs((novaPos.y + 1) - centroTwo.y) < abs(novaPos.y - centroTwo.y))
            novaPos.y++;
        else if (abs((novaPos.y - 1) - centroTwo.y) < abs(novaPos.y - centroTwo.y))
            novaPos.y--;
        else
            break;

        mapa[novaPos.y][novaPos.x].imagem = '.';
        mapa[novaPos.y][novaPos.x].podeAndar = true;
        mapa[novaPos.y][novaPos.x].transparente = true;
    }
}
