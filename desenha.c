#include "biblioteca.h"


/**
 * \brief Desenha o mapa.
*/
void desenhaMapa()
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if (mapa[y][x].visivel)
            {
                mvaddch(y, x, mapa[y][x].imagem | mapa[y][x].imagem);
            }
            else if (mapa[y][x].visto)
            {
                mvaddch(y, x, mapa[y][x].imagem | COLOR_PAIR(COR_VISTA));
            }
            else
            {
                mvaddch(y, x, ' ');
            }
        }
    }
}

/**
 * \brief Desenha o jogador.
*/
void desenhaJogador(ENTIDADE* jog)
{
    mvaddch(jog->pos.y, jog->pos.x, jog->imagem | jog->cor);
}

/**
 * \brief Desenha o monstro. 
*/
void desenhaMonstro (ENTIDADE* monstro)
{   
    mvaddch(monstro->pos.y, monstro->pos.x, monstro->imagem | monstro->cor);
}

/**
 * \brief Desenha o jogo.
*/
void desenhaJogo()
{   
    clear();
    desenhaMapa();
    desenhaPainelInformacoes();
    desenhaJogador(jogador);
}

/**
 * \brief 
*/
void desenhaMenu() {
    clear(); 
    refresh(); 
    int altura = 18;
    int larg = 80;
    int inicioY = (LINES - altura) / 2;
    int inicioX = (COLS - larg) / 2;
    
    WINDOW *menuwin = newwin(altura, larg, inicioY, inicioX );
    box(menuwin, 0, 0);
    
    mvwprintw(menuwin, 1, larg/2 -6, "Roguelite"); 
    mvwprintw(menuwin, 4, 2, "-O objetivo do jogo é matar todos os monstros sem morrer primeiro.");
    mvwprintw(menuwin, 6, 2, "Controles:");
    mvwprintw(menuwin, 7, 4, "8426/'wasd' - Move e ataca.");
    mvwprintw(menuwin, 8, 4, "'q' - Sai do jogo.");
    mvwprintw(menuwin, 10, 2, "Instruções:");
    mvwprintw(menuwin, 11, 4, "@ - Jogador");
    mvwprintw(menuwin, 12, 4, "M - Monstros");
    mvwprintw(menuwin, 13, 4, "O - Comidas (Vida)");
    mvwprintw(menuwin, altura-2, larg/2 - 15, "Pressione Enter para iniciar.");
    
    wrefresh(menuwin); 
    while (getch() != '\n'){}
    delwin(menuwin);
}

void desenhaPainelInformacoes(){
    for (int y = 0; y < LINES; y++)
    {
        mvaddch(y, COLS - 32, '|');
    }

    attron(A_BOLD);
    mvprintw(LINES/2 - 2, COLS - 26, "Vida do Jogador: %d", jogador->vida);
    mvprintw(LINES/2, COLS - 26, "Inimigos Restantes: ");
    mvprintw(LINES/2 + 2, COLS - 26, "Dano: %d", jogador->combate);
    attroff(A_BOLD);  
    refresh();  
}