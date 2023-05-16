#include "biblioteca.h" 

/**
 * \brief Cria a entidade Monstro numa determinada posição.
 * \return Apontador para a entidade Monstro. 
*/
Entidade* criaMonstro (Posicao pos_inicial)
{
    Entidade* novoMonstro = calloc(1, sizeof(Entidade));
    novoMonstro->pos.y = pos_inicial.y;
    novoMonstro->pos.x = pos_inicial.x;
    novoMonstro->imagem = 'M';
    novoMonstro->cor = COLOR_PAIR(COR_MONSTRO);
    return novoMonstro;
}

 //int numero_monstros = (rand() % 4) + 5; // Entre 3 á 8 monstros

Entidade* adicionaMonstros ()
{
    Entidade* monstros = calloc(12, sizeof(Entidade)); // Array de monstros

    for (int i = 0; i < 12; i++)
    {
        int y = (rand() % (MAP_HEIGHT - 15)) + 1; // 10 -- Tem de estar dentro do mapa
        int x = (rand() % (MAP_WIDTH - 25)) + 1;  // 20 -- Também 

        Posicao nova_posicao = {y,x};

        while (mapa[y][x].podeAndar)
        {
            monstros[i] = *criaMonstro(nova_posicao);
        }
    }

    return monstros;
}

/**
 * \brief Gera uma posição aleatória. 
 * @param nova_posicao
 * @return Posição 
 */
Posicao posicao_aleatoria (Posicao posicao)
{
    Posicao nova_posicao;

    int y = (rand() % (MAP_HEIGHT - 15)) + 1; // 10 -- Tem de estar dentro do mapa
    int x = (rand() % (MAP_WIDTH - 25)) + 1;  // 20 -- Também 

    nova_posicao.y = y;
    nova_posicao.x = x;

    posicao = nova_posicao;

    return posicao;
}
