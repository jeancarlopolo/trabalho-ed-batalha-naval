#include "lista.h"
#include "barco.h"

struct listanode
{
	Item info;
	struct listanode *prox;
};

struct lista
{
	struct listanode *l;
	int capacidade;
};

Lista createLista(int capacidade)
{
	struct lista *L = malloc(sizeof(struct lista));
	struct listanode *l = malloc(sizeof(struct listanode));
	L->l = l;
	l->prox = NIL;
	l->info = NIL;
	if (capacidade < 0)
	{
		L->capacidade = CAPAC_ILIMITADA;
	}
	else
	{
		L->capacidade = capacidade;
	}
	return L;
}

int length(Lista L)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	int i = 0;
	if (pointernode != NIL)
	{
		if (pointernode->info != NIL)
		{
			i++;
		}
		while (pointernode->prox != NIL)
		{
			pointernode = pointernode->prox;
			i++;
		}
	}
	return i;
}

int maxLength(Lista L)
{
	struct lista *pointer = L;
	return pointer->capacidade;
}

bool isEmpty(Lista L)
{
	if (length(L) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull(Lista L)
{
	struct lista *pointer = L;
	if (pointer->capacidade != CAPAC_ILIMITADA && length(pointer) >= maxLength(pointer))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Posic insert(Lista L, Item info)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (isFull(L))
	{
		return NIL;
	}
	else
	{
		while (pointernode->prox != NIL)
		{
			pointernode = pointernode->prox;
		}
		if (!isEmpty(L))
		{
			struct listanode *elemento = malloc(sizeof(struct listanode));
			pointernode->prox = elemento;
			elemento->prox = NIL;
			elemento->info = info;
			return elemento;
		}
		else
		{
			pointernode->info = info;
			return pointernode;
		}
	}
}

Item pop(Lista L)
{
	Item valor;
	struct listanode *elemento = getFirst(L);
	if (elemento == NIL)
	{
		return NIL;
	}
	else
	{
		valor = elemento->info;
		remover(L, elemento);
		return valor;
	}
}

void remover(Lista L, Posic p)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (!isEmpty(L))
	{
		if (p == getFirst(L))
		{
			pointer->l = pointernode->prox;
			if (pointernode->info != NIL)
			{
				barco_kill(pointernode->info);
			}
			pointernode->prox = NIL;
			free(pointernode);
		}
		else
		{
			while (pointernode->prox != p)
			{
				pointernode = pointernode->prox;
			}
			if (pointernode->prox->info != NIL)
			{
				barco_kill(pointernode->prox->info);
			}
			pointernode->prox = pointernode->prox->prox;
			free(p);
		}
	}
}

Item get(Lista L, Posic p)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (!isEmpty(L))
	{
		pointernode = p;
		return pointernode->info;
	}
	else
	{
		return NIL;
	}
}

Posic insertBefore(Lista L, Posic p, Item info)
{
	struct lista *pointer = L;
	struct listanode *pointerantes = pointer->l;
	struct listanode *pointernode = p;
	if (isFull(L))
	{
		return NIL;
	}
	else
	{
		if (p == getFirst(L))
		{
			struct listanode *elemento = malloc(sizeof(struct listanode));
			elemento->info = info;
			elemento->prox = pointernode;
			pointer->l = elemento;
			return elemento;
		}
		else
		{
			while (pointerantes->prox != p)
			{
				pointerantes = pointerantes->prox;
			}
			struct listanode *elemento = malloc(sizeof(struct listanode));
			elemento->info = info;
			elemento->prox = pointernode;
			pointerantes->prox = elemento;
			return elemento;
		}
	}
}

Posic insertAfter(Lista L, Posic p, Item info)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (isFull(L))
	{
		return NIL;
	}
	else
	{
		pointernode = p;
		struct listanode *elemento = malloc(sizeof(struct listanode));
		elemento->prox = pointernode->prox;
		pointernode->prox = elemento;
		elemento->info = info;
		return elemento;
	}
}

Posic getFirst(Lista L)
{
	struct lista *pointer = L;
	return pointer->l;
}

Posic getNext(Lista L, Posic p)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (!isEmpty(L))
	{
		pointernode = p;
		return pointernode->prox;
	}
	else
	{
		return NIL;
	}
}

Posic getLast(Lista L)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (!isEmpty(L))
	{
		while (pointernode->prox != NIL)
		{
			pointernode = pointernode->prox;
		}
		return pointernode;
	}
	else
	{
		return NIL;
	}
}

Posic getPrevious(Lista L, Posic p)
{
	struct lista *pointer = L;
	struct listanode *pointernode = pointer->l;
	if (!isEmpty(L))
	{
		while (pointernode->prox != p)
		{
			pointernode = pointernode->prox;
		}
		return pointernode;
	}
	else
	{
		return NIL;
	}
}

void killLista(Lista L)
{
	while (!isEmpty(L))
	{
		remover(L, getFirst(L));
	}
	free(L);
}
