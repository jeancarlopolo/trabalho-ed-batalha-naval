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

retangulo create_retangulo(int id, double x, double y, double w, double h, char* corb, char* corp);

//CREATE_RETANGULO retorna um RETANGULO;

void retangulo_set_i(retangulo ret, int id);

//RETANGULO_SET_I recebe um RETANGULO e um inteiro e seta o ID do RETANGULO

void retangulo_set_x(retangulo ret, double x);

//RETANGULO_SET_X recebe um RETANGULO e um double e seta o x da ancora (centro) do RETANGULO

void retangulo_set_y(retangulo ret, double y);

//RETANGULO_SET_Y recebe um RETANGULO e um double e seta o y da ancora (centro) do RETANGULO

void retangulo_set_w(retangulo ret, double w);

//RETANGULO_SET_W recebe um RETANGULO e um double e seta a largura do RETANGULO

void retangulo_set_h(retangulo ret, double h);

//RETANGULO_SET_H recebe um RETANGULO e um double e seta a altura do RETANGULO

void retangulo_set_corb(retangulo ret, char* corb);

//RETANGULO_SET_CORB recebe um RETANGULO e uma char* e seta a cor de borda do RETANGULO

void retangulo_set_corp(retangulo ret, char* corp);

//RETANGULO_SET_CORP recebe um RETANGULO e uma char* e seta a cor de preenchimento do RETANGULO

int retangulo_get_i(retangulo ret);

//RETANGULO_GET_I recebe um RETANGULO e retorna o ID do RETANGULO

double retangulo_get_x(retangulo ret);

//RETANGULO_GET_X recebe um RETANGULO e retorna o x da ancora (centro) do RETANGULO

double retangulo_get_y(retangulo ret);

//RETANGULO_GET_Y recebe um RETANGULO e retorna o y da ancora (centro) do RETANGULO

double retangulo_get_w(retangulo ret);

//RETANGULO_GET_W recebe um RETANGULO e retorna a largura do RETANGULO

double retangulo_get_h(retangulo ret);

//RETANGULO_GET_H recebe um RETANGULO e retorna a altura do RETANGULO

char* retangulo_get_corb(retangulo ret);

//RETANGULO_GET_CORB recebe um RETANGULO e retorna a cor de borda do RETANGULO

char* retangulo_get_corp(retangulo ret);

//RETANGULO_GET_CORP recebe um RETANGULO e retorna a cor de preenchimento do RETANGULO

double retangulo_get_area(retangulo ret);

//RETANGULO_GET_AREA recebe um RETANGULO e retorna a área do RETANGULO

void retangulo_free(retangulo ret);

//RETANGULO_FREE recebe um RETANGULO e libera a memória alocada para o mesmo

#endif


