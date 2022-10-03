#include "barco.h"
#include "lista.h"

struct barco
{
    Item info;
    char tipo;
};

Barco createBarco(char id, Item info)
{
    struct barco *b = malloc(sizeof(struct barco));
    b->tipo = id;
    b->info = info;
    return b;
};

Item getInfo(Barco b)
{
    struct barco *ponteiro = b;
    return ponteiro->info;
};

char getTipo(Barco b)
{
    struct barco *ponteiro = b;
    return ponteiro->tipo;
};

void setInfo(Barco b, Item info)
{
    struct barco *ponteiro = b;
    ponteiro->info = info;
};

void freeBarco(Barco b)
{
    struct barco *ponteiro = b;
    free(ponteiro);
};

