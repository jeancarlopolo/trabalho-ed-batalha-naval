#ifndef _CIRCULO_H
#define _CIRCULO_H

#include <string.h>
#include "lista.h"
#include "barco.h"

/**
CIRCULO é um polígono que possui um ponto de origem (âncora definida por x e y), raio, cor de borda e
cor de preenchimento.
*/
typedef void *circulo;

/** create_circulo cria um círculo com os dados passados como parâmetro*/
circulo create_circulo(int id, double x, double y, double r, char *corb, char *corp);

/** circulo_set_i define o id do círculo*/
void circulo_set_i(circulo cir, int id);

/** circulo_set_x define a coordenada x do círculo*/
void circulo_set_x(circulo cir, double x);

/** circulo_set_y define a coordenada y do círculo*/
void circulo_set_y(circulo cir, double y);

/** circulo_set_r define o raio do círculo*/
void circulo_set_r(circulo cir, double r);

/** circulo_set_corb define a cor de borda do círculo*/
void circulo_set_corb(circulo cir, char *corb);

/** circulo_set_corp define a cor de preenchimento do círculo*/
void circulo_set_corp(circulo cir, char *corp);

/** circulo_get_i retorna o id do círculo*/
int circulo_get_i(circulo cir);

/** circulo_get_x retorna a coordenada x do círculo*/
double circulo_get_x(circulo cir);

/** circulo_get_y retorna a coordenada y do círculo*/
double circulo_get_y(circulo cir);

/** circulo_get_r retorna o raio do círculo*/
double circulo_get_r(circulo cir);

/** circulo_get_corb retorna a cor de borda do círculo*/
char *circulo_get_corb(circulo cir);

/** circulo_get_corp retorna a cor de preenchimento do círculo*/
char *circulo_get_corp(circulo cir);

/** circulo_get_area retorna a area do círculo*/
double circulo_get_area(circulo cir);

/** circulo_free libera a memória alocada para o círculo*/
void circulo_free(circulo cir);

#endif