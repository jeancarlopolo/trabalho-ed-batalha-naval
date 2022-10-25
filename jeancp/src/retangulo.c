#include "retangulo.h"

struct Rectangle
{
    int id;
    double x;
    double y;
    double w;
    double h;
    char *cor;
    char *corb;
};

retangulo create_retangulo(int id, double x, double y, double w, double h, char *corb, char *corp)
{
    struct Rectangle *ret = (struct Rectangle *)malloc(sizeof(struct Rectangle));
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
    struct Rectangle *pointer = ret;
    pointer->id = i;
}

void retangulo_set_x(retangulo ret, double x)
{
    struct Rectangle *pointer = ret;
    pointer->x = x;
}

void retangulo_set_y(retangulo ret, double y)
{
    struct Rectangle *pointer = ret;
    pointer->y = y;
}

void retangulo_set_w(retangulo ret, double w)
{
    struct Rectangle *pointer = ret;
    pointer->w = w;
}

void retangulo_set_h(retangulo ret, double h)
{
    struct Rectangle *pointer = ret;
    pointer->h = h;
}

void retangulo_set_corb(retangulo ret, char *corb)
{
    struct Rectangle *pointer = ret;
    char *corborda = malloc(sizeof(char) * strlen(corb));
    strcpy(corborda, corb);
    pointer->corb = corborda;
}

void retangulo_set_corp(retangulo ret, char *corp)
{
    struct Rectangle *pointer = ret;
    char *corpreenchimento = malloc(sizeof(char) * strlen(corp));
    strcpy(corpreenchimento, corp);
    pointer->cor = corpreenchimento;
}

int retangulo_get_i(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->id;
}

double retangulo_get_x(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->x;
}

double retangulo_get_y(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->y;
}

double retangulo_get_w(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->w;
}

double retangulo_get_h(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->h;
}

char *retangulo_get_corb(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->corb;
}

char *retangulo_get_corp(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->cor;
}

double retangulo_get_area(retangulo ret)
{
    struct Rectangle *pointer = ret;
    return pointer->h * pointer->w;
}

void retangulo_free(retangulo ret)
{
    struct Rectangle *pointer = ret;
    free(pointer->corb);
    free(pointer->cor);
    free(ret);
}
