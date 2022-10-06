#include "barco.h"
#include "lista.h"

struct Barco
{
    Item info;
    char tipo;
};

Barco createBarco(char id, Item info)
{
    struct Barco *b = malloc(sizeof(struct Barco));
    b->tipo = id;
    //id = char tipo? 
    b->info = info;
    return b;
};

Item getInfo(Barco b)
{
    struct Barco *ponteiro = b;
    //nessa função que eu retorno as informações do tipo de barco?
    return ponteiro->info;
};

char getTipo(Barco b)
{
    struct Barco *ponteiro = b;
    //nessa função que eu pego o tipo do barco 
    return ponteiro->tipo;
};

void setInfo(Barco b, Item info)
{
    struct Barco *ponteiro = b;
    ponteiro->info = info;

};

void freeBarco(Barco b)
{
    struct Barco *ponteiro = b;
    free(ponteiro);
};



