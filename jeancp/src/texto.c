#include "texto.h"

typedef struct texto
{
    int id;
    float x;
    float y;
    char *corb;
    char *corp;
    char *conteudo;
    char ancora;
    int hp;
    int np;
    int pi;
    int pd;
} Stext;

Barco create_texto(int id, float x, float y, char *corb, char *corp, char *conteudo, char ancora)
{
    Stext *text = (Stext *)malloc(sizeof(Stext));
    text->id = id;
    text->x = x;
    text->y = y;
    text->corb = corb;
    text->corp = corp;
    text->conteudo = conteudo;
    text->ancora = ancora;
    text->hp = 1;
    text->np = 5;
    text->pi = 30;
    text->pd = 30;
    return text;
}

void texto_set_id(Barco text, int id)
{
    Stext *t = (Stext *)text;
    t->id = id;
}

void texto_set_x(Barco text, float x)
{
    Stext *t = (Stext *)text;
    t->x = x;
}

void texto_set_y(Barco text, float y)
{
    Stext *t = (Stext *)text;
    t->y = y;
}

void texto_set_corb(Barco text, char *corb)
{
    Stext *t = (Stext *)text;
    t->corb = corb;
}

void texto_set_corp(Barco text, char *corp)
{
    Stext *t = (Stext *)text;
    t->corp = corp;
}

void texto_set_conteudo(Barco text, char *conteudo)
{
    Stext *t = (Stext *)text;
    t->conteudo = conteudo;
}

void texto_set_ancora(Barco text, char ancora)
{
    Stext *t = (Stext *)text;
    t->ancora = ancora;
}

int texto_get_id(Barco text)
{
    Stext *t = (Stext *)text;
    return t->id;
}

float texto_get_x(Barco text)
{
    Stext *t = (Stext *)text;
    return t->x;
}

float texto_get_y(Barco text)
{
    Stext *t = (Stext *)text;
    return t->y;
}

char *texto_get_corb(Barco text)
{
    Stext *t = (Stext *)text;
    return t->corb;
}

char *texto_get_corp(Barco text)
{
    Stext *t = (Stext *)text;
    return t->corp;
}

char *texto_get_conteudo(Barco text)
{
    Stext *t = (Stext *)text;
    return t->conteudo;
}

char texto_get_ancora(Barco text)
{
    Stext *t = (Stext *)text;
    return t->ancora;
}

int texto_get_pontos_inativo(Barco text)
{
    Stext *t = (Stext *)text;
    return t->pi;
}

int texto_get_pontos_destruido(Barco text)
{
    Stext *t = (Stext *)text;
    return t->pd;
}

void texto_free(Barco text)
{
    Stext *t = (Stext *)text;
    free(t->corb);
    free(t->corp);
    free(t->conteudo);
    free(t);
}
