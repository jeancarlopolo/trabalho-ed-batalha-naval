#include "circulo.h"

//a struct tem que estar dif. do void pointer do .h
struct Circle
{
    int id;
    float x;
    float y;
    float r;
    string cor;
    string corb;
    int hp;
    int np;
};
//colocar int hp e defesa e pdi
Barco create_circulo(int id, float x, float y, float r, string corb, string corp)
{
    struct Circle *cir = malloc(sizeof(struct Circle));
    Barco bar = createBarco('c', cir);
    circulo_set_i(cir, id);
    circulo_set_x(cir, x);
    circulo_set_y(cir, y);
    circulo_set_r(cir, r);
    circulo_set_corb(cir, corb);
    circulo_set_corp(cir, corp);
    cir->hp = 2;
    cir->np = 60;
    return bar;
}

void circulo_set_i(Barco cir, int i)
{
    struct Circle *ponteiro = getInfo (cir);
    ponteiro->id = i;
}

void circulo_set_x(Circulo cir, float x)
{
    struct Circle *ponteiro = getInfo (cir);
    ponteiro->x = x;
}

void circulo_set_y(Circulo cir, float y)
{
    struct Circle *ponteiro = getInfo (cir);
    ponteiro->y = y;
}

void circulo_set_r(Circulo cir, float r)
{
    struct Circle *ponteiro = getInfo (cir);
    ponteiro->r = r;
}

void circulo_set_corb(Circulo cir, string corb)
{
    struct Circle *ponteiro = getInfo (cir);
    ponteiro->corb = corb;
}

void circulo_set_corp(Circulo cir, string corp)
{
    struct Circle *ponteiro = getInfo (cir);
    ponteiro->cor = corp;
}

void free_circulo(Circulo cir)
{
    struct Circle *ponteiro = getInfo (cir);
    free(ponteiro);
}

int circulo_get_i(Circulo cir)
{
    struct Circle *ponteiro = getInfo (cir);
    return ponteiro->id;
}

float circulo_get_x(Circulo cir)
{
    struct Circle *ponteiro = getInfo (cir);
    return ponteiro->x;
}

float circulo_get_y(Circulo cir)
{
    struct Circle *ponteiro = getInfo (cir);
    return ponteiro->y;
}

float circulo_get_r(Circulo cir)
{
    struct Circle *ponteiro = getInfo (cir);
    return ponteiro->r;
}

string circulo_get_corb(Circulo cir)
{
    struct Circle *ponteiro = getInfo (cir);
    return ponteiro->corb;
}

string circulo_get_corp(Circulo cir)
{
    struct Circle *ponteiro = getInfo (cir);
    return ponteiro->cor;
}

float circulo_get_area(Circulo cir)
{
    struct Circle *ponteiro = getInfo (cir);
    return 3.14 * ponteiro->r * ponteiro->r;
}

void circulo_free(Circulo cir)
{
    struct Circle *ponteiro = getInfo (cir);
    free(ponteiro);
}

//o resto depende de outros conceitos, como: nível de proteção, pontuação, etc