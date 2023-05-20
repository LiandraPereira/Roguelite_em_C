#include "biblioteca.h"

/**
 * \brief Cria todas as peças do mapa alocando memória para cada peça.
 * @return Apontador para array de apontadores de cada peça do mapa.
*/
PECA** criaMapaPecas()
{
    PECA** PECAs = calloc(MAP_HEIGHT, sizeof(PECA*));

    for (int y = 0; y < MAP_HEIGHT; y++) // y - comprimento do mapa
    {
        PECAs[y] = calloc(MAP_WIDTH, sizeof(PECA));

        for (int x = 0; x < MAP_WIDTH; x++) // x - largura do mapa;
        {
            PECAs[y][x].imagem = '#'; // # - Representa uma parede
            PECAs[y][x].cor = COLOR_PAIR(COR_VISIVEL);
            PECAs[y][x].podeAndar = false;
            PECAs[y][x].transparente = false;
            PECAs[y][x].visivel = false;
            PECAs[y][x].visto = false;
        }
    }

    return PECAs; // Cria peça por peça 
}

/**
 * \brief Constroi as salas e os corredores dentro do mapa.
 * \return Posição da primeira sala do mapa.
*/
POSICAO constroiSalasMapa(){

    int y, x, altura, largura;
    int numero_salas = (rand() % 16) + 5; //O número máximo de salas é 20 --> Adicionar -- Entre 5 e 15 11 -- 5
    int numero_monstros = (rand() % 4) + 5; // Entre 3 á 8 monstros;

    ENTIDADE *monstro = calloc(numero_monstros,sizeof(ENTIDADE));
    SALA *salas = calloc(numero_salas, sizeof(SALA));

    POSICAO pos_SalaInicial;

    for (int i = 0; i < numero_salas; i++)
    {
        y = (rand() % (MAP_HEIGHT - 15)) + 5; // 10 -- Tem de estar dentro do mapa 
        x = (rand() % (MAP_WIDTH - 25)) + 5;  // 20 -- Também

        altura = (rand() % 7) + 3; // Altura máxima é 9 - Entre 3 e 9
        largura = (rand() % 15) + 5; // Largura máxima é 19 - Entre 5 e 19

        salas[i] = criaSala(y, x, altura, largura, monstro);
        adicionaSalaMapa(salas[i], monstro, numero_monstros);

        if (i > 0)
        {
            connectaCentroSalas(salas[i-1].centro, salas[i].centro);
        }

    }

    pos_SalaInicial.y = salas[0].centro.y;
    pos_SalaInicial.x = salas[0].centro.x;

    free(salas);

    return pos_SalaInicial; // Primeira sala criada no mapa

}

/**
 * \brief Liberta o espaço do mapa alocado na memória.
*/
void freeMap()
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        free(mapa[y]);
    }
    free(mapa);
}
