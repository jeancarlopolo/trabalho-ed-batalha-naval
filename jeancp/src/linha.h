#ifndef _LINHA_H
#define _LINHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "barco.h"

/**
LINHA é um polígono que possui dois pontos de origem (âncora definida por x e y) e cor. A LINHA possui um
nível de proteção de 50 e um HP de 1. A pontuação recebida pela sua inativação é 50 e pela sua destruição
é 150.
**/

typedef void *Linha;

Linha create_linha(int id, float x1, float y1, float x2, float y2, string cor);

//CREATE_LINHA retorna uma LINHA;

void linha_set_i(Linha li, int i);

//LINHA_SET_I recebe uma LINHA e um inteiro e seta o ID da LINHA

void linha_set_x1(Linha li, float x1);

//LINHA_SET_X1 recebe uma LINHA e um float e seta o x do início da LINHA

void linha_set_y1(Linha li, float y1);

//LINHA_SET_Y1 recebe uma LINHA e um float e seta o y do início da LINHA

void linha_set_x2(Linha li, float x2);

//LINHA_SET_X2 recebe uma LINHA e um float e seta o x do fim da LINHA

void linha_set_y2(Linha li, float y2);

//LINHA_SET_Y2 recebe uma LINHA e um float e seta o y do fim da LINHA

void linha_set_cor(Linha li, string cor);

//LINHA_SET_COR recebe uma LINHA e uma string e seta a cor da LINHA

int linha_get_i(Linha li);

//LINHA_GET_I recebe uma LINHA e retorna o ID da LINHA

float linha_get_x1(Linha li);

//LINHA_GET_X1 recebe uma LINHA e retorna o x do início da LINHA

float linha_get_y1(Linha li);

//LINHA_GET_Y1 recebe uma LINHA e retorna o y do início da LINHA

float linha_get_x2(Linha li);

//LINHA_GET_X2 recebe uma LINHA e retorna o x do fim da LINHA

float linha_get_y2(Linha li);

//LINHA_GET_Y2 recebe uma LINHA e retorna o y do fim da LINHA

string linha_get_cor(Linha li);

//LINHA_GET_COR recebe uma LINHA e retorna a cor da LINHA

void linha_free(Linha li);

//LINHA_FREE recebe uma LINHA e libera a memória alocada para ela

#endif
