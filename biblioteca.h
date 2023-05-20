
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
typedef struct Posição
{
    int y;
    int x;
} POSICAO;

/* Estrutura do Jogador */
typedef struct Entidade 
{
    POSICAO pos;
    char imagem;
    int cor;
    int vida;
    int combate;
    int defende;

} ENTIDADE;

/*Estrutura das peças do mapa. */
typedef struct Peça
{
    char imagem;
    int  cor;    

    bool podeAndar;
    bool transparente;
    bool visivel;
    bool visto;

} PECA;

/* Estrutura das SALAs do mapa */
typedef struct Sala
{
    int altura;
    int largura;
    
    POSICAO pos;
    POSICAO centro;
    POSICAO comida;

    ENTIDADE *monstro;

} SALA;


/* Funcionalidades da biblioteca ncurses */

bool cursorSetup();

void cicloJogo();

void fimJogo ();

void desenhaMenu();

/* Funcionalidades do Jogador */

ENTIDADE* criaJogador (POSICAO pos_inicial);

void direcao (int tecla);

void adicionaVida(POSICAO nova_pos, int valor);

void movimentaJogador (POSICAO novaPos);

void modificaEstadoPeca (ENTIDADE* jogador);

void estadoNormalPeca (ENTIDADE* jogador);

bool posicaoDentroMapa (int y, int x);

int levaDistancia (POSICAO POSICAO1, POSICAO POSICAO2);

bool linhaVisao (POSICAO origin, POSICAO target);

int conheceSinal (int a);


/* Funcionalidades do Mapa */

PECA** criaMapaPecas();

void desenhaMapa();

void desenhaPainelInformacoes();

void desenhaJogador (ENTIDADE* jogador);

void desenhaMonstro (ENTIDADE* monstro);

void desenhaJogo();

POSICAO constroiSalasMapa();

SALA criaSala (int y, int x, int altura, int largura, ENTIDADE *monstro);

void adicionaSalaMapa (SALA SALA, ENTIDADE *monstro, int numero_monstros);

void connectaCentroSalas (POSICAO centro1, POSICAO centro2);

void freeMap();

/* Funcionalidades do Monstro */

ENTIDADE* criaMonstro (POSICAO pos_inicial);

ENTIDADE* adicionaMonstros();

void adicionaMonstroSALA (SALA SALA);

bool POSICAODentroSALA (POSICAO POSICAO, SALA SALA);

POSICAO POSICAO_aleatoria ();

//POSICAO movimenta_frente (POSICAO origem, POSICAO destino);

//void movimentaMonstro(POSICAO nova_pos, ENTIDADE* monstro);

//bool consegue_ver (ENTIDADE* monstro, ENTIDADE* jogador);


/*Variáveis globais e constantes*/
extern const int MAP_HEIGHT;

extern const int MAP_WIDTH;

/*Variável global*/
extern PECA** mapa;

/* Declarei esta varável usando o 'extern' porque é uma variável global e e vai ser usada em diversos ficheiros.*/
extern ENTIDADE* jogador;

#endif //DEBUG_BIBLIOTECA_H
