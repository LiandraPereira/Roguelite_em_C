
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
    int movimentos;
    int vitorias;
    int raio;

    POSICAO pos;

} ENTIDADE;

/*Estrutura das peças do mapa. */
typedef struct Peca
{
    char imagem;
    int  cor;

    bool podeAndar;
    bool transparente;
    bool visivel;
    bool visto;


    ENTIDADE perigo;

} PECA;

/* Estrutura das salas do mapa */
typedef struct Sala
{
    int altura;
    int largura;
    int numero_monstros;

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

void desenhaMapa();

void desenhaPainelInformacoes();

void desenhaMenuFinal();

void desenhaJogador (ENTIDADE* jogador);

void desenhaJogo();

/* Variáveis globais e constantes*/
extern const int MAP_HEIGHT;

extern const int MAP_WIDTH;

/*Variáveis globais*/
extern PECA** mapa;

extern ENTIDADE *jogador;

#endif //DEBUG_BIBLIOTECA_H
