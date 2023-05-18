CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2
LIBS = -lm -lncurses

jogo: main.c engine.c desenha.c salas.c mapa.c visao.c jogador.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm jogo *.o
