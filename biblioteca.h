
#ifndef DEBUG_BIBLIOTECA_H
#define DEBUG_BIBLIOTECA_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

/* CORES */
#define COR_VISIVEL 7
#define COR_VISTA 3
#define COR_MONSTRO 1
#define COR_COMIDA 2 
#define COR_ARMADILHA 4

/* Velocidades */
#define V_MONSTRO 1 // velocidade do monstro
#define V_JOGADOR 2

/* Estrutura das coordenadas do jogador */
typedef struct Posicao
{
    int y;
    int x;

} POSICAO;

/*Estrutura para as comidas*/
typedef struct comida
{
    char imagem;
    int cor;
    
    POSICAO posicao;

} COMIDA;

typedef struct armadilha
{
    char imagem;
    int cor;
    
    POSICAO posicao;

} ARMADILHA;

/* Estrutura do Jogador */
typedef struct Entidade 
{
    char imagem;
    int cor;
    int vida;
    int combate;
    int defende;
    int movimentos;

    POSICAO pos;

    //ENTIDADE *monstro;


} ENTIDADE;

typedef struct Monstro
{   
    int numero_monstros;

    ENTIDADE *lista;

} MONSTRO;



/*Estrutura das peças do mapa. */
typedef struct Peca
{
    char imagem;
    int  cor;

    bool podeAndar;
    bool transparente;
    bool visivel;
    bool visto;

} PECA;

/* Estrutura das salas do mapa */
typedef struct Sala
{
    int altura;
    int largura;
    int monstros;

    POSICAO pos;
    POSICAO centro;
    POSICAO comida;

    ENTIDADE *monstro; // Apontador para a lista de monstros da sala 

} SALA;


/* Funcionalidades da biblioteca ncurses */

bool cursorSetup();

void cicloJogo();

void reiniciaJogo();

void fimJogo ();

void desenhaMenu();

void desenhaMensagemTemporaria(char *mensagem, int duracao);

/* Funcionalidades do Jogador */

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


/* Funcionalidades do Mapa */

PECA** criaMapaPecas();

void desenhaMapa();

void desenhaPainelInformacoes();

void desenhaMenuFinal();

void desenhaJogador (ENTIDADE* jogador);

void desenhaMonstro (ENTIDADE* monstro);

void desenhaJogo();

POSICAO constroiSalasMapa();

SALA criaSala (int y, int x, int altura, int largura, int numero_monstros);

void adicionaSalaMapa (SALA novaSala);

void connectaCentroSalas (POSICAO centro1, POSICAO centro2);

void freeMap();

COMIDA* criaComida(SALA novaSala);

ARMADILHA* criaArmadilha (SALA novaSala);

/* Funcionalidades do Monstro */

ENTIDADE criaMonstro (int y, int x, ENTIDADE monstro);

void adicionaMonstroSala (SALA novaSala);

void combate (SALA sala, POSICAO posicao);

/*Variáveis globais e constantes*/
extern const int MAP_HEIGHT;

extern const int MAP_WIDTH;

/*Variável global*/
extern PECA** mapa;

/* Declarei esta varável usando o 'extern' porque é uma variável global e e vai ser usada em diversos ficheiros.*/
extern ENTIDADE *jogador;

#endif //DEBUG_BIBLIOTECA_H
