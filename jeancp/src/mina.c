#include "mina.h"

struct mina
{
    int id;
    double x;
    double y;
    char* corb;
    char* corp;
    char* ancora;
};

void setMinaId(Mina min, int id)
{
    struct mina *ponteiro = min;
    ponteiro->id = id;
}

void setMinaX(Mina min, double x)
{
    struct mina *ponteiro = min;
    ponteiro->x = x;
}

void setMinaY(Mina min, double y)
{
    struct mina *ponteiro = min;
    ponteiro->y = y;
}

void setMinaCorb(Mina min, char* corb)
{
    struct mina *ponteiro = min;
    char *corborda = malloc(sizeof(char) * strlen(corb));
    strcpy(corborda, corb);
    ponteiro->corb = corborda;
}

void setMinaCorp(Mina min, char* corp)
{
    struct mina *ponteiro = min;
    char *corpreenchimento = malloc(sizeof(char) * strlen(corp));
    strcpy(corpreenchimento, corp);
    ponteiro->corp = corpreenchimento;
}

void setMinaAncora(Mina min, char* ancora)
{
    struct mina *ponteiro = min;
    char *ancoraTexto = malloc(sizeof(char) * strlen(ancora));
    strcpy(ancoraTexto, ancora);
    ponteiro->ancora = ancoraTexto;
}


Mina createMina(int id, double x, double y, char* corb, char* corp, char *ancora)
{
    struct mina *min = (struct mina *) malloc(sizeof(struct mina));
    setMinaId(min, id);
    setMinaX(min, x);
    setMinaY(min, y);
    setMinaCorb(min, corb);
    setMinaCorp(min, corp);
    setMinaAncora(min, ancora);
    return min;
}

int getMinaId(Mina min)
{
    struct mina *ponteiro = min;
    return ponteiro->id;
}

double getMinaX(Mina min)
{
    struct mina *ponteiro = min;
    return ponteiro->x;
}

double getMinaY(Mina min)
{
    struct mina *ponteiro = min;
    return ponteiro->y;
}

char* getMinaCorB(Mina min)
{
    struct mina *ponteiro = min;
    return ponteiro->corb;
}

char* getMinaCorP(Mina min)
{
    struct mina *ponteiro = min;
    return ponteiro->corp;
}

char* getMinaAncora(Mina min)
{
    struct mina *ponteiro = min;
    return ponteiro->ancora;
}

void killMina(Mina mina)
{
    struct mina *ponteiro = mina;
    free(ponteiro->corb);
    free(ponteiro->corp);
    free(ponteiro->ancora);
    free(ponteiro);
}