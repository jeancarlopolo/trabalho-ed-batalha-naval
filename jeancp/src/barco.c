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

Item getInfo(Barco b)
{
    struct Barco *ponteiro = b;
    return ponteiro->info;
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

void freeBarco(Barco b)
{
    struct Barco *ponteiro = b;
    switch (ponteiro->tipo)
    {
    case 'c':
        circulo_free(ponteiro->info);
        break;
    case 'r':
        retangulo_free(ponteiro->info);
        break;
    case 't':
        texto_free(ponteiro->info);
        break;
    case 'l':
        linha_free(ponteiro->info);
        break;
    default:
        break;
    }
    free(ponteiro);
}



