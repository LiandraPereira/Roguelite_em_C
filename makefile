CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2
LIBS = -lm -lcurses

jogo: main.c engine.c desenha.c salas.c mapa.c visao.c jogador.c monstro.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f jogo *.o

run: jogo 
	./jogo