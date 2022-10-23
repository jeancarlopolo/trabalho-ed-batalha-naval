#include "circulo.h"

struct Circle
{
    int id;
    double x;
    double y;
    double r;
    char *cor;
    char *corb;
};

circulo create_circulo(int id, double x, double y, double r, char *corb, char *corp)
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

void circulo_set_x(circulo cir, double x)
{
    struct Circle *ponteiro = cir;
    ponteiro->x = x;
}

void circulo_set_y(circulo cir, double y)
{
    struct Circle *ponteiro = cir;
    ponteiro->y = y;
}

void circulo_set_r(circulo cir, double r)
{
    struct Circle *ponteiro = cir;
    ponteiro->r = r;
}

void circulo_set_corb(circulo cir, char *corb)
{
    struct Circle *ponteiro = cir;
    char *corborda = malloc(sizeof(char) * strlen(corb));
    strcpy(corborda, corb);
    ponteiro->corb = corborda;
}

void circulo_set_corp(circulo cir, char *corp)
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

double circulo_get_x(circulo cir)
{
    struct Circle *ponteiro = cir;
    return ponteiro->x;
}

double circulo_get_y(circulo cir)
{
    struct Circle *ponteiro = cir;
    return ponteiro->y;
}

double circulo_get_r(circulo cir)
{
    struct Circle *ponteiro = cir;
    return ponteiro->r;
}

char *circulo_get_corb(circulo cir)
{
    struct Circle *ponteiro = cir;
    return ponteiro->corb;
}

char *circulo_get_corp(circulo cir)
{
    struct Circle *ponteiro = cir;
    return ponteiro->cor;
}

double circulo_get_area(circulo cir)
{
    struct Circle *ponteiro = cir;
    return 3.14 * ponteiro->r * ponteiro->r;
}

void circulo_free(circulo cir)
{
    struct Circle *ponteiro = cir;
    free(ponteiro->corb);
    free(ponteiro->cor);
    free(cir);
}
