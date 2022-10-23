#include "linha.h"


struct Line
{
    int id;
    double x1;
    double y1;
    double x2;
    double y2;
    char* cor;
    int hp;
    int np;
};

linha create_linha(int id, double x1, double y1, double x2, double y2, char* cor)
{
    struct Line *li = malloc(sizeof(struct Line));
    linha_set_i(li, id);
    linha_set_x1(li, x1);
    linha_set_y1(li, y1);
    linha_set_x2(li, x2);
    linha_set_y2(li, y2);
    linha_set_cor(li, cor);
    return li;
}

void linha_set_i(linha li, int i)
{
    struct Line *ponteiro = li;
    ponteiro->id = i;
}

void linha_set_x1(linha li, double x1)
{
    struct Line *ponteiro = li;
    ponteiro->x1 = x1;
}

void linha_set_y1(linha li, double y1)
{
    struct Line *ponteiro = li;
    ponteiro->y1 = y1;
}

void linha_set_x2(linha li, double x2)
{
    struct Line *ponteiro = li;
    ponteiro->x2 = x2;
}

void linha_set_y2(linha li, double y2)
{
    struct Line *ponteiro = li;
    ponteiro->y2 = y2;
}

void linha_set_cor(linha li, char* cor)
{
    struct Line *ponteiro = li;
    char *corstring = malloc(sizeof(char) * strlen(cor));
    strcpy(corstring, cor);
    ponteiro->cor = corstring;
}

int linha_get_i(linha li)
{
    struct Line *ponteiro = li;
    return ponteiro->id;
}

double linha_get_x1(linha li)
{
    struct Line *ponteiro = li;
    return ponteiro->x1;
}

double linha_get_y1(linha li)
{
    struct Line *ponteiro = li;
    return ponteiro->y1;
}

double linha_get_x2(linha li)
{
    struct Line *ponteiro = li;
    return ponteiro->x2;
}

double linha_get_y2(linha li)
{
    struct Line *ponteiro = li;
    return ponteiro->y2;
}

char* linha_get_cor(linha li)
{
    struct Line *ponteiro = li;
    return ponteiro->cor;
}

void linha_free(linha li)
{
    struct Line *ponteiro = li;
    free(ponteiro->cor);
    free(li);
}
