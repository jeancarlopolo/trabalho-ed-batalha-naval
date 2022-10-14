#include "circulo.h"

// a struct tem que estar dif. do void pointer do .h
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
// colocar int hp e defesa e pdi
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
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    ponteiro->id = i;
}

void circulo_set_x(Barco cir, float x)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    ponteiro->x = x;
}

void circulo_set_y(Barco cir, float y)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    ponteiro->y = y;
}

void circulo_set_r(Barco cir, float r)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    ponteiro->r = r;
}

void circulo_set_corb(Barco cir, string corb)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    char corborda[20];
    strcpy(corborda, corb);
    ponteiro->corb = corborda;
}

void circulo_set_corp(Barco cir, string corp)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    char corpreenchimento[20];
    strcpy(corpreenchimento, corp);
    ponteiro->cor = corpreenchimento;
}

void free_circulo(Barco cir)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    free(ponteiro);
}

int circulo_get_i(Barco cir)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    return ponteiro->id;
}

float circulo_get_x(Barco cir)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    return ponteiro->x;
}

float circulo_get_y(Barco cir)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    return ponteiro->y;
}

float circulo_get_r(Barco cir)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    return ponteiro->r;
}

string circulo_get_corb(Barco cir)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    return ponteiro->corb;
}

string circulo_get_corp(Barco cir)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    return ponteiro->cor;
}

float circulo_get_area(Barco cir)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    return 3.14 * ponteiro->r * ponteiro->r;
}

void circulo_free(Barco cir)
{
    Item info = cir;
    getInfo(cir, info);
    struct Circle *ponteiro = info;
    free(ponteiro);
}

// o resto depende de outros conceitos, como: nível de proteção, pontuação, etc