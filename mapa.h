/**
 * @file mapa.h
 *
 * Neste ficheiro estão contidos os protótipos do módulo mapa.c
 */

#ifndef ROQUELITE_EM_C_MAPA_H
#define ROQUELITE_EM_C_MAPA_H

PECA** criaMapaPecas();

POSICAO constroiSalasMapa();

SALA criaSala (int y, int x, int altura, int largura, int numero_monstros);

void adicionaSalaMapa (SALA novaSala);

void connectaCentroSalas (POSICAO centro1, POSICAO centro2);

void freeMap();

OBJETO *criaComida(SALA novaSala);

OBJETO *criaArmadilha (SALA novaSala);

#endif //ROQUELITE_EM_C_MAPA_H
