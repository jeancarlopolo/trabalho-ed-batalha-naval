#ifndef _RETANGULO_H_
#define _RETANGULO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef char *string;
typedef void *retangulo;

/**
RETANGULO é um polígono que possui um ponto de origem (âncora definida por x e y), largura, altura,
cor de borda e cor de preenchimento. O RETANGULO possui um nível de proteção de 60 e um HP de 3. A
pontuação recebida pela sua inativação é 90 e pela sua destruição é 90/(área/5).
**/

retangulo create_retangulo();

//CREATE_RETANGULO retorna um RETANGULO vazio;

void retangulo_set_i(retangulo, int);

//RETANGULO_SET_I recebe um RETANGULO e um inteiro e seta o ID do RETANGULO

void retangulo_set_x(retangulo, float);

//RETANGULO_SET_X recebe um RETANGULO e um float e seta o x da ancora (centro) do RETANGULO

void retangulo_set_y(retangulo, float);

//RETANGULO_SET_Y recebe um RETANGULO e um float e seta o y da ancora (centro) do RETANGULO

void retangulo_set_w(retangulo, float);

//RETANGULO_SET_W recebe um RETANGULO e um float e seta a largura do RETANGULO

void retangulo_set_h(retangulo, float);

//RETANGULO_SET_H recebe um RETANGULO e um float e seta a altura do RETANGULO

void retangulo_set_corb(retangulo, string);

//RETANGULO_SET_CORB recebe um RETANGULO e uma string e seta a cor de borda do RETANGULO

void retangulo_set_corp(retangulo, string);

//RETANGULO_SET_CORP recebe um RETANGULO e uma string e seta a cor de preenchimento do RETANGULO

int retangulo_get_i(retangulo);

//RETANGULO_GET_I recebe um RETANGULO e retorna o ID do RETANGULO

float retangulo_get_x(retangulo);

//RETANGULO_GET_X recebe um RETANGULO e retorna o x da ancora (centro) do RETANGULO

float retangulo_get_y(retangulo);

//RETANGULO_GET_Y recebe um RETANGULO e retorna o y da ancora (centro) do RETANGULO

float retangulo_get_w(retangulo);

//RETANGULO_GET_W recebe um RETANGULO e retorna a largura do RETANGULO

float retangulo_get_h(retangulo);

//RETANGULO_GET_H recebe um RETANGULO e retorna a altura do RETANGULO

string retangulo_get_corb(retangulo);

//RETANGULO_GET_CORB recebe um RETANGULO e retorna a cor de borda do RETANGULO

string retangulo_get_corp(retangulo);

//RETANGULO_GET_CORP recebe um RETANGULO e retorna a cor de preenchimento do RETANGULO

int retangulo_get_np(retangulo);

//RETANGULO_GET_NP recebe um RETANGULO e retorna o nível de proteção do RETANGULO

int retangulo_get_hp(retangulo);

//RETANGULO_GET_HP recebe um RETANGULO e retorna o HP do RETANGULO

float retangulo_get_pontos_inativo(retangulo);

//RETANGULO_GET_PONTOS recebe um RETANGULO e retorna a pontuação por inativar um RETANGULO

float retangulo_get_area(retangulo);

//RETANGULO_GET_AREA recebe um RETANGULO e retorna a área do RETANGULO

float retangulo_get_pontos_destruido(retangulo);

//RETANGULO_GET_PONTOS recebe um RETANGULO e retorna a pontuação por destruir um RETANGULO

void retangulo_free(retangulo);

//RETANGULO_FREE recebe um RETANGULO e libera a memória alocada para o RETANGULO (limpa da memória)

#endif
