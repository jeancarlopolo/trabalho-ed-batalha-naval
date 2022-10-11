
#include "retangulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "barco.h"

struct Retangulo
{
    int id;
    float x;
    float y;
    float w;
    float h;
    string cor;
    string corb;
};

Retangulo create_retangulo(int id, float x, float y, float w, float h, string corb, string corp)
{
    Retangulo ret = (Retangulo)malloc(sizeof(struct Retangulo));
    retangulo_set_i(ret, id);
    retangulo_set_x(ret, x);
    retangulo_set_y(ret, y);
    retangulo_set_w(ret, w);
    retangulo_set_h(ret, h);
    retangulo_set_corb(ret, corb);
    retangulo_set_corp(ret, corp);
    return ret;
};

void retangulo_set_i(Retangulo ret, int i)
{
    struct Retangulo *ponteiro = ret;
    ponteiro->id = i;
};

void retangulo_set_x(Retangulo ret, float x)
{
    struct Retangulo *ponteiro = ret;
    ponteiro->x = x;
};

void retangulo_set_y(Retangulo ret, float y)
{
    struct Retangulo *ponteiro = ret;
    ponteiro->y = y;
};

void retangulo_set_w(Retangulo ret, float w)
{
    struct Retangulo *ponteiro = ret;
    ponteiro->w = w;
};

void retangulo_set_h(Retangulo ret, float h)
{
    struct Retangulo *ponteiro = ret;
    ponteiro->h = h;
};

void retangulo_set_corb(Retangulo ret, string corb)
{
    struct Retangulo *ponteiro = ret;
    ponteiro->corb = corb;
};

void retangulo_set_corp(Retangulo ret, string corp)
{
    struct Retangulo *ponteiro = ret;
    ponteiro->cor = corp;
};

int retangulo_get_i(Retangulo ret)
{
    struct Retangulo *ponteiro = ret;
    return ponteiro->id;
};

float retangulo_get_x(Retangulo ret)
{
    struct Retangulo *ponteiro = ret;
    return ponteiro->x;
};

float retangulo_get_y(Retangulo ret)
{
    struct Retangulo *ponteiro = ret;
    return ponteiro->y;
};

float retangulo_get_w(Retangulo ret)
{
    struct Retangulo *ponteiro = ret;
    return ponteiro->w;
};

float retangulo_get_h(Retangulo ret)
{
    struct Retangulo *ponteiro = ret;
    return ponteiro->h;
};

string retangulo_get_corb(Retangulo ret)
{
    struct Retangulo *ponteiro = ret;
    return ponteiro->corb;
};

string retangulo_get_corp(Retangulo ret)
{
    struct Retangulo *ponteiro = ret;
    return ponteiro->cor;
};

void retangulo_free(Retangulo ret)
{
    free(ret);
};

//o resto depende de outros conceitos, como: nível de proteção, pontuação, etc.