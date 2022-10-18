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
*/

/** Dispara um torpedo nas coordenadas x e y. */
void torpedo(Lista lista, float x, float y, FILE *svg);


#endif