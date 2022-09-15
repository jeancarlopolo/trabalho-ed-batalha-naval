#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct listabase
{
    Item info;
    struct listabase *prox;
    struct listabase *ant;
    Posic posicao;
};

struct lista
{
    struct listabase *l;
    int capacidade;
};

Lista createLista(int capacidade)
{
    struct lista *L = malloc(sizeof(struct lista));
    L->l->posicao = NIL;
    L->l->ant = NIL;
    L->l->prox = NIL;
    if (capacidade < 0)
    {
        L->capacidade = CAPAC_ILIMITADA;
    }
    else
    {
        L->capacidade = capacidade;
    }
    return L;
};

int length(Lista L)
{
    struct lista *ponteiro = L;
    while (ponteiro->l->prox != NULL)
    {
        ponteiro = ponteiro->l->prox;
    };
    return ponteiro->l->posicao;
};

int maxLength(Lista L)
{
    struct lista *ponteiro = L;
    return ponteiro->capacidade;
};

bool isEmpty(Lista L)
{
    struct lista *ponteiro = L;
    if (ponteiro->l->posicao == NIL)
    {
        return true;
    }
    else
    {
        return false;
    };
};

bool isFull(Lista L)
{
    struct lista *ponteiro = L;
    if (ponteiro->capacidade != CAPAC_ILIMITADA && length(ponteiro) == maxLength(ponteiro))
    {
        return true;
    }
    else
    {
        return false;
    };
};

Posic insert(Lista L, Item info)
{
    struct lista *ponteiro = L;
    struct listabase *elemento = malloc(sizeof(struct listabase));
    while (ponteiro->l->prox != NULL)
    {
        ponteiro = ponteiro->l->prox;
    };
    ponteiro->l->prox = elemento;
    elemento->ant = ponteiro->l;
    elemento->info = info;
    if (ponteiro->l->posic != NIL)
    {
        elemento->posicao = ponteiro->l->posic + 1;
    }
    else
    {
        elemento->posicao = NIL;
    }
    return elemento->posicao;
};

Item pop(Lista L)
{
    Item elemento;
    struct lista *ponteiro = L;
    if (!isEmpty(L))
    {
        while (ponteiro->l->posicao > 1)
        {
            ponteiro = ponteiro->l->ant;
        };
        Item elemento = ponteiro->l->info;
    }
}
