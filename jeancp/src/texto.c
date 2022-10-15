#include "texto.h"

struct Text
{
    int id;
    float x;
    float y;
    char* corb;
    char* corp;
    char* conteudo;
    char* ancora;
};


void texto_set_i(texto txt, int i)
{
    struct Text *ponteiro = txt;
    ponteiro->id = i;
}

void texto_set_x(texto txt, float x)
{
    struct Text *ponteiro = txt;
    ponteiro->x = x;
}

void texto_set_y(texto txt, float y)
{
    struct Text *ponteiro = txt;
    ponteiro->y = y;
}

void texto_set_corb(texto txt, char* corb)
{
    struct Text *ponteiro = txt;
    char *corborda = malloc(sizeof(char) * 200);
    strcpy(corborda, corb);
    ponteiro->corb = corborda;
}

void texto_set_corp(texto txt, char* corp)
{
    struct Text *ponteiro = txt;
    char *corpreenchimento = malloc(sizeof(char) * strlen(corp));
    strcpy(corpreenchimento, corp);
    ponteiro->corp = corpreenchimento;
}

void texto_set_conteudo(texto txt, char* conteudo)
{
    struct Text *ponteiro = txt;
    char *conteudoTexto = malloc(sizeof(char) * strlen(conteudo));
    strcpy(conteudoTexto, conteudo);
    ponteiro->conteudo = conteudoTexto;
}

void texto_set_ancora(texto txt, char* ancora)
{
    struct Text *ponteiro = txt;
    char *ancoraTexto = malloc(sizeof(char) * strlen(ancora));
    strcpy(ancoraTexto, ancora);
    ponteiro->ancora = ancoraTexto;
}

int texto_get_i(texto txt)
{
    struct Text *ponteiro = txt;
    return ponteiro->id;
}

float texto_get_x(texto txt)
{
    struct Text *ponteiro = txt;
    return ponteiro->x;
}

float texto_get_y(texto txt)
{
    struct Text *ponteiro = txt;
    return ponteiro->y;
}

char* texto_get_corb(texto txt)
{
    struct Text *ponteiro = txt;
    return ponteiro->corb;
}

char* texto_get_corp(texto txt)
{
    struct Text *ponteiro = txt;
    return ponteiro->corp;
}

char* texto_get_conteudo(texto txt)
{
    struct Text *ponteiro = txt;
    return ponteiro->conteudo;
}

char* texto_get_ancora(texto txt)
{
    struct Text *ponteiro = txt;
    return ponteiro->ancora;
}

texto create_texto(int id, float x, float y, char* corb, char* corp, char* conteudo, char* ancora)
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
    struct Text *ponteiro = txt;
    free(ponteiro->corb);
    free(ponteiro->corp);
    free(ponteiro->conteudo);
    free(ponteiro->ancora);
    free(ponteiro);
}