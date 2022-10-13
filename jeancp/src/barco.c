#include "barco.h"

struct Barco
{
    Item info;
    char tipo;
};

Barco createBarco(char id, Item info)
{
    struct Barco *b = malloc(sizeof(struct Barco));
    b->tipo = id;
    b->info = info;
    return b;
}

Item getInfo(Barco b, Item info)
{
    struct Barco *ponteiro = b;
    info = ponteiro->info;
    return info;
}

char getTipo(Barco b)
{
    struct Barco *ponteiro = b;
    return ponteiro->tipo;
}

void setInfo(Barco b, Item info)
{
    struct Barco *ponteiro = b;
    ponteiro->info = info;

}
