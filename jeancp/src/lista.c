#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct listabase
{
	Item info;
	struct listabase *prox;
	struct listabase *ant;
};

struct lista
{
	struct listabase *l;
	int capacidade;
};

Lista createLista(int capacidade)
{
	struct lista *L = malloc(sizeof(struct lista));
	struct listabase *l = L->l = malloc(sizeof(struct listabase));
	l->ant = NIL;
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
};

int length(Lista L)
{
	struct lista *ponteiro = L;
	struct listabase *ponteiroaux = ponteiro->l;
	int i = 0;
	while (ponteiroaux->prox != NULL)
	{
		ponteiroaux = ponteiroaux->prox;
		i++;
	};
	return i;
};

int maxLength(Lista L)
{
	struct lista *ponteiro = L;
	return ponteiro->capacidade;
};

bool isEmpty(Lista L)
{
	struct lista *ponteiro = L;
	if (ponteiro->l->prox == NIL && ponteiro->l->ant == NIL && ponteiro->l->info == NIL)
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
	if (isFull(L))
	{
		return NIL;
	}
	else
	{
		while (ponteiroaux->prox != NULL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		if (!isEmpty(L))
		{
			struct listabase *elemento = malloc(sizeof(struct listabase));
			ponteiroaux->prox = elemento;
			elemento->ant = ponteiroaux;
			elemento->info = info;
			return elemento;
		}
		else
		{
			ponteiroaux->info = info;
			return ponteiroaux;
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
		while (ponteiroaux->ant != NIL)
		{
			ponteiroaux = ponteiroaux->ant;
		};
		Item elemento = ponteiroaux->info;
		ponteiroaux->prox->ant = NIL;
		free(ponteiroaux);
		return elemento;
	}
};

void remover(Lista L, Posic p)
{
	struct lista *ponteiro = L;
	struct listabase *ponteiroaux = ponteiro->l;
	if (!isEmpty(L))
	{
		while (ponteiroaux != p && ponteiroaux->prox != NULL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		if (ponteiroaux != p)
		{
			return;
		}
		else
		{
			ponteiroaux->ant->prox = ponteiroaux->prox;
			ponteiroaux->prox->ant = ponteiroaux->ant;
			free(ponteiroaux);
		}
	};
};

Item get(Lista L, Posic p)
{
	struct lista *ponteiro = L;
	struct listabase *ponteiroaux = ponteiro->l;
	if (!isEmpty(L))
	{
		while (ponteiroaux != p && ponteiroaux->prox != NULL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		if (ponteiroaux != p)
		{
			return NIL;
		}
		else
		{
			return ponteiroaux->info;
		}
	};
};

Posic insertBefore(Lista L, Posic p, Item info)
{
	struct lista *ponteiro = L;
	struct listabase *ponteiroaux = ponteiro->l;
	if (isFull(L))
	{
		return NIL;
	}
	else
	{
		while (ponteiroaux != p && ponteiroaux->prox != NULL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		if (ponteiroaux != p)
		{
			return NIL;
		}
		struct listabase *elemento = malloc(sizeof(struct listabase));
		elemento->info = info;
		elemento->prox = ponteiroaux;
		elemento->ant = ponteiroaux->ant;
		ponteiroaux->ant->prox = elemento;
		ponteiroaux->ant = elemento;
		return elemento;
	};
};

Posic insertAfter(Lista L, Posic p, Item info)
{
	struct lista *ponteiro = L;
	struct listabase *ponteiroaux = ponteiro->l;
	if (isFull(L))
	{
		return NIL;
	}
	else
	{
		while (ponteiroaux != p && ponteiroaux->prox != NULL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		if (ponteiroaux != p)
		{
			return NIL;
		}
		struct listabase *elemento = malloc(sizeof(struct listabase));
		elemento->info = info;
		elemento->prox = ponteiroaux->prox;
		elemento->ant = ponteiroaux;
		ponteiroaux->prox->ant = elemento;
		ponteiroaux->prox = elemento;
		ponteiroaux = elemento->prox;
		return elemento;
	};
};

Posic getFirst(Lista L)
{
	struct lista *ponteiro = L;
	struct listabase *ponteiroaux = ponteiro->l;
	if (!isEmpty(L))
	{
		while (ponteiroaux->ant != NULL)
		{
			ponteiroaux = ponteiroaux->ant;
		};
		return ponteiroaux;
	}
	else
	{
		return NIL;
	};
};

Posic getNext(Lista L, Posic p)
{
	struct lista *ponteiro = L;
	struct listabase *ponteiroaux = ponteiro->l;
	if (!isEmpty(L))
	{
		while (ponteiroaux != p && ponteiroaux->prox != NULL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		if (ponteiroaux != p || ponteiroaux->prox == NULL)
		{
			return NIL;
		}
		else
		{
			return ponteiroaux->prox;
		}
	};
};

Posic getLast(Lista L)
{
	struct lista *ponteiro = L;
	struct listabase *ponteiroaux = ponteiro->l;
	if (!isEmpty(L))
	{
		while (ponteiroaux->prox != NULL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		return ponteiroaux;
	}
	else
	{
		return NIL;
	};
};

Posic getPrevious(Lista L, Posic p)
{
	struct lista *ponteiro = L;
	struct listabase *ponteiroaux = ponteiro->l;
	if (!isEmpty(L))
	{
		while (ponteiroaux != p && ponteiroaux->prox != NULL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		if (ponteiroaux != p || ponteiroaux->ant == NULL)
		{
			return NIL;
		}
		else
		{
			return ponteiroaux->ant;
		}
	};
};

void killLista(Lista L)
{
	struct lista *ponteiro = L;
	struct listabase *ponteiroaux = ponteiro->l;
	while (ponteiroaux->prox != NULL)
	{
		ponteiroaux = ponteiroaux->prox;
	};
	while (ponteiroaux->ant != NULL)
	{
		ponteiroaux = ponteiroaux->ant;
		free(ponteiroaux->prox);
	};
	free(ponteiroaux);
	free(ponteiro);
};

// int main(int argc, char const *argv[])
// {
// 	Lista L = createLista(7);
// 	Posic p = insert(L, (Item)1);
// 	Posic p2 = insert(L, (Item)2);
// 	Posic p3 = insert(L, (Item)3);
// 	Posic p4 = insert(L, (Item)4);
// 	Posic p5 = insert(L, (Item)5);
// 	Posic p6 = insert(L, (Item)6);
// 	Posic p7 = insert(L, (Item)7);
// 	Posic p8 = insert(L, (Item)8);
// 	bool teste = isEmpty(L);
// 	bool teste2 = isFull(L);
// 	int teste3 = length(L);
// 	Posic teste4 = getFirst(L);
// 	Posic teste5 = getLast(L);
// 	Posic teste6 = getNext(L, p3);
// 	Posic teste7 = getPrevious(L, p6);
// 	Item teste8 = get(L, p2);
// 	int teste9 = maxLength(L);
// 	remover(L, p2);
// 	Item teste10 = pop(L);
// 	Posic teste11 = insertBefore(L, p3, (Item)9);
// 	Posic teste12 = insertAfter(L, p3, (Item)10);
// 	killLista(L);
// 	return 0;
// }
