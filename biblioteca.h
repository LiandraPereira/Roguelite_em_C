/**
 * @file biblioteca.h
 *
 * Neste ficheiro estão contidos os protótipos do módulo biblioteca.c
 */

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#ifndef DEBUG_BIBLIOTECA_H
#define DEBUG_BIBLIOTECA_H

/* CORES */
#define COR_VISIVEL 7    
#define COR_VISTA 3      
#define COR_MONSTRO 5    
#define COR_COMIDA 2     
#define COR_ARMADILHA 1 
#define COR_JOGADOR 6     
#define COR_MORTO 1 

/**
 * @brief Definição da estrutura da Posição.
 */
typedef struct Posicao
{
    int y;
    int x;

} POSICAO;

/**
 * @brief Definição da estrutura do objeto.
 */
typedef struct Objeto
{
    char imagem;
    int cor;
    
    POSICAO posicao;
} OBJETO;

/**
 * @brief Definição da estrutura da Entidade.
 */
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

/**
 * @brief Definiçãoda da estrutura da Peça.
 */
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

/**
 * @brief Definição da estrutura da Sala.
 */
typedef struct Sala
{
    int altura;
    int largura;
    int numero_monstros;

    POSICAO pos;
    POSICAO centro;
    POSICAO comida;

    ENTIDADE *monstro; 

} SALA;

/**
 * @brief Definição da estrutura da GameInfo.
 */
typedef struct GameInfo
{
    int nComidas;
    int nArmadilhas;
    int nMonstros;
    int tempoInicial;

} GAMEINFO;

/**
 * @brief Definição dos protótipos do módulo engine.c
*/

bool cursorSetup();

void cicloJogo();

void reiniciaJogo();

void fimJogo ();

/**
 * @brief Definição dos protótipos do módulo desenha.c
*/

void desenhaMenu();

void desenhaMapa();

void desenhaPainelInformacoes();

void desenhaMenuFinal();

void desenhaJogador (ENTIDADE* jogador);

void desenhaJogo();

/**
 * @brief Declaração das variáveis globais e constantes.
*/

extern const int MAP_HEIGHT;

extern const int MAP_WIDTH;

/**
 * @brief Declaração das variáveis globais.
*/
extern PECA** mapa;

extern ENTIDADE *jogador;

extern GAMEINFO game_info;

#endif //DEBUG_BIBLIOTECA_H