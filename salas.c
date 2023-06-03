#include "biblioteca.h"

/**
 * \brief Cria e inicializada a estrututa de uma sala. 
 * \param y 
 * \param x
 * \param altura
 * \param largura 
 * \return Sala 
*/
SALA criaSala (int y, int x, int altura, int largura, int numero_monstros)
{
    SALA novaSala;
    
    ENTIDADE *monstro = calloc(numero_monstros,sizeof(ENTIDADE));

    novaSala.pos.y = y;
    novaSala.pos.x = x;
    novaSala.altura = altura;
    novaSala.largura = largura;
    novaSala.centro.y = y + (int)(altura / 2);
    novaSala.centro.x = x + (int)(largura / 2);
    novaSala.monstros = numero_monstros;
    novaSala.monstro = monstro; 
    
    return novaSala;
}

/**
 * \brief Adiciona uma sala no mapa com auxílio da posição da sala. 
 * \param novaSala 
*/
void adicionaSalaMapa (SALA novaSala)
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
    
    COMIDA *novaComida = criaComida(novaSala);
    int y = novaComida->posicao.y, x = novaComida->posicao.x; 

    mapa[y][x].imagem = novaComida->imagem;

    ARMADILHA *novaArmadilha = criaArmadilha(novaSala); 

    if (novaArmadilha != NULL) // (??) Não percebi porqueê NULL
    {
        int y = novaArmadilha->posicao.y, x = novaArmadilha->posicao.x; 
        mapa[y][x].imagem = novaArmadilha->imagem;
        mapa[y][x].cor = novaArmadilha->cor;  
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

/**
 * \brief Função que cria comidas espalhadas pelo mapa
 * \param novaSala 
*/
COMIDA *criaComida(SALA novaSala) //Muda o nome para adicionaComida 
{
    int posY, posX;
    COMIDA* comida = calloc (1,sizeof(COMIDA));

    comida->imagem = 'o';

    do {
        posY = (rand() % (novaSala.altura)) + novaSala.pos.y;
        posX = (rand() % (novaSala.largura)) + novaSala.pos.x;
    } 
    while (!mapa[posY][posX].podeAndar);

    comida->posicao.x = posX;
    comida->posicao.y = posY;

    return comida;
}

ARMADILHA *criaArmadilha (SALA novaSala) //Aqui também 
{
    int chance = rand() % 10; //60% de chance de nascer de spawn
    ARMADILHA* armadilha = calloc(1,sizeof(ARMADILHA));

    armadilha->imagem = '^';

    if (chance <= 5)
    {
        int posY, posX;

        do {
            posY = (rand() % (novaSala.altura)) + novaSala.pos.y;
            posX = (rand() % (novaSala.largura)) + novaSala.pos.x;
        } 

        while (!mapa[posY][posX].podeAndar);
        
        armadilha->posicao.x = posX;
        armadilha->posicao.y = posY;
        
        return armadilha;
    }
    
    else return NULL;  
}