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
    struct listabase *ponteiroaux = ponteiro->l;
    while (ponteiroaux->prox != NULL)
    {
        ponteiroaux = ponteiroaux->prox;
    };
    return ponteiroaux->posicao;
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
    struct listabase *ponteiroaux = ponteiro->l;
    if (isFull(ponteiro))
    {
        return NIL;
    }
    else
    {
        while (ponteiroaux->prox != NULL)
        {
            ponteiroaux = ponteiroaux->prox;
        };
        if (ponteiroaux->posicao != NIL)
        {
            struct listabase *elemento = malloc(sizeof(struct listabase));
            ponteiroaux->prox = elemento;
            elemento->ant = ponteiroaux;
            elemento->info = info;
            return elemento->posicao = (ponteiroaux->posicao) + 1;
        }
        else
        {
            ponteiroaux->info = info;
            return ponteiroaux->posicao = 1;
        };
    };
};

Item pop(Lista L)
{
    Item elemento;
    struct lista *ponteiro = L;
    struct listabase *ponteiroaux = ponteiro->l;
    if (!isEmpty(L))
    {
        while (ponteiroaux->posicao > 1)
        {
            ponteiroaux = ponteiroaux->ant;
        };
        Item elemento = ponteiroaux->info;
        ponteiroaux->prox->ant = NIL;
        free(ponteiroaux);
        return elemento;
    }
};

void remove(Lista L, Posic p)
{
    struct lista *ponteiro = L;
    struct listabase *ponteiroaux = ponteiro->l;
    if (!isEmpty(L))
    {
        while (ponteiroaux->posicao < p && ponteiroaux->prox != NULL)
        {
            ponteiroaux = ponteiroaux->prox;
        };
        if (ponteiroaux->posicao < p)
        {
            return;
        };
        ponteiroaux->ant->prox = ponteiroaux->prox;
        ponteiroaux->prox->ant = ponteiroaux->ant;
        free(ponteiroaux);
    };
};
