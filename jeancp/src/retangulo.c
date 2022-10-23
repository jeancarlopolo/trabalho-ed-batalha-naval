#include "retangulo.h"

struct Rectangle
{
    int id;
    double x;
    double y;
    double w;
    double h;
    char* cor;
    char* corb;
};

retangulo create_retangulo(int id, double x, double y, double w, double h, char* corb, char* corp)
{
    struct Rectangle *ret = (struct Rectangle *) malloc(sizeof(struct Rectangle));
    retangulo_set_i(ret, id);
    retangulo_set_x(ret, x);
    retangulo_set_y(ret, y);
    retangulo_set_w(ret, w);
    retangulo_set_h(ret, h);
    retangulo_set_corb(ret, corb);
    retangulo_set_corp(ret, corp);
    return ret;
}

void retangulo_set_i(retangulo ret, int i)
{
    struct Rectangle *ponteiro = ret;
    ponteiro->id = i;
}

void retangulo_set_x(retangulo ret, double x)
{
    struct Rectangle *ponteiro = ret;
    ponteiro->x = x;
}

void retangulo_set_y(retangulo ret, double y)
{
    struct Rectangle *ponteiro = ret;
    ponteiro->y = y;
}

void retangulo_set_w(retangulo ret, double w)
{
    struct Rectangle *ponteiro = ret;
    ponteiro->w = w;
}

void retangulo_set_h(retangulo ret, double h)
{
    struct Rectangle *ponteiro = ret;
    ponteiro->h = h;
}

void retangulo_set_corb(retangulo ret, char* corb)
{
    struct Rectangle *ponteiro = ret;
    char *corborda = malloc(sizeof(char) * strlen(corb));
    strcpy(corborda, corb);
    ponteiro->corb = corborda;
}

void retangulo_set_corp(retangulo ret, char* corp)
{
    struct Rectangle *ponteiro = ret;
    char *corpreenchimento = malloc(sizeof(char) * strlen(corp));
    strcpy(corpreenchimento, corp);
    ponteiro->cor = corpreenchimento;
}

int retangulo_get_i(retangulo ret)
{
    struct Rectangle *ponteiro = ret;
    return ponteiro->id;
}

double retangulo_get_x(retangulo ret)
{
    struct Rectangle *ponteiro = ret;
    return ponteiro->x;
}

double retangulo_get_y(retangulo ret)
{
    struct Rectangle *ponteiro = ret;
    return ponteiro->y;
}

double retangulo_get_w(retangulo ret)
{
    struct Rectangle *ponteiro = ret;
    return ponteiro->w;
}

double retangulo_get_h(retangulo ret)
{
    struct Rectangle *ponteiro = ret;
    return ponteiro->h;
}

char* retangulo_get_corb(retangulo ret)
{
    struct Rectangle *ponteiro = ret;
    return ponteiro->corb;
}

char* retangulo_get_corp(retangulo ret)
{
    struct Rectangle *ponteiro = ret;
    return ponteiro->cor;
}

double retangulo_get_area(retangulo ret)
{
    struct Rectangle *ponteiro = ret;
    return ponteiro->h * ponteiro->w;
}

void retangulo_free(retangulo ret)
{
    struct Rectangle *ponteiro = ret;
    free(ponteiro->corb);
    free(ponteiro->cor);
    free(ret);
}
