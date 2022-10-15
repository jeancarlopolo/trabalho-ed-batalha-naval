#include "circulo.h"
#include "barco.h"

// a struct tem que estar dif. do void pointer do .h
struct Circle
{
    int id;
    float x;
    float y;
    float r;
    char* cor;
    char* corb;
};
// colocar int hp e defesa e pdi
circulo create_circulo(int id, float x, float y, float r, char* corb, char* corp)
{
    struct Circle *cir = malloc(sizeof(struct Circle));
    circulo_set_i(cir, id);
    circulo_set_x(cir, x);
    circulo_set_y(cir, y);
    circulo_set_r(cir, r);
    circulo_set_corb(cir, corb);
    circulo_set_corp(cir, corp);
    return cir;
}

void circulo_set_i(circulo cir, int i)
{
    struct Circle *ponteiro = cir;
    ponteiro->id = i;
}

void circulo_set_x(circulo cir, float x)
{
    struct Circle *ponteiro = cir;
    ponteiro->x = x;
}

void circulo_set_y(circulo cir, float y)
{
    struct Circle *ponteiro = cir;
    ponteiro->y = y;
}

void circulo_set_r(circulo cir, float r)
{
    struct Circle *ponteiro = cir;
    ponteiro->r = r;
}

void circulo_set_corb(circulo cir, char* corb)
{
    struct Circle *ponteiro = cir;
    char *corborda = malloc(sizeof(char) * strlen(corb));
    strcpy(corborda, corb);
    ponteiro->corb = corborda;
}

void circulo_set_corp(circulo cir, char* corp)
{
    struct Circle *ponteiro = cir;
    char *corpreenchimento = malloc(sizeof(char) * strlen(corp));
    strcpy(corpreenchimento, corp);
    ponteiro->cor = corpreenchimento;
}

int circulo_get_i(circulo cir)
{
    struct Circle *ponteiro = cir;
    return ponteiro->id;
}

float circulo_get_x(circulo cir)
{
    struct Circle *ponteiro = cir;
    return ponteiro->x;
}

float circulo_get_y(circulo cir)
{
    struct Circle *ponteiro = cir;
    return ponteiro->y;
}

float circulo_get_r(circulo cir)
{
    struct Circle *ponteiro = cir;
    return ponteiro->r;
}

char* circulo_get_corb(circulo cir)
{
    struct Circle *ponteiro = cir;
    return ponteiro->corb;
}

char* circulo_get_corp(circulo cir)
{
    struct Circle *ponteiro = cir;
    return ponteiro->cor;
}

float circulo_get_area(circulo cir)
{
    struct Circle *ponteiro = cir;
    return 3.14 * ponteiro->r * ponteiro->r;
}

void circulo_free(circulo cir)
{
    Item info = getInfo(cir);
    struct Circle *ponteiro = info;
    free(ponteiro->corb);
    free(ponteiro->cor);
    free(cir);
}
