/**
 * @file jogador.c
 *
 * Neste ficheiro estão as funções que tratam das funcionalidades do jogador.
 */

#include "biblioteca.h"
#include "jogador.h" 
#include "monstro.h"

/**
 * \brief Cria a ENTIDADE Jogador numa determinada posição.
 * @returns Apontador para a ENTIDADE Jogador. 
*/

ENTIDADE* criaJogador (POSICAO start_pos)
{
    ENTIDADE* novoJogador = calloc(1, sizeof(ENTIDADE));

    novoJogador->pos.y = start_pos.y;
    novoJogador->pos.x = start_pos.x;
    novoJogador->imagem = '@';
    novoJogador->cor = COLOR_PAIR(COR_JOGADOR);
    novoJogador->vida = 40;
    novoJogador->movimentos = 0;
    novoJogador->raio = 8;
    novoJogador->vitorias = 0;

    return novoJogador;
}

/**
 * \brief Altera a direção do Jogador usando as teclas numpad.
 * @param tecla 
*/
void direcao (int tecla)
{
    POSICAO nova_pos = { jogador->pos.y, jogador->pos.x };

     // Move para cima 
    if (tecla == 'w' || tecla == 'W' || tecla == '8'){
        nova_pos.y--;
        jogador->movimentos++;
    }    
    // Move para baixo
    else if (tecla == 's' || tecla == 'S' ||tecla == '2'){
        nova_pos.y++;
        jogador->movimentos++;
    }
    // Move para esquerda 
    else if (tecla == 'a' || tecla == 'A' || tecla =='4'){
        nova_pos.x--;
        jogador->movimentos++;
    }
    // Move para direita
    else if (tecla == 'd' || tecla == 'D' || tecla == '6'){
        nova_pos.x++;
        jogador->movimentos++;
    }

    movimentaJogador(nova_pos);
}

/**
 * \brief Movimenta o jogador para uma determinada posição. 
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
        else if (mapa[nova_pos.y][nova_pos.x].imagem == '^')
        {
            pisouArmadilha(nova_pos,10); 
        } else if (mapa[nova_pos.y][nova_pos.x].imagem == 'M')
        {
            combate(nova_pos);
            return;
        }
        
        estadoNormalPeca(jogador);

        jogador->pos.y = nova_pos.y;
        jogador->pos.x = nova_pos.x;
        
        modificaEstadoPeca(jogador);
    }
}

/**
 * \brief Adiciona um certo valor a vida do jogador e retira a comida do mapa.
 * @param nova_pos
 * @param valor 
*/
void adicionaVida(POSICAO nova_pos, int valor)
{
    if (jogador->vida == 40) return; // Não faz nada 

    mapa[nova_pos.y][nova_pos.x].imagem = '.';
    
    if (jogador->vida + valor > 40) jogador->vida = 40;
    else jogador->vida += valor;
}

/**
 * \brief Verifica a vida do jogador quando o mesmo pisa numa armadilha.
 * @param nova_pos
 * @param valor 
*/
void pisouArmadilha(POSICAO nova_pos, int valor){
    
    jogador->vida = jogador->vida - valor;
    mapa[nova_pos.y][nova_pos.x].imagem = '.';
    
    if(jogador->vida <= 0)
    {
        desenhaMenuFinal();
        return;
    }
    
}