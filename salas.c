#include "biblioteca.h"

/**
 * \brief Cria e inicializada a estrututa de uma sala. 
 * \param y 
 * \param x
 * \param altura
 * \param largura 
 * \return Sala 
*/
SALA criaSala (int y, int x, int altura, int largura, ENTIDADE *monstro)
{
    SALA novaSala;

    novaSala.pos.y = y;
    novaSala.pos.x = x;
    novaSala.altura = altura;
    novaSala.largura = largura;
    novaSala.centro.y = y + (int)(altura / 2);
    novaSala.centro.x = x + (int)(largura / 2);
    novaSala.comida.y = rand() % (altura - 2) + y + 1;
    novaSala.comida.x = rand() % (largura - 2) + x + 1;
    novaSala.monstro = monstro;

    return novaSala;
}

/**
 * \brief Adiciona uma sala no mapa com auxílio da posição da sala. 
 * \param novaSala 
*/
void adicionaSalaMapa (SALA novaSala, ENTIDADE *monstro, int numero_mostros)
{   
    
    for (int y = novaSala.pos.y; y < novaSala.pos.y + novaSala.altura; y++)
    {
        for (int x = novaSala.pos.x; x < novaSala.pos.x + novaSala.largura; x++)
        {
            mapa[y][x].imagem = '.';
            mapa[y][x].podeAndar = true;
            mapa[y][x].transparente = true;
        }
    }
    
    mapa[novaSala.comida.y][novaSala.comida.x].imagem = 'o';

    //mapa[novaSala.comida.y][novaSala.comida.x].cor = COLOR_PAIR(COR_COMIDA); --> Não funciona 
    
    monstro = calloc (numero_mostros, sizeof(ENTIDADE)); //Array de n monstros

    novaSala.monstro = monstro;

    for (int i = 0; i < numero_mostros; i++)
    {   
        int y = rand() % (novaSala.altura - 2) + novaSala.pos.y + 1;
        int x = rand() % (novaSala.largura - 2) + novaSala.pos.x + 1;

        novaSala.monstro[i].pos.y = y;
        novaSala.monstro[i].pos.x = x;
        novaSala.monstro[i].imagem = 'M';
        //novaSala.monstro[i].cor = COLOR_PAIR(COR_MONSTRO); --> Não funciona 

        /* Quando o mostro morrer ou mover-se a peça passa a ser '.' */
        mapa[novaSala.monstro->pos.y][novaSala.monstro->pos.x].imagem = 'M';
        
    }
}

/**
 * \brief Cria corredores conectando o centro de duas salas do mapa.
 * \param centro1
 * \param centro2 
*/
void connectaCentroSalas (POSICAO centro1, POSICAO centro2)
{
    POSICAO novaPos;
    novaPos.x = centro1.x;
    novaPos.y = centro1.y;

    while (true)
    {
        if (abs((novaPos.x - 1) - centro2.x) < abs(novaPos.x - centro2.x))
            novaPos.x--;
        else if (abs((novaPos.x + 1) - centro2.x) < abs(novaPos.x - centro2.x))
            novaPos.x++;
        else if (abs((novaPos.y + 1) - centro2.y) < abs(novaPos.y - centro2.y))
            novaPos.y++;
        else if (abs((novaPos.y - 1) - centro2.y) < abs(novaPos.y - centro2.y))
            novaPos.y--;
        else
            break;

        mapa[novaPos.y][novaPos.x].imagem = '.';
        mapa[novaPos.y][novaPos.x].podeAndar = true;
        mapa[novaPos.y][novaPos.x].transparente = true;
    }
}
