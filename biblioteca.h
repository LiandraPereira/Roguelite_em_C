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
#define COR_VISIVEL 7
#define COR_VISTA 3
#define COR_MONSTRO 1
#define COR_COMIDA 2 

/* Velocidades */
#define V_MONSTRO 1 // velocidade do monstro
#define V_JOGADOR 2

/* Estrutura das coordenadas do jogador */
typedef struct Coordenadas
{
    int y;
    int x;

} Posicao;

/* Estrutura do Jogador */
typedef struct 
{
    Posicao pos;
    char imagem;
    int cor;
    int vida;
    int combate;
    int defende;

} Entidade;

/*Estrutura das peças do mapa. */
typedef struct Celula 
{
    char imagem;
    int  cor;    

    // Estado de cada peça

    bool podeAndar;
    bool transparente;
    bool visivel;
    bool vista;

} Peca;

/* Estrutura das salas do mapa */
typedef struct 
{
    int altura;
    int largura;
    Posicao pos;
    Posicao centro;
    Posicao comida;
    Entidade *monstro;

} Sala;


/* Funcionalidades da biblioteca ncurses */

bool cursorSetup();

void cicloJogo();

void fimJogo ();

void desenhaMenu();

/* Funcionalidades do Jogador */

Entidade* criaJogador (Posicao pos_inicial);

void direcao (int tecla);

void adicionaVida(Posicao nova_pos, int valor);

void movimentaJogador (Posicao novaPos);

void modificaEstadoPeca (Entidade* jogador);

void estadoNormalPeca (Entidade* jogador);

bool posicaoDentroMapa (int y, int x);

int levaDistancia (Posicao posicao1, Posicao posicao2);

bool linhaVisao (Posicao origin, Posicao target);

int conheceSinal (int a);


/* Funcionalidades do Mapa */

Peca** criaMapaPecas();

void desenhaMapa();

void desenhaJogador (Entidade* jogador);

void desenhaMonstro (Entidade* monstro);

void desenhaJogo();

Posicao constroiSalasMapa();

Sala criaSala (int y, int x, int altura, int largura, Entidade *monstro);

void adicionaSalaMapa (Sala sala, Entidade *monstro, int numero_monstros);

void connectaCentroSalas (Posicao centro1, Posicao centro2);

void freeMap();

/* Funcionalidades do Monstro */

Entidade* criaMonstro (Posicao pos_inicial);

Entidade* adicionaMonstros();

void adicionaMonstroSala (Sala sala);

bool posicaoDentroSala (Posicao posicao, Sala sala);

Posicao posicao_aleatoria ();

/*Variáveis globais e constantes*/
extern const int MAP_HEIGHT;

extern const int MAP_WIDTH;

/*Variável global*/
extern Peca** mapa;

/* Declarei esta varável usando o 'extern' porque é uma variável global e e vai ser usada em diversos ficheiros.*/
extern Entidade* jogador;

#endif //DEBUG_BIBLIOTECA_H
