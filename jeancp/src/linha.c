#include "linha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "barco.h"

struct Line
{
    int id;
    float x1;
    float y1;
    float x2;
    float y2;
    string cor;
    int hp;
    int np;
};

Barco create_linha(int id, float x1, float y1, float x2, float y2, string cor)
{
    struct Line *li = malloc(sizeof(struct Line));
    Barco bar = createBarco('l', li);
    linha_set_i(li, id);
    linha_set_x1(li, x1);
    linha_set_y1(li, y1);
    linha_set_x2(li, x2);
    linha_set_y2(li, y2);
    linha_set_cor(li, cor);
    li->hp = 1;
    li->np = 50;
    return bar;
}

void linha_set_i(Barco li, int i)
{
    Item info = li;
    getInfo(li, info);
    struct Line *ponteiro = info;
    ponteiro->id = i;
}

void linha_set_x1(Barco li, float x1)
{
    Item info = li;
    getInfo(li, info);
    struct Line *ponteiro = info;
    ponteiro->x1 = x1;
}

void linha_set_y1(Barco li, float y1)
{
    Item info = li;
    getInfo(li, info);
    struct Line *ponteiro = info;
    ponteiro->y1 = y1;
}

void linha_set_x2(Barco li, float x2)
{
    Item info = li;
    getInfo(li, info);
    struct Line *ponteiro = info;
    ponteiro->x2 = x2;
}

void linha_set_y2(Barco li, float y2)
{
    Item info = li;
    getInfo(li, info);
    struct Line *ponteiro = info;
    ponteiro->y2 = y2;
}

void linha_set_cor(Barco li, string cor)
{
    Item info = li;
    getInfo(li, info);
    struct Line *ponteiro = info;
    char corstring[20];
    strcpy(corstring, cor);
    ponteiro->cor = corstring;
}

int linha_get_i(Barco li)
{
    Item info = li;
    getInfo(li, info);
    struct Line *ponteiro = info;
    return ponteiro->id;
}

float linha_get_x1(Barco li)
{
    Item info = li;
    getInfo(li, info);
    struct Line *ponteiro = info;
    return ponteiro->x1;
}

float linha_get_y1(Barco li)
{
    Item info = li;
    getInfo(li, info);
    struct Line *ponteiro = info;
    return ponteiro->y1;
}

float linha_get_x2(Barco li)
{
    Item info = li;
    getInfo(li, info);
    struct Line *ponteiro = info;
    return ponteiro->x2;
}

float linha_get_y2(Barco li)
{
    Item info = li;
    getInfo(li, info);
    struct Line *ponteiro = info;
    return ponteiro->y2;
}

string linha_get_cor(Barco li)
{
    Item info = li;
    getInfo(li, info);
    struct Line *ponteiro = info;
    return ponteiro->cor;
}

void linha_free(Barco li)
{
    free(li);
}
