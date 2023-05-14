#include "biblioteca.h"

/**
 * \brief Cria a entidade Jogador numa determinada posição.
 * \return Apontador para a entidade Jogador. 
*/
Entidade* criaJogador (Posicao start_pos)
{
    Entidade* novoJogador = calloc(1, sizeof(Entidade));

    novoJogador->pos.y = start_pos.y;
    novoJogador->pos.x = start_pos.x;
    novoJogador->imagem = '@';
    novoJogador->cor = COLOR_PAIR(COR_VISTA);

    return novoJogador;
}

/**
 * \brief Altera as direção do Jogador usando as teclas numpad.
 * \param tecla 
 * 
*/
void direcao (int tecla)
{
    Posicao nova_pos = { jogador->pos.y, jogador->pos.x };

    switch(tecla)
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

/**
 * \brief Movimenta o Jogador para uma determinada posição. 
 * \param nova_pos
*/
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