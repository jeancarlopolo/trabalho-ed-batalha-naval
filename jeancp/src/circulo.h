#ifndef _CIRCULO_H
#define _CIRCULO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/**
CIRCULO é um polígono que possui um ponto de origem (âncora definida por x e y), raio, cor de borda e
cor de preenchimento. O CIRCULO possui um nível de proteção de 60 e um HP de 2. A pontuação recebida
pela sua inativação é 75 e pela sua destruição é 75/(área/5).
**/

typedef char *string;
typedef void *Circulo;

Circulo create_circulo(int id, float x, float y, float r, string corb, string corp);

//CREATE_CIRCULO retorna um CIRCULO;

void circulo_set_i(Circulo cir, int id);

//CIRCULO_SET_I recebe um CIRCULO e um inteiro e seta o ID do CIRCULO

void circulo_set_x(Circulo cir, float x);

//CIRCULO_SET_X recebe um CIRCULO e um float e seta o x da ancora (centro) do CIRCULO

void circulo_set_y(Circulo cir, float y);

//CIRCULO_SET_Y recebe um CIRCULO e um float e seta o y da ancora (centro) do CIRCULO

void circulo_set_r(Circulo cir, float r);

//CIRCULO_SET_R recebe um CIRCULO e um float e seta o raio do CIRCULO

void circulo_set_corb(Circulo cir, string corb);

//CIRCULO_SET_CORB recebe um CIRCULO e uma string e seta a cor de borda do CIRCULO

void circulo_set_corp(Circulo cir, string corp);

//CIRCULO_SET_CORP recebe um CIRCULO e uma string e seta a cor de preenchimento do CIRCULO

int circulo_get_i(Circulo cir);

//CIRCULO_GET_I recebe um CIRCULO e retorna o ID do CIRCULO

float circulo_get_x(Circulo cir);

//CIRCULO_GET_X recebe um CIRCULO e retorna o x da ancora (centro) do CIRCULO

float circulo_get_y(Circulo cir);

//CIRCULO_GET_Y recebe um CIRCULO e retorna o y da ancora (centro) do CIRCULO

float circulo_get_r(Circulo cir);

//CIRCULO_GET_R recebe um CIRCULO e retorna o raio do CIRCULO

string circulo_get_corb(Circulo cir);

//CIRCULO_GET_CORB recebe um CIRCULO e retorna a cor de borda do CIRCULO

string circulo_get_corp(Circulo cir);

//CIRCULO_GET_CORP recebe um CIRCULO e retorna a cor de preenchimento do CIRCULO

int circulo_get_np(Circulo cir);

//CIRCULO_GET_NP recebe um CIRCULO e retorna o nível de proteção do CIRCULO

int circulo_get_hp(Circulo cir);

//CIRCULO_GET_HP recebe um CIRCULO e retorna o HP do CIRCULO

int circulo_get_pontos_inativo(Circulo cir);

//CIRCULO_GET_PONTOS_INATIVO recebe um CIRCULO e retorna a pontuação recebida pela inativação do CIRCULO

int circulo_get_pontos_destruido(Circulo cir);

//CIRCULO_GET_PONTOS_DESTRUIDO recebe um CIRCULO e retorna a pontuação recebida pela destruição do CIRCULO

float circulo_get_area(Circulo cir);

//CIRCULO_GET_AREA recebe um CIRCULO e retorna a área do CIRCULO

void circulo_free(Circulo cir);

//CIRCULO_FREE recebe um CIRCULO e libera a memória alocada para o mesmo

#endif