
#ifndef ROQUELITE_EM_C_MAPA_H
#define ROQUELITE_EM_C_MAPA_H

PECA** criaMapaPecas();

/*void desenhaMapa();

void desenhaPainelInformacoes();

void desenhaMenuFinal();

void desenhaJogador (ENTIDADE* jogador);

void desenhaMonstro (ENTIDADE* monstro);

void desenhaJogo();*/

POSICAO constroiSalasMapa();

SALA criaSala (int y, int x, int altura, int largura, int numero_monstros);

void adicionaSalaMapa (SALA novaSala);

void connectaCentroSalas (POSICAO centro1, POSICAO centro2);

void freeMap();

COMIDA* criaComida(SALA novaSala);

ARMADILHA* criaArmadilha (SALA novaSala);

#endif //ROQUELITE_EM_C_MAPA_H
