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

Retangulo create_retangulo(int id, float x, float y, float w, float h, string corb, string corp)
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
    return ret;
}

void retangulo_set_i(Retangulo ret, int i)
{
    struct Rectangle *ponteiro = getInfo (ret);
    ponteiro->id = i;
}

void retangulo_set_x(Retangulo ret, float x)
{
    struct Rectangle *ponteiro = getInfo (ret);
    ponteiro->x = x;
}

void retangulo_set_y(Retangulo ret, float y)
{
    struct Rectangle *ponteiro = getInfo (ret);
    ponteiro->y = y;
}

void retangulo_set_w(Retangulo ret, float w)
{
    struct Rectangle *ponteiro = getInfo (ret);
    ponteiro->w = w;
}

void retangulo_set_h(Retangulo ret, float h)
{
    struct Rectangle *ponteiro = getInfo (ret);
    ponteiro->h = h;
}

void retangulo_set_corb(Retangulo ret, string corb)
{
    struct Rectangle *ponteiro = getInfo (ret);
    ponteiro->corb = corb;
}

void retangulo_set_corp(Retangulo ret, string corp)
{
    struct Rectangle *ponteiro = getInfo (ret);
    ponteiro->cor = corp;
}

int retangulo_get_i(Retangulo ret)
{
    struct Rectangle *ponteiro = getInfo (ret);
    return ponteiro->id;
}

float retangulo_get_x(Retangulo ret)
{
    struct Rectangle *ponteiro = getInfo (ret);
    return ponteiro->x;
}

float retangulo_get_y(Retangulo ret)
{
    struct Rectangle *ponteiro = getInfo (ret);
    return ponteiro->y;
}

float retangulo_get_w(Retangulo ret)
{
    struct Rectangle *ponteiro = getInfo (ret);
    return ponteiro->w;
}

float retangulo_get_h(Retangulo ret)
{
    struct Rectangle *ponteiro = getInfo (ret);
    return ponteiro->h;
}

string retangulo_get_corb(Retangulo ret)
{
    struct Rectangle *ponteiro = getInfo (ret);
    return ponteiro->corb;
}

string retangulo_get_corp(Retangulo ret)
{
    struct Rectangle *ponteiro = getInfo (ret);
    return ponteiro->cor;
}

void retangulo_free(Retangulo ret)
{
    free(ret);
}

//o resto depende de outros conceitos, como: nível de proteção, pontuação, etc.