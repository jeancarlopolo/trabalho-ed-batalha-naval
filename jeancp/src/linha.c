#include "linha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "barco.h"

struct Linha
{
    int id;
    float x1;
    float y1;
    float x2;
    float y2;
    string cor;
};

Linha create_linha(int id, float x1, float y1, float x2, float y2, string cor)
{
    Linha li = (Linha)malloc(sizeof(struct Linha));
    linha_set_i(li, id);
    linha_set_x1(li, x1);
    linha_set_y1(li, y1);
    linha_set_x2(li, x2);
    linha_set_y2(li, y2);
    linha_set_cor(li, cor);
    return li;
}

void linha_set_i(Linha li, int i)
{
    struct Linha *ponteiro = li;
    ponteiro->id = i;
}

void linha_set_x1(Linha li, float x1)
{
    struct Linha *ponteiro = li;
    ponteiro->x1 = x1;
}

void linha_set_y1(Linha li, float y1)
{
    struct Linha *ponteiro = li;
    ponteiro->y1 = y1;
}

void linha_set_x2(Linha li, float x2)
{
    struct Linha *ponteiro = li;
    ponteiro->x2 = x2;
}

void linha_set_y2(Linha li, float y2)
{
    struct Linha *ponteiro = li;
    ponteiro->y2 = y2;
}

void linha_set_cor(Linha li, string cor)
{
    struct Linha *ponteiro = li;
    ponteiro->cor = cor;
}

int linha_get_i(Linha li)
{
    struct Linha *ponteiro = li;
    return ponteiro->id;
}

float linha_get_x1(Linha li)
{
    struct Linha *ponteiro = li;
    return ponteiro->x1;
}

float linha_get_y1(Linha li)
{
    struct Linha *ponteiro = li;
    return ponteiro->y1;
}

float linha_get_x2(Linha li)
{
    struct Linha *ponteiro = li;
    return ponteiro->x2;
}

float linha_get_y2(Linha li)
{
    struct Linha *ponteiro = li;
    return ponteiro->y2;
}

string linha_get_cor(Linha li)
{
    struct Linha *ponteiro = li;
    return ponteiro->cor;
}

void linha_free(Linha li)
{
    free(li);
}

