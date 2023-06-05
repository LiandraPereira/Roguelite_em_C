
#ifndef ROQUELITE_EM_C_JOGADOR_H
#define ROQUELITE_EM_C_JOGADOR_H

ENTIDADE* criaJogador (POSICAO pos_inicial);

void direcao (int tecla);

void adicionaVida(POSICAO nova_pos, int valor);

void pisouArmadilha(POSICAO nova_pos, int dano);

void movimentaJogador (POSICAO novaPos);

void modificaEstadoPeca (ENTIDADE* jogador);

void estadoNormalPeca (ENTIDADE* jogador);

bool posicaoDentroMapa (int y, int x);

int levaDistancia (POSICAO POSICAO1, POSICAO POSICAO2);

bool linhaVisao (POSICAO origin, POSICAO target);

int conheceSinal (int a);

#endif //ROQUELITE_EM_C_JOGADOR_H
