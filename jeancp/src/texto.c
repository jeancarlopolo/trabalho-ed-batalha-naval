#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

typedef void *Texto;
typedef char *string;
typedef struct texto
{
    int id;
    float x;
    float y;
    char *corb;
    char *corp;
    char *conteudo;
    char ancora;
}Stext;

Texto create_texto(int id, float x, float y, char *corb, char *corp, char *conteudo, char ancora)
{
    Stext *text = (Stext*)malloc(sizeof(Stext));
    text->id = id;
    text->x = x;
    text->y = y;
    text->corb = corb;
    text->corp = corp;
    text->conteudo = conteudo;
    text->ancora = ancora;
    return text;
}

void texto_set_id(Texto text, int id){
    Stext *t = (Stext*)text;
    t->id = id;

}

void texto_set_x(Texto text, float x)
{
    Stext *t = (Stext*)text;
    t->x = x;
}

void texto_set_y(Texto text, float y)
{
    Stext *t = (Stext*)text;
    t->y = y;
}

void texto_set_corb(Texto text, char *corb)
{
    Stext *t = (Stext*)text;
    t->corb = corb;
}

void texto_set_corp(Texto text, char *corp)
{
    Stext *t = (Stext*)text;
    t->corp = corp;
}

void texto_set_conteudo(Texto text, char *conteudo)
{
    Stext *t = (Stext*)text;
    t->conteudo = conteudo;
}

void texto_set_ancora(Texto text, char ancora)
{
    Stext *t = (Stext*)text;
    t->ancora = ancora;
}

int texto_get_id(Texto text)
{
    Stext *t = (Stext*)text;
    return t->id;
}

float texto_get_x(Texto text)
{
    Stext *t = (Stext*)text;
    return t->x;
}

float texto_get_y(Texto text)
{
    Stext *t = (Stext*)text;
    return t->y;
}

char *texto_get_corb(Texto text)
{
    Stext *t = (Stext*)text;
    return t->corb;
}

char *texto_get_corp(Texto text)
{
    Stext *t = (Stext*)text;
    return t->corp;
}

char *texto_get_conteudo(Texto text)
{
    Stext *t = (Stext*)text;
    return t->conteudo;
}

char texto_get_ancora(Texto text)
{
    Stext *t = (Stext*)text;
    return t->ancora;
}

void texto_free=(Texto text)
{
    Stext *t = (Stext*)text;
    free(t->corb);
    free(t->corp);
    free(t->conteudo);
    free(t);
}

// Language: c
