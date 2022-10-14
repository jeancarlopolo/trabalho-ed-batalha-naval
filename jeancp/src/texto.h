#ifndef _TEXTO_H
#define _TEXTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/**
TEXTO é um polígono que possui um ponto de origem no início, meio ou fim (âncora definida por x e y), 
conteúdo, cor de borda e cor de preenchimento. O TEXTO possui um nível de proteção de 5 e um HP de 1.
A pontuação recebida pela sua inativação é 30 e pela sua destruição é 500.
**/
typedef void *texto;

texto create_texto(int id, float x, float y, char *corb, char *corp, char *conteudo, char *ancora);

//CREATE_TEXTO retorna um TEXTO;

void texto_set_id(texto text, int id);

//TEXTO_SET_I recebe um TEXTO e um inteiro e seta o ID do TEXTO

void texto_set_ancora(texto text, char* ancora);

//TEXTO_SET_ANCOR recebe um TEXTO e um char e seta a posição da ancora do TEXTO

void texto_set_x(texto text, float x);

//TEXTO_SET_X recebe um TEXTO e um float e seta o x da ancora do TEXTO

void texto_set_y(texto text, float y);

//TEXTO_SET_Y recebe um TEXTO e um float e seta o y da ancora do TEXTO

void texto_set_conteudo(texto text, char* conteudo);

//TEXTO_SET_CONTEUDO recebe um TEXTO e uma char* e seta o conteúdo do TEXTO

void texto_set_corb(texto text, char* corb);

//TEXTO_SET_CORB recebe um TEXTO e uma char* e seta a cor de borda do TEXTO

void texto_set_corp(texto text, char* corp);

//TEXTO_SET_CORP recebe um TEXTO e uma char* e seta a cor de preenchimento do TEXTO

int texto_get_i(texto text);

//TEXTO_GET_I recebe um TEXTO e retorna o ID do TEXTO

char* texto_get_ancora(texto text);

//TEXTO_GET_ANCOR recebe um TEXTO e retorna a posição da ancora do TEXTO

float texto_get_x(texto text);

//TEXTO_GET_X recebe um TEXTO e retorna o x da ancora do TEXTO

float texto_get_y(texto text);

//TEXTO_GET_Y recebe um TEXTO e retorna o y da ancora do TEXTO

char* texto_get_conteudo(texto text);

//TEXTO_GET_CONTEUDO recebe um TEXTO e retorna o conteúdo do TEXTO

char* texto_get_corb(texto text);

//TEXTO_GET_CORB recebe um TEXTO e retorna a cor de borda do TEXTO

char* texto_get_corp(texto text);

//TEXTO_GET_CORP recebe um TEXTO e retorna a cor de preenchimento do TEXTO

void texto_free(texto text);

//TEXTO_FREE recebe um TEXTO e libera a memória alocada para o TEXTO

#endif