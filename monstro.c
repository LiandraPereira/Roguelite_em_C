#include "biblioteca.h"
#include "monstro.h"

// Feito por (...)

/**
 * @brief Cria a entidade monstro numa determinada posição.
 * @return Entidade monstro. 
*/
ENTIDADE criaMonstro (int y, int x, ENTIDADE monstro)
{   
    monstro.pos.y = y;
    monstro.pos.x = x;
    monstro.imagem = 'M';
    monstro.cor = COLOR_PAIR(COR_MONSTRO);
    monstro.vida = 20;

    return monstro;
}

/**
 * @brief Adiciona monstros numa sala. 
 * @return novaSala 
 */
void adicionaMonstroSala (SALA novaSala)
{  
    for (int i = 0; i < novaSala.numero_monstros; i++) 
    {   
        int y = rand() % (novaSala.altura  - 1) + novaSala.pos.y  + 1; // Verificar a posição dos monstros
        int x = rand() % (novaSala.largura - 1) + novaSala.pos.x + 1;

        if (mapa[y][x].podeAndar)
        {
            novaSala.monstro[i] = criaMonstro(y,x,novaSala.monstro[i]);
            mapa[y][x].perigo = novaSala.monstro[i];
            mapa[novaSala.monstro[i].pos.y][novaSala.monstro[i].pos.x].imagem = novaSala.monstro[i].imagem;
            
        }
    }
}

/**
 * \brief Acontece o combate entre o jogador e o monstro. 
 * @param nova_pos
 * @param monstro
 * @return 
 */
void combate (POSICAO nova_pos)
{
    if (mapa[nova_pos.y][nova_pos.x].perigo.vida == 0)
    {
        mapa[nova_pos.y][nova_pos.x].imagem = '.';
        jogador->vitorias++;
    }
    else 
    {
        mapa[nova_pos.y][nova_pos.x].perigo.vida -= 10;
 
    }
}