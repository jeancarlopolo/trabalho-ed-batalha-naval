#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"


typedef struct texto
{
    int id;
    float x;
    float y;
    string corb;
    string corp;
    string conteudo;
    string ancora;
    float pi;
    float pd;
    int hp;
    int np;
}Stext;

Texto create_texto(int id, float x, float y, string corb, string corp, string conteudo, char ancora)
{
    Stext *text = malloc(sizeof(Stext));
    text->id = id;
    text->x = x;
    text->y = y;
    text->corb = corb;
    text->corp = corp;
    text->conteudo = conteudo;
    text->ancora = ancora;
    text->hp = 3;
    text->np = 60;
    return text;
}

void texto_set_id(Texto text, int id){
    Stext *t = text;
    t->id = id;

}

void texto_set_x(Texto text, float x)
{
    Stext *t = text;
    t->x = x;
}

void texto_set_y(Texto text, float y)
{
    Stext *t = text;
    t->y = y;
}

void texto_set_corb(Texto text, char *corb)
{
    Stext *t = text;
    t->corb = corb;
}

void texto_set_corp(Texto text, char *corp)
{
    Stext *t = text;
    t->corp = corp;
}

void texto_set_conteudo(Texto text, char *conteudo)
{
    Stext *t = text;
    t->conteudo = conteudo;
}

void texto_set_ancora(Texto text, char ancora)
{
    Stext *t = text;
    t->ancora = ancora;
}

int texto_get_id(Texto text)
{
    Stext *t = text;
    return t->id;
}

float texto_get_x(Texto text)
{
    Stext *t = text;
    return t->x;
}

float texto_get_y(Texto text)
{
    Stext *t = text;
    return t->y;
}

char *texto_get_corb(Texto text)
{
    Stext *t = text;
    return t->corb;
}

char *texto_get_corp(Texto text)
{
    Stext *t = text;
    return t->corp;
}

char *texto_get_conteudo(Texto text)
{
    Stext *t = text;
    return t->conteudo;
}

char texto_get_ancora(Texto text)
{
    Stext *t = text;
    return t->ancora;
}

void texto_free(Texto text)
{
    Stext *t = text;
    free(t->corb);
    free(t->corp);
    free(t->conteudo);
    free(t);
}

// Language: c