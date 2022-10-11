#include "lista.h"

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
	struct listanode *l = L->l = malloc(sizeof(struct listanode));
	l->prox = NIL;
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
	struct lista *ponteiro = L;
	struct listanode *ponteironode = ponteiro->l;
	int i = 0;
	if (ponteironode != NIL)
	{
		if (ponteironode->info != NIL)
		{
			i++;
		}
		while (ponteironode->prox != NIL)
		{
			ponteironode = ponteironode->prox;
			i++;
		}
	}
	return i;
}

int maxLength(Lista L)
{
	struct lista *ponteiro = L;
	return ponteiro->capacidade;
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
	struct lista *ponteiro = L;
	if (ponteiro->capacidade != CAPAC_ILIMITADA && length(ponteiro) >= maxLength(ponteiro))
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
	struct lista *ponteiro = L;
	struct listanode *ponteironode = ponteiro->l;
	if (isFull(L))
	{
		return NIL;
	}
	else
	{
		while (ponteironode->prox != NIL)
		{
			ponteironode = ponteironode->prox;
		}
		if (!isEmpty(L))
		{
			struct listanode *elemento = malloc(sizeof(struct listanode));
			ponteironode->prox = elemento;
			elemento->prox = NIL;
			elemento->info = info;
			return elemento;
		}
		else
		{
			ponteironode->info = info;
			return ponteironode;
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
	struct lista *ponteiro = L;
	struct listanode *ponteironode = ponteiro->l;
	if (!isEmpty(L))
	{
		if (p == getFirst(L))
		{
			ponteiro->l = ponteironode->prox;
			ponteironode->info = NIL;
			ponteironode->prox = NIL;
			free(ponteironode);
		}
		else
		{
			while (ponteironode->prox != p)
			{
				ponteironode = ponteironode->prox;
			}
			ponteironode->prox->info = NIL;
			ponteironode->prox = ponteironode->prox->prox;
			free(p);
		}
	}
}

Item get(Lista L, Posic p)
{
	struct lista *ponteiro = L;
	struct listanode *ponteironode = ponteiro->l;
	if (!isEmpty(L))
	{
		ponteironode = p;
		return ponteironode->info;
	}
	else
	{
		return NIL;
	}
}

Posic insertBefore(Lista L, Posic p, Item info)
{
	struct lista *ponteiro = L;
	struct listanode *ponteiroantes = ponteiro->l;
	struct listanode *ponteironode = p;
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
			elemento->prox = ponteironode;
			ponteiro->l = elemento;
			return elemento;
		}
		else
		{
			while (ponteiroantes->prox != p)
			{
				ponteiroantes = ponteiroantes->prox;
			}
			struct listanode *elemento = malloc(sizeof(struct listanode));
			elemento->info = info;
			elemento->prox = ponteironode;
			ponteiroantes->prox = elemento;
			return elemento;
		}
	}
}

Posic insertAfter(Lista L, Posic p, Item info)
{
	struct lista *ponteiro = L;
	struct listanode *ponteironode = ponteiro->l;
	if (isFull(L))
	{
		return NIL;
	}
	else
	{
		ponteironode = p;
		struct listanode *elemento = malloc(sizeof(struct listanode));
		elemento->prox = ponteironode->prox;
		ponteironode->prox = elemento;
		elemento->info = info;
		return elemento;
	}
}

Posic getFirst(Lista L)
{
	struct lista *ponteiro = L;
	return ponteiro->l;
}

Posic getNext(Lista L, Posic p)
{
	struct lista *ponteiro = L;
	struct listanode *ponteironode = ponteiro->l;
	if (!isEmpty(L))
	{
		ponteironode = p;
		return ponteironode->prox;
	}
}

Posic getLast(Lista L)
{
	struct lista *ponteiro = L;
	struct listanode *ponteironode = ponteiro->l;
	if (!isEmpty(L))
	{
		while (ponteironode->prox != NIL)
		{
			ponteironode = ponteironode->prox;
		}
		return ponteironode;
	}
	else
	{
		return NIL;
	}
}

Posic getPrevious(Lista L, Posic p)
{
	struct lista *ponteiro = L;
	struct listanode *ponteironode = ponteiro->l;
	if (!isEmpty(L))
	{
		while (ponteironode->prox != p)
		{
			ponteironode = ponteironode->prox;
		}
		return ponteironode;
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


