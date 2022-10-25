#ifndef _TORPEDOS_H_
#define _TORPEDOS_H_

#include "lista.h"
#include "barco.h"
#include "math.h"
#include "svg.h"

/**
O torpedo é um tipo de ataque que pode ser disparado contra um navio. Ele reduz a vida do navio em
1 ponto e marca o local onde o torpedo foi disparado com um asterisco vermelho caso tenha atingido
um navio ou um asterisco cinza caso tenha atingido o mar.

Já o torpedo replicante é um tipo de ataque que cria clones dos navios que atingiu. Os clones são
cópias exatas transladadas para uma posição relativa ao navio original. As cores de borda dos clones
são as cores de preenchimento do navio de original e vice versa.
*/

/** Dispara um torpedo nas coordenadas x e y. Retorna a pontuação recebida.*/
double torpedo(Lista lista, double x, double y, FILE *svg, FILE *textow);

/** Dispara um torpedo replicante nas coordenadas x e y que replica barcos atingidos para as coordenadas x1 e y1. */
void torpedo_replicante(Lista lista, double x, double y, double x1, double y1, int id, FILE *svg, FILE *textow);

#endif