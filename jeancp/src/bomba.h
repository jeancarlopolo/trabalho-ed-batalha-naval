#ifndef _BOMBA_H_
#define _BOMBA_H_

#include "barco.h"
#include "lista.h"
#include "math.h"
#include "svg.h"

/** Calcula a redução de proteção de uma embarcação atingida pela bomba*/
float calcular_reducao(float area, float r, float na);

/** Bomba de radiação atinge o local especificado */
void bomba_rad(Lista *l, float x, float y, float r, float na, FILE *svg, FILE *textow);

#endif