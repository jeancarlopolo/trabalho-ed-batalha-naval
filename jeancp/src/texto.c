#include "_TEXTO_H"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "barco.h"

struct Texto
{
    int id;
    float x;
    float y;
    string txt;
    string cor;
};

Texto create_texto(int id, float x, float y, string txt, string cor)
{
    Texto txt = (Texto)malloc(sizeof(struct Texto));
    texto_set_i(txt, id);
    texto_set_x(txt, x);
    texto_set_y(txt, y);
    texto_set_txt(txt, txt);
    texto_set_cor(txt, cor);
    return txt;
};

void texto_set_i(Texto txt, int i)
{
    struct Texto *ponteiro = txt;
    ponteiro->id = i;
};

void texto_set_x(Texto txt, float x)
{
    struct Texto *ponteiro = txt;
    ponteiro->x = x;
};

void texto_set_y(Texto txt, float y)
{
    struct Texto *ponteiro = txt;
    ponteiro->y = y;
};

void texto_set_txt(Texto txt, string txt)
{
    struct Texto *ponteiro = txt;
    ponteiro->txt = txt;
};

void texto_set_cor(Texto txt, string cor)
{
    struct Texto *ponteiro = txt;
    ponteiro->cor = cor;
};

void texto_set_corp(Texto txt, string corp)
{
    struct Texto *ponteiro = txt;
    ponteiro->corp = corp;
};

void texto_set_corb(Texto txt, string corb)
{
    struct Texto *ponteiro = txt;
    ponteiro->corb = corb;
};

void texto_set_corp(Texto txt, string corp)
{
    struct Texto *ponteiro = txt;
    ponteiro->corp = corp;
};

int texto_get_i(Texto text)
{
    struct Texto *ponteiro = text;
    return ponteiro->id;
};

char texto_get_ancora(Texto text)
{
    struct Texto *ponteiro = text;
    return ponteiro->ancora;
};

float texto_get_x(Texto text)
{
    struct Texto *ponteiro = text;
    return ponteiro->x;
};

float texto_get_y(Texto text)
{
    struct Texto *ponteiro = text;
    return ponteiro->y;
};

string texto_get_conteudo(Texto text)
{
    struct Texto *ponteiro = text;
    return ponteiro->conteudo;
};

string texto_get_corb(Texto text)
{
    struct Texto *ponteiro = text;
    return ponteiro->corb;
};

string texto_get_corp(Texto text)
{
    struct Texto *ponteiro = text;
    return ponteiro->corp;
};

void texto_free(Texto text)
{
    free(text);
};



