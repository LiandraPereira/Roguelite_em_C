#include "biblioteca.h" 

/**
 * \brief Cria a entidade Monstro numa determinada posição.
 * \return Apontador para a entidade Monstro. 
*/
ENTIDADE criaMonstro (int y, int x, ENTIDADE monstro)
{   
    monstro.pos.y = y;
    monstro.pos.x = x;
    monstro.imagem = 'M';
    monstro.cor = COLOR_PAIR(COR_MONSTRO);

    return monstro;

}

/**
 * @brief Adiciona monstros numa sala. 
 * @return novaSala 
*/
void adicionaMonstroSala (SALA novaSala)
{   
    int y, x;

    for (int i = 0; i < novaSala.monstros; i++)
    {   
        y = rand() % (novaSala.altura - 2) + novaSala.pos.y + 1;
        x = rand() % (novaSala.largura - 2) + novaSala.pos.x + 1;

        novaSala.monstro[i] = criaMonstro(y,x,novaSala.monstro[i]);
        mapa[novaSala.monstro->pos.y][novaSala.monstro->pos.x].imagem = 'M';

    }
}

/**
 * \brief Gera uma posição aleatória. 
 * @param nova_posicao
 * @return Posição 
 *
Posicao posicao_aleatoria (Posicao posicao)
{
    Posicao nova_posicao;

    int y = (rand() % (MAP_HEIGHT - 15)) + 1; // 10 -- Tem de estar dentro do mapa
    int x = (rand() % (MAP_WIDTH - 25)) + 1;  // 20 -- Também 

    nova_posicao.y = y;
    nova_posicao.x = x;

    posicao = nova_posicao;

    return posicao;
}*/
