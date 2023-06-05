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
                if (mapa[y][x].imagem == 'o') //Comida
                {   
                    attron(COLOR_PAIR(COR_COMIDA));
                    mvaddch(y, x, mapa[y][x].imagem);
                    attroff(COLOR_PAIR(COR_COMIDA));
                }
                else if (mapa[y][x].imagem == '^') //Armadilha
                {
                    attron(COLOR_PAIR(COR_ARMADILHA));
                    mvaddch(y, x, mapa[y][x].imagem);
                    attroff(COLOR_PAIR(COR_ARMADILHA));
                }
                else if (mapa[y][x].imagem == 'M') //Monstro
                {
                    if (mapa[y][x].perigo.vida == 10){
                        attron(COLOR_PAIR(COR_VISTA));
                        mvaddch(y, x, mapa[y][x].imagem);
                        attroff(COLOR_PAIR(COR_VISTA));
                    } else if (mapa[y][x].perigo.vida <= 10){
                        attron(COLOR_PAIR(COR_MONSTRO));
                        mvaddch(y, x, mapa[y][x].imagem);
                        attroff(COLOR_PAIR(COR_MONSTRO));
                    } else {
                        attron(COLOR_PAIR(COR_MORTO));
                        mvaddch(y, x, mapa[y][x].imagem);
                        attroff(COLOR_PAIR(COR_MORTO));

                    }

                } 
                else
                {
                    attron(COLOR_PAIR(COR_VISIVEL));
                    mvaddch(y, x, mapa[y][x].imagem);
                    attroff(COLOR_PAIR(COR_VISIVEL));
                }
            }
            else if (mapa[y][x].vista)
            {
                attron(COLOR_PAIR(COR_VISTA));
                mvaddch(y, x, mapa[y][x].imagem);
                attroff(COLOR_PAIR(COR_VISTA));
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
    attron(jog->cor);
    mvaddch(jog->pos.y, jog->pos.x, jog->imagem);
    attroff(jog->cor);
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
 * \brief Desenha o Menu Inicial quando o jogo é iniciado
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
    attroff(A_BOLD);  
    refresh();  
}

/**
 * \brief Desenha o Menu Final com as informações sobre o jogo e com a opção de reiniciar
*/
void desenhaMenuFinal()
{
    clear();
    refresh();
    
    int altura = 15;
    int largura = 60;
    int inicioY = (LINES - altura) / 2;
    int inicioX = (COLS - largura) / 2;

    WINDOW *menuwin = newwin(altura, largura, inicioY, inicioX);
    box(menuwin, 0, 0);

    mvwprintw(menuwin, 1, largura / 2 - 6, "Fim do Jogo!");
    mvwprintw(menuwin, 3, 2, "-Terminou o jogo com %d de Vida.", jogador->vida);
    mvwprintw(menuwin, 5, 2, "-Matou %d Monstros.", jogador->vitorias);
    mvwprintw(menuwin, 7, 2, "-Fez %d Movimentos.", jogador->movimentos);
    mvwprintw(menuwin, altura - 6, largura / 2 - 15, "Pressione Enter para reiniciar");
    mvwprintw(menuwin, altura - 4, largura / 2 - 1, "Ou");
    mvwprintw(menuwin, altura - 2, largura / 2 - 11, "Pressione Q para sair");

    wrefresh(menuwin);
    
    int tecla;
    while ((tecla = getch())) 
    {
        if (tecla == '\n') // Reiniciar o jogo
        {  
            reiniciaJogo();
        } 
        if(tecla == 'q' || tecla == 'Q')  // Sair do jogo
        {
            fimJogo();
        }   
        
    }
}