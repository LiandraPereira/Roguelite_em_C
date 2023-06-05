/**
 * @file mapa.c
 *
 * Neste ficheiro estão as funções que tratam da criação do mapa.
 */

#include "biblioteca.h"
#include "mapa.h"
#include "monstro.h"

/**
 * \brief Cria todas as peças do mapa alocando memória para cada peça.
 * @returns Matriz de peças.
*/
PECA **criaMapaPecas()
{
    PECA **pecas = calloc(MAP_HEIGHT, sizeof(PECA*));

    for (int y = 0; y < MAP_HEIGHT; y++) 
    {
        pecas[y] = calloc(MAP_WIDTH, sizeof(PECA));

        for (int x = 0; x < MAP_WIDTH; x++) 
        {
            pecas[y][x].imagem = '#'; 
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
 * \brief Constroi as salas do mapa.
 * @returns Posição da primeira sala do mapa.
*/
POSICAO constroiSalasMapa()
{
    int y, x, altura, largura, numero_monstros;
    int numero_salas = (rand() % 16) + 5;

    SALA *salas = calloc(numero_salas, sizeof(SALA));
    POSICAO pos_SalaInicial;

    for (int i = 0; i < numero_salas; i++)
    {
        y = (rand() % (MAP_HEIGHT - 15)) + 5; 
        x = (rand() % (MAP_WIDTH - 25)) + 5;

        altura = (rand() % 7) + 3;
        largura = (rand() % 15) + 5; 
        
        numero_monstros = (rand() % 2) + 1; 
        
        salas[i] = criaSala(y, x, altura, largura, numero_monstros);
        
        adicionaSalaMapa(salas[i]);
        adicionaMonstroSala (salas[i]);

        if (i > 0)
        {
            connectaCentroSalas(salas[i-1].centro, salas[i].centro);
        }

    }

    pos_SalaInicial.y = salas[0].centro.y;
    pos_SalaInicial.x = salas[0].centro.x;

    free(salas);

    return pos_SalaInicial;

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