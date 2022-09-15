#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>

/**
Uma lista e� uma colecao ordenada de itens (ou seja, um elemento possui um antecessor e um sucessor)  em que seus elementos podem
ser acessados atraves de sua posicao (tipo Posic).
Uma lista sem nenhum elemento (comprimento 0) e' denominada lista vazia.

Uma instancia do tipo Posic indica a posicao de um item dentro da lista.
Este tipo possui um valor invalido que indica nao se referir a nenhum item.
Tal valor invalido e' denotado por NIL.
 */

typedef void *Lista;
typedef void *Posic;
typedef void *Item;

#define NIL NULL
#define CAPAC_ILIMITADA -1

/** Retorna uma lista vazia. A lista pode definir um limite maximo de
elementos armazenados (capacidade). Caso capacidade < 0, o tamanho da lista �
ilimitado */
Lista createLista(int capacidade);

/** Retorna o numero de elementos da lista. */
int length(Lista L);

/** Retorna a capacidade da lista. Retorna -1, se a capacidade � ilimitada */
int maxLength(Lista L);

/** Retorna verdadeiro se a lista L estiver vazia */
bool isEmpty(Lista L);

/** Retorna verdadeiro se a lista L estiver cheia. Ou seja, se a lista
   tiver sido criada com uma capacidade m�xima e lenght(L) == maxLength(L). */
bool isFull(Lista L);

/**  Insere o item info no final da lista L. O comprimento da
lista e' acrescido de 1 elemento.
Retorna um indicador para o elemento acrescentado; ou NIL, se a lista estiver
cheia */
Posic insert(Lista L, Item info);

/** Remove e retorna o primeiro elemento da lista L. A lista nao pode
    estar vazia */
Item pop(Lista L);

/** Remove o elemento da lista L indicado por p.  p deve indicar um elemento existente em L. O comprimento da lista e' diminuido de 1 elemento. */
void remover(Lista L, Posic p);

/** Retorna o valor do item da lista indicado por p.
    p deve indicar um elemento existente em L. */
Item get(Lista L, Posic p);

/** Insere o item info na posicao imediatamente anterior ao
item indicado por p. O comprimento da lista e' acrescido de 1 elemento.
Retorna um indicador para o elemento acrescentado. p deve indicar um
elemento existente em L.*/
Posic insertBefore(Lista L, Posic p, Item info);

/** Insere o item info na posicao imediatamente posterior ao
item indicado por p. O comprimento da lista e' acrescido de 1 elemento.
Retorna um indicador para o elemento acrescentado. p deve indicar um
elemento existente em L.*/
Posic insertAfter(Lista L, Posic p, Item info);

/** retorna o indicador do primeiro elemento de L. Se
length(L)=0, retorna NIL. */
Posic getFirst(Lista L);

/** Retorna o indicador do elemento de L seguinte ao elemento
indicado por p. Se p for o ultimo elemento da lista, retorna NIL.
p deve indicar um elemento existente em L.*/
Posic getNext(Lista L, Posic p);

/** Retorna o indicador do ultimo elemento de L. Se
length(L)=0, retorna NIL.*/
Posic getLast(Lista L);

/** Retorna o indicador do elemento de L anterior ao elemento
indicado por p. Se p for o primeiro elemento da lista, retorna NIL.
p deve indicar um elemento existente em L. */
Posic getPrevious(Lista L, Posic p);

/** Libera toda memoria alocada pela lista. */
void killLista(Lista L);

#endif
