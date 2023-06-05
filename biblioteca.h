
#ifndef DEBUG_BIBLIOTECA_H
#define DEBUG_BIBLIOTECA_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

/* CORES */
#define COR_VISIVEL 7    //
#define COR_VISTA 3      //
#define COR_MONSTRO 1    //
#define COR_COMIDA 2     //
#define COR_ARMADILHA 4  //

/* Estrutura das coordenadas do jogador */
typedef struct Posicao
{
    int y;
    int x;

} POSICAO;

/* Estrutura do objeto */
typedef struct objeto
{
    char imagem;
    int cor;
    
    POSICAO posicao;
} OBJETO;

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
    bool vista;


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

typedef struct GameInfo{
    int nComidas;
    int nArmadilhas;
    int nMonstros;
    int tempoInicial;
} GAMEINFO;


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

/*Variavel global que mantem informacoes sobre o jogo atual*/
extern GAMEINFO game_info;

#endif //DEBUG_BIBLIOTECA_H