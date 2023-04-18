cmake_minimum_required(VERSION 3.25)
project(Roquelite_em_C C)

set(CMAKE_C_STANDARD 11)

add_executable(Roquelite_em_C main.c mapa.c mapa.h jogador.c jogador.h monstro.c combate.c combate.h monstro.h)
