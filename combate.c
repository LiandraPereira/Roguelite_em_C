#include <stdio.h>
#include <ncurses.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


#define Q 81 // ASCII for Q
#define C 67
#define W 87
#define A 65
#define S 83
#define D 68

typedef struct {
    char nome[20];
    int max_hp;
    int hp_atual;
    int potencia_do_ataque;
    int defesa;
    char monstro_tipo[20];
    int x;
    int y;
} Monstro;

//implementação da faca
typedef struct {
    char nome[20];
    int potencia_do_ataque;
} Faca;


//implementação da espada
typedef struct {
    char nome[20];
    int potencia_do_ataque;
} Espada;

typedef struct {
    char nome[20];
    int vida;
    int x;
    int y;
} Jogador;

void ataque_monstro(Monstro *atacante, Monstro *alvo) { //criar um valor para o ataque
    int dano_ataque = rand() % (atacante->potencia_do_ataque + 1);
    int dano_real_ataque = dano_ataque - alvo->defesa; //definição do dano real
    if (dano_real_ataque < 0) {
        dano_real_ataque = 0;
    }
    //dano tido pelo alvo
    alvo->hp_atual -= dano_real_ataque;
    if (alvo->hp_atual < 0) {
        alvo->hp_atual = 0;
    }
    mvprintw(4, 0, "%s ataca %s por %d dano!\n", atacante->nome, alvo->nome, dano_real_ataque);
    mvprintw(6, 0, "%s's HP: %d", alvo->nome, alvo->hp_atual);
    refresh();
}
double calcula_distancia(int x1, int y1, int x2, int y2){ //calcular a distância usando os pontos das coordenadas
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
void perseguicao(Monstro *monstro, int jogador_x, int jogador_y){ //dados de perseguição do monstro
    double distancia = calcula_distancia(monstro->x, monstro->y, jogador_x, jogador_y);//calcula a distancia entre o monstro e o jogador

    if (distancia > 1){//se a distancia for maior que 1, aproximar-se do jogador
        //calcula o movimento da direção
        int dx = (int)round((jogador_x - monstro->x)/ distancia);
        int dy = (int)round((jogador_y - monstro->y)/ distancia);

        monstro->y += dy; //atualizar a localização do monstro
        monstro->x += dx;
    }
}

int main() {// gerador de número
    srand(time(NULL));

    Jogador jogador = {"Jogador", 100, 100, 10, 5, "Humano", 10, 10 };
    Monstro goblin = {"Goblin", 30, 30, 6, 2, "Pequeno", 5, 5};

    Espada espada_jogador = { "Espada", 8};
    Faca faca_jogador = { "Faca", 5};

    int ch;

    //começar ncurses
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();


    printw("%s encontra um %s selvagem %s!\n", jogador.nome, goblin.monstro_tipo, goblin.nome);
    refresh();
    getch();

    while (jogador.vida > 0 && goblin.hp_atual > 0){

        ataque_monstro(&goblin, &jogador); //ataque do monstro

        printw("\nClique na tecla 'f' para atacar com uma faca e 'e' para atacar com uma espada. \n" )
        refresh();
        ch = getch();

        if (ch == 'f' || ch == 'F') {
            printw("\n%s ataca %s com uma %d!\n", jogador.nome, goblin.nome, faca_jogador.nome);
            refresh();
            getch();

            int dano_faca = faca_jogador.potencia_do_ataque; //dano da faca
            goblin.hp_atual -= dano_faca;
            if (goblin.hp_atual < 0) {
                goblin.hp_atual = 0;
            }
            mvprintw(8, 0, "%s's HP: %d", jogador.nome, jogador.vida);
            refresh();
            getch();
        }
        else if (ch == 'e' || ch == 'E'){
            printw("\n%s ataca %s com uma %s!\n", jogador.nome, goblin.nome, espada_jogador.nome);
            refresh();
            getch();

            int dano_espada = espada_jogador.potencia_do_ataque; //dano da espada
            goblin.hp_atual -= dano_espada;
            if (goblin.hp_atual < 0){
                goblin.hp_atual = 0;
            }
            mvprintw(10, 0, "%s's HP: %d", goblin.nome, goblin.hp_atual);
            refresh();
            getch();
        } else{
            printw("\n Seleção Inválida! \n");
            refresh();
            getch();
        }
        printw("\nMovimento do jogador: use W, A, S, D para mover ou 'q' para terminar o jogo.\n");
        refresh();
        ch = getch();

        if (ch == 'W' || ch == 'w'){
            jogador.y--;
        }
        else if (ch == 'S' ||ch == 's'){
            jogador.y++;
        }
        else if (ch == 'A' || ch =='a'){
            jogador.x--;
        }
        else if (ch == 'D' || ch == 'd'){
            jogador.x++;
        }
        else if (ch == 'q' || ch == 'Q'){
            break;
        }
        perseguicao(&goblin, jogador.x, jogador.y);
    }


    endwin();//exit ncurses and clean up

    return 0;
}