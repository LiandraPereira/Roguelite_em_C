#include <math.h>
#include "biblioteca.h"

void modificaEstadoPeca (Jogador* jogador)
{
    int y, x, distance;
    int RADIUS = 15;
    Posicao target;

    mapa[jogador->pos.y][jogador->pos.x].visivel = true;
    mapa[jogador->pos.y][jogador->pos.x].vista = true;

    for (y = jogador->pos.y - RADIUS; y < jogador->pos.y + RADIUS; y++)
    {
        for (x = jogador->pos.x - RADIUS; x < jogador->pos.x + RADIUS; x++)
        {
            target.y = y;
            target.x = x;
            distance = levaDistancia(jogador->pos, target);

            if (distance < RADIUS)
            {
                if (dentroMapa(y, x) && linhaVisao(jogador->pos, target))
                {
                    mapa[y][x].visivel = true;
                    mapa[y][x].vista = true;
                }
            }
        }
    }
}

void estadoNormalPeca(Jogador* jogador)
{
    int y, x;
    int RADIUS = 15;

    for (y = jogador->pos.y - RADIUS; y < jogador->pos.y + RADIUS; y++)
    {
        for (x = jogador->pos.x - RADIUS; x < jogador->pos.x + RADIUS; x++)
        {
            if (dentroMapa(y, x))
                mapa[y][x].visivel = false;
        }
    }
}

int levaDistancia(Posicao origin, Posicao target)
{
    double dy, dx;
    int distance;
    dx = target.x - origin.x;
    dy = target.y - origin.y;
    distance = floor(sqrt((dx * dx) + (dy * dy)));

    return distance;
}

bool dentroMapa(int y, int x)
{
    if ((0 < y && y < MAP_HEIGHT - 1) && (0 < x && x < MAP_WIDTH - 1))
    {
        return true;
    }

    return false;
}

bool linhaVisao(Posicao origin, Posicao target)
{
    int t, x, y, abs_delta_x, abs_delta_y, sign_x, sign_y, delta_x, delta_y;

    delta_x = origin.x - target.x;
    delta_y = origin.y - target.y;

    abs_delta_x = abs(delta_x);
    abs_delta_y = abs(delta_y);

    sign_x = conheceSinal(delta_x);
    sign_y = conheceSinal(delta_y);

    x = target.x;
    y = target.y;

    if (abs_delta_x > abs_delta_y)
    {
        t = abs_delta_y * 2 - abs_delta_x;

        do
        {
            if (t >= 0)
            {
                y += sign_y;
                t -= abs_delta_x * 2;
            }

            x += sign_x;
            t += abs_delta_y * 2;

            if (x == origin.x && y == origin.y)
            {
                return true;
            }
        }
        while (mapa[y][x].transparente);

        return false;
    }
    else
    {
        t = abs_delta_x * 2 - abs_delta_y;

        do
        {
            if (t >= 0)
            {
                x += sign_x;
                t -= abs_delta_y * 2;
            }

            y += sign_y;
            t += abs_delta_x * 2;

            if (x == origin.x && y == origin.y)
            {
                return true;
            }
        }
        while (mapa[y][x].transparente);

        return false;
    }
}

int conheceSinal(int a)
{
    return (a < 0) ? -1 : 1;
}