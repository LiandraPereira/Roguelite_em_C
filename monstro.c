#include "biblioteca.h" 

/**
 * \brief Cria a entidade Monstro numa determinada posição.
 * \return Apontador para a entidade criada. 
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

/**
 * \brief Movimenta aleatóriamente o monstro para uma posição. 
 * @param nova_posicao
 * @return Nova posição aleatoria no mapa. 
 */
Posicao posiciona_aleatoria (Posicao posicao)
{
    Posicao nova_posicao;

    nova_posicao.x = posicao.x + (rand() % 3) - 1;
    nova_posicao.y = posicao.y + (rand() % 3) - 1;

    return nova_posicao;
}

/**
 * \brief Movimenta o monstro para uma posição em frente.
 * @param origem
 * @param destino
 * @return Posição
*/
Posicao movimenta_frente (Posicao origem, Posicao destino) //Vai mudar após consultar outro algoritmo para o mostro.
{
    // implementacao do movimento em direcao a um ponto
    // por simplicidade, consideramos que o movimento a sempre reto, sem obstaculos

    int dx, dy, distancia, factor;

    dx = destino.x - origem.x;
    dy = destino.y - origem.y;

    distancia = levaDistancia(origem,destino);

    factor = (int) V_MONSTRO / distancia;

    Posicao nova_posicao;

    nova_posicao.x = origem.x + round(factor*dx);
    nova_posicao.y = origem.y + round(factor*dy);

    return nova_posicao;
}

/**
 * \brief Movimenta o Monstro para uma determinada posição. 
 * \param nova_pos
*/
void movimentaMonstro()
{
    Posicao nova_pos = posiciona_aleatoria(monstro->pos);

    if (mapa[nova_pos.y][nova_pos.x].podeAndar)
    {   
        monstro->pos.y = nova_pos.y;
        monstro->pos.x = nova_pos.x;
    }
}

/**
 * \brief Verifica se o mosntro consegue ou não ver o jogador no mapa. 
 * @param monstro
 * @param jogador 
 * \return Booleano 
*/
bool consegue_ver (Entidade* monstro, Entidade* jogador)
{
    // implementação da visão do monstro
    int RAIO = 5;

    int distancia = levaDistancia (monstro->pos,jogador->pos);

    if (distancia <= RAIO) return true; 
    
    return false;
}


/**
 * \brief TAREFAS - Assistir o video 12
 * 1. Adicionar um número aleaório de monstros nas salas criadas do mapa;
 * 2. Implementar o movimento aleatório do monstro, função esta que estará implmentada dentro do mapa, quando gerado aleatoriamente;
 * 3. Diminuir o raio do campo de visão do jogador.
*/




