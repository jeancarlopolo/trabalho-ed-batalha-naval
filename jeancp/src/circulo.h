#ifndef _CIRCULO_H
#define _CIRCULO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/**
CIRCULO é um polígono que possui um ponto de origem (âncora definida por x e y), raio, cor de borda e
cor de preenchimento. 
*/
typedef void *circulo;

circulo create_circulo(int id, float x, float y, float r, char* corb, char* corp);

//CREATE_CIRCULO retorna um CIRCULO;

void circulo_set_i(circulo cir, int id);

//CIRCULO_SET_I recebe um CIRCULO e um inteiro e seta o ID do CIRCULO

void circulo_set_x(circulo cir, float x);

//CIRCULO_SET_X recebe um CIRCULO e um float e seta o x da ancora (centro) do CIRCULO

void circulo_set_y(circulo cir, float y);

//CIRCULO_SET_Y recebe um CIRCULO e um float e seta o y da ancora (centro) do CIRCULO

void circulo_set_r(circulo cir, float r);

//CIRCULO_SET_R recebe um CIRCULO e um float e seta o raio do CIRCULO

void circulo_set_corb(circulo cir, char* corb);

//CIRCULO_SET_CORB recebe um CIRCULO e uma char* e seta a cor de borda do CIRCULO

void circulo_set_corp(circulo cir, char* corp);

//CIRCULO_SET_CORP recebe um CIRCULO e uma char* e seta a cor de preenchimento do CIRCULO

int circulo_get_i(circulo cir);

//CIRCULO_GET_I recebe um CIRCULO e retorna o ID do CIRCULO

float circulo_get_x(circulo cir);

//CIRCULO_GET_X recebe um CIRCULO e retorna o x da ancora (centro) do CIRCULO

float circulo_get_y(circulo cir);

//CIRCULO_GET_Y recebe um CIRCULO e retorna o y da ancora (centro) do CIRCULO

float circulo_get_r(circulo cir);

//CIRCULO_GET_R recebe um CIRCULO e retorna o raio do CIRCULO

char* circulo_get_corb(circulo cir);

//CIRCULO_GET_CORB recebe um CIRCULO e retorna a cor de borda do CIRCULO

char* circulo_get_corp(circulo cir);

//CIRCULO_GET_CORP recebe um CIRCULO e retorna a cor de preenchimento do CIRCULO

float circulo_get_area(circulo cir);

//CIRCULO_GET_AREA recebe um CIRCULO e retorna a área do CIRCULO

void circulo_free(circulo cir);

//CIRCULO_FREE recebe um CIRCULO e libera a memória alocada para o mesmou

#endif