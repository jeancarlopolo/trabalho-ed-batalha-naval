#include "mina.h"

struct mina
{
    int id;
    double x;
    double y;
    char *corb;
    char *corp;
    char *ancora;
};

void setMinaId(Mina min, int id)
{
    struct mina *pointer = min;
    pointer->id = id;
}

void setMinaX(Mina min, double x)
{
    struct mina *pointer = min;
    pointer->x = x;
}

void setMinaY(Mina min, double y)
{
    struct mina *pointer = min;
    pointer->y = y;
}

void setMinaCorb(Mina min, char *corb)
{
    struct mina *pointer = min;
    char *corborda = malloc(sizeof(char) * strlen(corb));
    strcpy(corborda, corb);
    pointer->corb = corborda;
}

void setMinaCorp(Mina min, char *corp)
{
    struct mina *pointer = min;
    char *corpreenchimento = malloc(sizeof(char) * strlen(corp));
    strcpy(corpreenchimento, corp);
    pointer->corp = corpreenchimento;
}

void setMinaAncora(Mina min, char *ancora)
{
    struct mina *pointer = min;
    char *ancoraTexto = malloc(sizeof(char) * strlen(ancora));
    strcpy(ancoraTexto, ancora);
    pointer->ancora = ancoraTexto;
}

Mina createMina(int id, double x, double y, char *corb, char *corp, char *ancora)
{
    struct mina *min = (struct mina *)malloc(sizeof(struct mina));
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
    struct mina *pointer = min;
    return pointer->id;
}

double getMinaX(Mina min)
{
    struct mina *pointer = min;
    return pointer->x;
}

double getMinaY(Mina min)
{
    struct mina *pointer = min;
    return pointer->y;
}

char *getMinaCorB(Mina min)
{
    struct mina *pointer = min;
    return pointer->corb;
}

char *getMinaCorP(Mina min)
{
    struct mina *pointer = min;
    return pointer->corp;
}

char *getMinaAncora(Mina min)
{
    struct mina *pointer = min;
    return pointer->ancora;
}

void killMina(Mina mina)
{
    struct mina *pointer = mina;
    free(pointer->corb);
    free(pointer->corp);
    free(pointer->ancora);
    free(pointer);
}