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
	while (ponteiroaux->prox != NIL)
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
		while (ponteiroaux->prox != NIL)
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
	Item valor;
	struct lista *ponteiro = L;
	struct listabase *elemento = getFirst(L);
	if (elemento == NIL)
	{
		return NIL;
	}
	else
	{
		valor = elemento->info;
		ponteiro->l = elemento->prox;
		if (ponteiro->l != NIL)
		{
			ponteiro->l->ant = NIL;
		}
		remover(L, elemento);
		return valor;
	};
};

void remover(Lista L, Posic p)
{
	struct lista *ponteiro = L;
	struct listabase *ponteiroaux = ponteiro->l;
	if (!isEmpty(L))
	{
		while (ponteiroaux != p && ponteiroaux->prox != NIL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		if (ponteiroaux != p)
		{
			return;
		}
		else
		{
			if (ponteiroaux->ant != NIL)
			{
				ponteiroaux->ant->prox = ponteiroaux->prox;
			};
			if (ponteiroaux->prox != NIL)
			{
				ponteiroaux->prox->ant = ponteiroaux->ant;
			};
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
		while (ponteiroaux != p && ponteiroaux->prox != NIL)
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
		while (ponteiroaux != p && ponteiroaux->prox != NIL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		if (ponteiroaux != p)
		{
			return NIL;
		}
		else
		{
			struct listabase *elemento = malloc(sizeof(struct listabase));
			ponteiroaux->ant->prox = elemento;
			elemento->ant = ponteiroaux->ant;
			ponteiroaux->ant = elemento;
			elemento->prox = ponteiroaux;
			elemento->info = info;
			return elemento;
		};
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
		while (ponteiroaux != p && ponteiroaux->prox != NIL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		if (ponteiroaux != p)
		{
			return NIL;
		}
		else
		{
			struct listabase *elemento = malloc(sizeof(struct listabase));
			ponteiroaux->prox->ant = elemento;
			elemento->prox = ponteiroaux->prox;
			ponteiroaux->prox = elemento;
			elemento->ant = ponteiroaux;
			elemento->info = info;
			return elemento;
		}
	};
};

Posic getFirst(Lista L)
{
	struct lista *ponteiro = L;
	struct listabase *ponteiroaux = ponteiro->l;
	if (!isEmpty(L))
	{
		while (ponteiroaux->prox != NIL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		while (ponteiroaux->ant != NIL)
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
		while (ponteiroaux != p && ponteiroaux->prox != NIL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		if (ponteiroaux != p || ponteiroaux->prox == NIL)
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
		while (ponteiroaux->ant != NIL)
		{
			ponteiroaux = ponteiroaux->ant;
		};
		while (ponteiroaux->prox != NIL)
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
		while (ponteiroaux != p && ponteiroaux->prox != NIL)
		{
			ponteiroaux = ponteiroaux->prox;
		};
		if (ponteiroaux != p || ponteiroaux->ant == NIL)
		{
			return NIL;
		}
		else
		{
			return ponteiroaux->ant;
		}
	};
};

// void killLista(Lista L)
// {
// 	while (length(L) >= 0)
// 	{
// 		pop(L);
// 	};
// 	struct lista *ponteiro = L;
// 	struct listabase *ponteiroaux = ponteiro->l;
// 	remover(L, ponteiroaux);
// 	free(ponteiro);
// };
