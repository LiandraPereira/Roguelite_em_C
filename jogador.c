#include "biblioteca.h"

Jogador* criaJogador (Posicao start_pos)
{
    Jogador* novoJogador = calloc(1, sizeof(Jogador));

    novoJogador->pos.y = start_pos.y;
    novoJogador->pos.x = start_pos.x;
    novoJogador->imagem = '@';
    novoJogador->cor = COLOR_PAIR(COR_VISIVEL);

    return novoJogador;
}

void direcao (int input)
{
    Posicao nova_pos = { jogador->pos.y, jogador->pos.x };

    switch(input)
    {
        //move up
        case 'w':
            nova_pos.y--;
            break;
            //move down
        case 's':
            nova_pos.y++;
            break;
            //move left
        case 'a':
            nova_pos.x--;
            break;
            //move right
        case 'd':
            nova_pos.x++;
            break;
        default:
            break;
    }

    movimentaJogador(nova_pos);
}

void movimentaJogador(Posicao nova_pos)
{
    if (mapa[nova_pos.y][nova_pos.x].podeAndar)
    {
        estadoNormalPeca(jogador);
        jogador->pos.y = nova_pos.y;
        jogador->pos.x = nova_pos.x;
        modificaEstadoPeca(jogador);
    }
}