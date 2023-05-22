#include "biblioteca.h"

/**
 * @file Jogador.c 
 * 
 * Jogador 
*/
/**
 * Cria a ENTIDADE Jogador numa determinada posição.
 * Apontador para a ENTIDADE Jogador. 
*/

/**
 * Breve descrição da função.
 *
 * Descrição mais detalhada da função, explicando o que ela faz, quais são os
 * parâmetros de entrada, o valor de retorno e possíveis exceções.
 *
 * @param parametro1 Descrição do parâmetro 1.
 * @param parametro2 Descrição do parâmetro 2.
 * @return Descrição do valor de retorno.
*/

ENTIDADE* criaJogador (POSICAO start_pos)
{
    ENTIDADE* novoJogador = calloc(1, sizeof(ENTIDADE));

    novoJogador->pos.y = start_pos.y;
    novoJogador->pos.x = start_pos.x;
    novoJogador->imagem = '@';
    novoJogador->cor = COLOR_PAIR(COR_VISTA);
    novoJogador->vida = 100;
    novoJogador->movimentos = 0;

    return novoJogador;
}

/**
 * \brief Altera as direção do Jogador usando as teclas numpad.
 * \param tecla 
 * 
*/
void direcao (int tecla)
{
    POSICAO nova_pos = { jogador->pos.y, jogador->pos.x };

    switch(tecla)
    {
        //move up
        case 'w':
            nova_pos.y--;
            jogador->movimentos++;
            break;
            //move down
        case 's':
            nova_pos.y++;
            jogador->movimentos++;
            break;
            //move left
        case 'a':
            nova_pos.x--;
            jogador->movimentos++;
            break;
            //move right
        case 'd':
            nova_pos.x++;
            jogador->movimentos++;
            break;
        default:
            break;
    }

    movimentaJogador(nova_pos);
}

/**
 * \brief Movimenta o Jogador para uma determinada posição. 
 * @param nova_pos
*/
void movimentaJogador(POSICAO nova_pos)
{
    if (mapa[nova_pos.y][nova_pos.x].podeAndar)
    {
        if (mapa[nova_pos.y][nova_pos.x].imagem == 'o')
        {
            adicionaVida(nova_pos,5);
        } 
        
        estadoNormalPeca(jogador);

        jogador->pos.y = nova_pos.y;
        jogador->pos.x = nova_pos.x;
        
        modificaEstadoPeca(jogador);
    }
}

/**
 * \brief Adiciona um certo valor a vida do jogador e retira a comida do mapa.
 * \param nova_pos
 * \param valor 
*/
void adicionaVida(POSICAO nova_pos, int valor)
{
    if (jogador->vida == 100) return; // Não faz nada 

    mapa[nova_pos.y][nova_pos.x].imagem = '.';
    
    if (jogador->vida + valor > 100) jogador->vida = 100;
    else jogador->vida += valor;
}