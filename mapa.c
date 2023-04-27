#include "biblioteca.h"

/**
 * \brief Cria o mapa adicionando peça por peça na memória alocada.
 * @return Apontador para o primeiro elemento da matriz ou ínício do mapa.
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
    return pecas;
}

/**
 * \brief
*/
Posicao setupMap(){

    int y, x, altura, largura, n_salas;
    n_salas =  (rand() % 11) + 5;
    // Room rooms[n_rooms];
    Sala* salas = calloc(n_salas, sizeof(Sala));
    Posicao pos_inicial;

    for (int i = 0; i < n_salas; i++)
    {
        y = (rand() % (MAP_HEIGHT - 10)) + 1;
        x = (rand() % (MAP_WIDTH - 20)) + 1;
        altura = (rand() % 7) + 3;
        largura = (rand() % 15) + 5;
        salas[i] = criaSala(y, x, altura, largura);
        adicionaSalaMapa(salas[i]);

        /*
        y = (rand() % (MAP_HEIGHT - 10)) + 1;
        x = (rand() % (MAP_WIDTH - 20)) + 1;
        height = (rand() % 7) + 3;
        width = (rand() % 15) + 5;
        rooms[i] = createRoom(y, x, height, width);
        addRoomToMap(rooms[i]);
        */

        if (i > 0)
        {
            connectaCentroSalas(salas[i-1].centro, salas[i].centro);
        }

    }

    pos_inicial.y = salas[0].centro.y;
    pos_inicial.x = salas[0].centro.x;

    free(salas);

    return pos_inicial;

}

/**
 * \brief Liberta o espaço do mapa na memória.
*/
void freeMap()
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        free(mapa[y]);
    }
    free(mapa);
}
