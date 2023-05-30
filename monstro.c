#include "biblioteca.h" 

/**
 * @brief Cria a entidade Monstro numa determinada posição.
 * @return Apontador para a entidade Monstro. 
*/
ENTIDADE criaMonstro (int y, int x,)
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
 *
void adicionaMonstroSala (SALA novaSala)
{  
    for (int i = 0; i < novaSala.monstros; i++) 
    {   
        int y = rand() % (novaSala.altura)  + novaSala.pos.y  + 1; // Verificar a posição dos monstros
        int x = rand() % (novaSala.largura) + novaSala.pos.x  + 1;

        if (mapa[y][x].podeAndar)
        {
            novaSala.monstro[i] = criaMonstro(y,x,novaSala.monstro[i]);
            mapa[novaSala.monstro[i].pos.y][novaSala.monstro[i].pos.x].imagem = 'M';
        }
    }
}*/


/**
 * @brief Adiciona monstros numa sala. 
 * @return novaSala 
 */
void adicionaMonstroSala (SALA novaSala)
{  
    for (int i = 0; i < novaSala.monstros; i++) 
    {   
        int y = rand() % (novaSala.altura)  + novaSala.pos.y  + 1; // Verificar a posição dos monstros
        int x = rand() % (novaSala.largura) + novaSala.pos.x  + 1;

        if (mapa[y][x].podeAndar)
        {
            novaSala.monstro[i] = criaMonstro(y,x,novaSala.monstro[i]);
            mapa[novaSala.monstro[i].pos.y][novaSala.monstro[i].pos.x].imagem = 'M';
        }
    }
}



void combate (SALA sala, POSICAO posicao)
{
    for (int m = 0; m < sala.monstros; m++){
        if (sala.monstro[m].pos.y == posicao.y &&
            sala.monstro[m].pos.x == posicao.x)
        {
            if (sala.monstro[m].vida <= 0)
            {
                mapa[sala.monstro[m].pos.y][sala.monstro[m].pos.x].imagem = '.';
                movimentaJogador(posicao);
            } 
            else 
            {
                sala.monstro[m].vida -= 10;
            }
        } 
    }
}