//
// Created by liandrapereira on 27-04-2023.
//

#ifndef DEBUG_BIBLIOTECA_H
#define DEBUG_BIBLIOTECA_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

/* CORES */
#define COR_VISIVEL 1
#define COR_VISTA 2

/* Estrutura das coordenadas do jogador */
typedef struct{
    int y;
    int x;
} Posicao;

/* Estrutura do Jogador */
typedef struct{
    Posicao pos;
    char imagem;
    int cor;
} Jogador;

/*Estrutura das peças do mapa. */
typedef struct{
    char imagem;
    int  cor;
    bool podeAndar;
    bool transparente;
    bool visivel;
    bool vista;
} Peca;

/* Estrutura das salas do mapa */
typedef struct {
    int altura;
    int largura;
    Posicao pos;
    Posicao centro;
} Sala;


/* Funcionalidades da biblioteca ncurses */

bool cursesSetup();

void gameLoop();

void closeGame ();

/* Funcionalidades do Jogador */

Jogador* criaJogador (Posicao pos_inicial);

void direcao (int tecla);

void movimentaJogador (Posicao novaPos);

void modificaEstadoPeca (Jogador* jogador);

void estadoNormalPeca (Jogador* jogador);

bool dentroMapa (int y, int x);

int levaDistancia (Posicao posicao1, Posicao posicao2);

bool linhaVisao (Posicao origin, Posicao target);

int conheceSinal (int a);


/* Funcionalidades do Mapa */

Peca** criaMapaPecas();

void desenhaMapa();

void desenhaJogador (Jogador* jogador);

void desenhaAmbos();

Posicao setupMap();

Sala criaSala (int y, int x, int altura, int largura);

void adicionaSalaMapa (Sala sala);

void connectaCentroSalas (Posicao centro1, Posicao centro2);

void freeMap();


/*Variáveis globais e constantes*/
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;

/*Variável global*/
extern Peca** mapa;

/* Declarei esta varável usando o 'extern' porque é uma variável global e e vai ser usada em diversos ficheiros.*/
extern Jogador* jogador;

#endif //DEBUG_BIBLIOTECA_H
