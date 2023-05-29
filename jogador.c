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
    novoJogador->vida = 40;
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

     // Move up 
    if (tecla == 'w' || tecla == 'W' || tecla == '8'){
        nova_pos.y--;
        jogador->movimentos++;
    }    
    // Move down 
    else if (tecla == 's' || tecla == 'S' ||tecla == '2'){
        nova_pos.y++;
        jogador->movimentos++;
    }
    // Move left 
    else if (tecla == 'a' || tecla == 'A' || tecla =='4'){
        nova_pos.x--;
        jogador->movimentos++;
    }
    // Move right 
    else if (tecla == 'd' || tecla == 'D' || tecla == '6'){
        nova_pos.x++;
        jogador->movimentos++;
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
            //desenhaMensagemTemporaria("Ganhou 5 de Vida", 2000);
        }
        if (mapa[nova_pos.y][nova_pos.x].imagem == '^')
        {
            pisouArmadilha(nova_pos,10);
            //desenhaMensagemTemporaria("Perdeu 10 de Vida", 2000);
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

/**
 * \brief Diminui a vida do jogador e verifica se morreu, caso pise numa armadilha
 * \param nova_pos
 * \param valor 
*/
void pisouArmadilha(POSICAO nova_pos, int valor){
    
    jogador->vida = jogador->vida - valor;
    mapa[nova_pos.y][nova_pos.x].imagem = '.';
    
    if(jogador->vida == 0) //MORREU ?
    {
        desenhaMenuFinal();
        return;
    }
    
}