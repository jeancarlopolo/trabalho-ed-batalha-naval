#include "retangulo.h"

struct Rectangle
{
    int id;
    float x;
    float y;
    float w;
    float h;
    string cor;
    string corb;
};

Barco create_retangulo(int id, float x, float y, float w, float h, string corb, string corp)
{
    struct Rectangle *ret = malloc(sizeof(struct Rectangle));
    Barco bar = createBarco('r', ret);
    retangulo_set_i(ret, id);
    retangulo_set_x(ret, x);
    retangulo_set_y(ret, y);
    retangulo_set_w(ret, w);
    retangulo_set_h(ret, h);
    retangulo_set_corb(ret, corb);
    retangulo_set_corp(ret, corp);
    return bar;
}

void retangulo_set_i(Barco ret, int i)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    ponteiro->id = i;
}

void retangulo_set_x(Barco ret, float x)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    ponteiro->x = x;
}

void retangulo_set_y(Barco ret, float y)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    ponteiro->y = y;
}

void retangulo_set_w(Barco ret, float w)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    ponteiro->w = w;
}

void retangulo_set_h(Barco ret, float h)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    ponteiro->h = h;
}

void retangulo_set_corb(Barco ret, string corb)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    char corborda[20];
    strcpy(corborda, corb);
    ponteiro->corb = corborda;
}

void retangulo_set_corp(Barco ret, string corp)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    char corpreenchimento[20];
    strcpy(corpreenchimento, corp);
    ponteiro->cor = corpreenchimento;
}

int retangulo_get_i(Barco ret)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    return ponteiro->id;
}

float retangulo_get_x(Barco ret)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    return ponteiro->x;
}

float retangulo_get_y(Barco ret)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    return ponteiro->y;
}

float retangulo_get_w(Barco ret)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    return ponteiro->w;
}

float retangulo_get_h(Barco ret)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    return ponteiro->h;
}

string retangulo_get_corb(Barco ret)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    return ponteiro->corb;
}

string retangulo_get_corp(Barco ret)
{
    Item info = ret;
    getInfo(ret, info);
    struct Rectangle *ponteiro = info;
    return ponteiro->cor;
}

void retangulo_free(Barco ret)
{
    free(ret);
}

// o resto depende de outros conceitos, como: nível de proteção, pontuação, etc.