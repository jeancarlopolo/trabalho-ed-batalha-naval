#ifndef _RETANGULO_H_
#define _RETANGULO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
RETANGULO é um polígono que possui um ponto de origem (âncora definida por x e y), largura, altura,
cor de borda e cor de preenchimento.
*/
typedef void *retangulo;

/** create_retangulo cria um retangulo com os dados passados como parâmetro*/
retangulo create_retangulo(int id, double x, double y, double w, double h, char *corb, char *corp);

/** retangulo_set_i define o id do retângulo*/
void retangulo_set_i(retangulo ret, int id);

/** retangulo_set_x define a coordenada x do retângulo*/
void retangulo_set_x(retangulo ret, double x);

/** retangulo_set_y define a coordenada y do retângulo*/
void retangulo_set_y(retangulo ret, double y);

/** retangulo_set_w define a largura do retângulo*/
void retangulo_set_w(retangulo ret, double w);

/** retangulo_set_h define a altura do retângulo*/
void retangulo_set_h(retangulo ret, double h);

/** retangulo_set_corb define a cor de borda do retângulo*/
void retangulo_set_corb(retangulo ret, char *corb);

/** retangulo_set_corp define a cor de preenchimento do retângulo*/
void retangulo_set_corp(retangulo ret, char *corp);

/** retangulo_get_i retorna o id do retângulo*/
int retangulo_get_i(retangulo ret);

/** retangulo_get_x retorna a coordenada x do retângulo*/
double retangulo_get_x(retangulo ret);

/** retangulo_get_y retorna a coordenada y do retângulo*/
double retangulo_get_y(retangulo ret);

/** retangulo_get_w retorna a largura do retângulo*/
double retangulo_get_w(retangulo ret);

/** retangulo_get_h retorna a altura do retângulo*/
double retangulo_get_h(retangulo ret);

/** retangulo_get_corb retorna a cor de borda do retângulo*/
char *retangulo_get_corb(retangulo ret);

/** retangulo_get_corp retorna a cor de preenchimento do retângulo*/
char *retangulo_get_corp(retangulo ret);

/** retangulo_get_area retorna a area do retângulo*/
double retangulo_get_area(retangulo ret);

/** retangulo_free libera a memória alocada para o retângulo*/
void retangulo_free(retangulo ret);

#endif
