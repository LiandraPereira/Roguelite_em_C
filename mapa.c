#include "biblioteca.h"

/**
 * \brief Cria todas as peças do mapa alocando memória para cada peça.
 * @return Apontador para vetor de apontadores de cada peça do mapa.  // Ainda por verificar
*/
Peca** criaMapaPecas() {

    Peca** pecas = calloc(MAP_HEIGHT, sizeof(Peca*));

    for (int y = 0; y < MAP_HEIGHT; y++) // y - comprimento do mapa
    {
        pecas[y] = calloc(MAP_WIDTH, sizeof(Peca));

        for (int x = 0; x < MAP_WIDTH; x++) // x - largura do mapa;
        {
            pecas[y][x].imagem = '#'; // # - Representa uma parede
            pecas[y][x].cor = COLOR_PAIR(COR_VISIVEL);
            pecas[y][x].podeAndar = false;
            pecas[y][x].transparente = false;
            pecas[y][x].visivel = false;
            pecas[y][x].vista = false;
        }
    }

    return pecas; // Cria peça por peça 
}

/**
 * \brief Constroi as salas e os corredores dentro do mapa. 
 * \return Posição da primeira sala do mapa. 
*/
Posicao constroiSalasMapa(){

    int y, x, altura, largura;
    int numero_salas = (rand() % 11) + 5; //O número máximo de salas é 15 --> Adicionar -- Entre 5 e 15

    Sala* salas = calloc(numero_salas, sizeof(Sala));
    Posicao pos_SalaInicial;

    for (int i = 0; i < numero_salas; i++)
    {
        y = (rand() % (MAP_HEIGHT - 15)) + 1; // 10 -- Tem de estar dentro do mapa
        x = (rand() % (MAP_WIDTH - 25)) + 1;  // 20 -- Também 

        altura = (rand() % 7) + 3; // Altura máxima é 9 - Entre 3 e 9
        largura = (rand() % 15) + 5; // Largura máxima é 19 - Entre 5 e 19

        salas[i] = criaSala(y, x, altura, largura);
        adicionaSalaMapa(salas[i]);
        
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
