#ifndef _BOMBA_H_
#define _BOMBA_H_

#include "lista.h"
#include "math.h"
#include "svg.h"

/** Calcula a redução de proteção de uma embarcação atingida pela bomba*/
double calcular_reducao(double area, double r, double na);

/** Bomba de radiação atinge o local especificado. Retorna a pontuação recebida.*/
double bomba_rad(Lista *l, double x, double y, double r, double na, FILE *svg, FILE *textow);

#endif