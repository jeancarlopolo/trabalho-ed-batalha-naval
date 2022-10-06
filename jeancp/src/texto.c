<<<<<<< HEAD
#include "_TEXTO_H"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "barco.h"

struct Texto
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

typedef void *Texto;
typedef char *string;
typedef struct texto
>>>>>>> 28eb1a7ddb257e5f94b1121b3ba97e0fce538f48
{
    int id;
    float x;
    float y;
<<<<<<< HEAD
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



=======
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
>>>>>>> 28eb1a7ddb257e5f94b1121b3ba97e0fce538f48
