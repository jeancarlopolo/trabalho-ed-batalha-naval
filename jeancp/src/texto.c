#include "texto.h"

struct Text
{
    int id;
    double x;
    double y;
    char *corb;
    char *corp;
    char *conteudo;
    char *ancora;
};

void texto_set_i(texto txt, int i)
{
    struct Text *pointer = txt;
    pointer->id = i;
}

void texto_set_x(texto txt, double x)
{
    struct Text *pointer = txt;
    pointer->x = x;
}

void texto_set_y(texto txt, double y)
{
    struct Text *pointer = txt;
    pointer->y = y;
}

void texto_set_corb(texto txt, char *corb)
{
    struct Text *pointer = txt;
    char *corborda = malloc(sizeof(char) * 200);
    strcpy(corborda, corb);
    pointer->corb = corborda;
}

void texto_set_corp(texto txt, char *corp)
{
    struct Text *pointer = txt;
    char *corpreenchimento = malloc(sizeof(char) * strlen(corp));
    strcpy(corpreenchimento, corp);
    pointer->corp = corpreenchimento;
}

void texto_set_conteudo(texto txt, char *conteudo)
{
    struct Text *pointer = txt;
    char *conteudoTexto = malloc(sizeof(char) * strlen(conteudo));
    strcpy(conteudoTexto, conteudo);
    pointer->conteudo = conteudoTexto;
}

void texto_set_ancora(texto txt, char *ancora)
{
    struct Text *pointer = txt;
    char *ancoraTexto = malloc(sizeof(char) * strlen(ancora));
    strcpy(ancoraTexto, ancora);
    pointer->ancora = ancoraTexto;
}

int texto_get_i(texto txt)
{
    struct Text *pointer = txt;
    return pointer->id;
}

double texto_get_x(texto txt)
{
    struct Text *pointer = txt;
    return pointer->x;
}

double texto_get_y(texto txt)
{
    struct Text *pointer = txt;
    return pointer->y;
}

char *texto_get_corb(texto txt)
{
    struct Text *pointer = txt;
    return pointer->corb;
}

char *texto_get_corp(texto txt)
{
    struct Text *pointer = txt;
    return pointer->corp;
}

char *texto_get_conteudo(texto txt)
{
    struct Text *pointer = txt;
    return pointer->conteudo;
}

char *texto_get_ancora(texto txt)
{
    struct Text *pointer = txt;
    return pointer->ancora;
}

texto create_texto(int id, double x, double y, char *corb, char *corp, char *conteudo, char *ancora)
{
    struct Text *txt = malloc(sizeof(struct Text));
    texto_set_i(txt, id);
    texto_set_x(txt, x);
    texto_set_y(txt, y);
    texto_set_corb(txt, corb);
    texto_set_corp(txt, corp);
    texto_set_conteudo(txt, conteudo);
    texto_set_ancora(txt, ancora);
    return txt;
}

void texto_free(texto txt)
{
    struct Text *pointer = txt;
    free(pointer->corb);
    free(pointer->corp);
    free(pointer->conteudo);
    free(pointer->ancora);
    free(pointer);
}