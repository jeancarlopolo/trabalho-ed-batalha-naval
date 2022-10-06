#include "barco.h"
#include "lista.h"

struct Barco
{
    Item info;
    char tipo;
};

Barco createBarco(char id, Item info)
{
    struct barco *b = malloc(sizeof(struct barco));
    b->tipo = id;
    //id = char tipo? 
    b->info = info;
    return b;
};

Item getInfo(Barco b)
{
    struct barco *ponteiro = b;
    //nessa função que eu retorno as informações do tipo de barco?
    return ponteiro->info;
};

char getTipo(Barco b)
{
    struct barco *ponteiro = b;
    //nessa função que eu pego o tipo do barco 
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


    return 0;
}
