#include "circulo.h"

struct Circulo
{
    int id;
    float x;
    float y;
    float r;
    string cor;
    string corb;
};

Circulo create_circulo(int id, float x, float y, float r, string corb, string corp)
{
    Circulo cir = (Circulo)malloc(sizeof(struct Circulo));
    circulo_set_i(cir, id);
    circulo_set_x(cir, x);
    circulo_set_y(cir, y);
    circulo_set_r(cir, r);
    circulo_set_corb(cir, corb);
    circulo_set_corp(cir, corp);
    return cir;
}

void circulo_set_i(Circulo cir, int i)
{
    struct Circulo *ponteiro = cir;
    ponteiro->id = i;
}

void circulo_set_x(Circulo cir, float x)
{
    struct Circulo *ponteiro = cir;
    ponteiro->x = x;
}

void circulo_set_y(Circulo cir, float y)
{
    struct Circulo *ponteiro = cir;
    ponteiro->y = y;
}

void circulo_set_r(Circulo cir, float r)
{
    struct Circulo *ponteiro = cir;
    ponteiro->r = r;
}

void circulo_set_corb(Circulo cir, string corb)
{
    struct Circulo *ponteiro = cir;
    ponteiro->corb = corb;
}

void circulo_set_corp(Circulo cir, string corp)
{
    struct Circulo *ponteiro = cir;
    ponteiro->cor = corp;
}

void free_circulo(Circulo cir)
{
    struct Circulo *ponteiro = cir;
    free(ponteiro);
}

int circulo_get_i(Circulo cir)
{
    struct Circulo *ponteiro = cir;
    return ponteiro->id;
}

float circulo_get_x(Circulo cir)
{
    struct Circulo *ponteiro = cir;
    return ponteiro->x;
}

float circulo_get_y(Circulo cir)
{
    struct Circulo *ponteiro = cir;
    return ponteiro->y;
}

float circulo_get_r(Circulo cir)
{
    struct Circulo *ponteiro = cir;
    return ponteiro->r;
}

string circulo_get_corb(Circulo cir)
{
    struct Circulo *ponteiro = cir;
    return ponteiro->corb;
}

string circulo_get_corp(Circulo cir)
{
    struct Circulo *ponteiro = cir;
    return ponteiro->cor;
}

float circulo_get_area(Circulo cir)
{
    struct Circulo *ponteiro = cir;
    return 3.14 * ponteiro->r * ponteiro->r;
}

void circulo_free(Circulo cir)
{
    struct Circulo *ponteiro = cir;
    free(ponteiro);
}

//o resto depende de outros conceitos, como: nível de proteção, pontuação, etc