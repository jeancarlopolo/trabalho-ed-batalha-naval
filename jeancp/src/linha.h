#ifndef _LINHA_H
#define _LINHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
LINHA é um polígono que possui dois pontos de origem (âncora definida por x e y) e cor.
*/
typedef void *linha;

/** CREATE_LINHA retorna uma LINHA; */
linha create_linha(int id, double x1, double y1, double x2, double y2, char* cor);


/** LINHA_SET_I recebe uma LINHA e um inteiro e seta o ID da LINHA */
void linha_set_i(linha li, int i);


/** LINHA_SET_X1 recebe uma LINHA e um double e seta o x do início da LINHA */
void linha_set_x1(linha li, double x1);


/** LINHA_SET_Y1 recebe uma LINHA e um double e seta o y do início da LINHA */
void linha_set_y1(linha li, double y1);


/** LINHA_SET_X2 recebe uma LINHA e um double e seta o x do fim da LINHA */
void linha_set_x2(linha li, double x2);


/** LINHA_SET_Y2 recebe uma LINHA e um double e seta o y do fim da LINHA */
void linha_set_y2(linha li, double y2);


/** LINHA_SET_COR recebe uma LINHA e uma string e seta a cor da LINHA */
void linha_set_cor(linha li, char* cor);


/** LINHA_GET_I recebe uma LINHA e retorna o ID da LINHA */
int linha_get_i(linha li);


/** LINHA_GET_X1 recebe uma LINHA e retorna o x do início da LINHA */
double linha_get_x1(linha li);


/** LINHA_GET_Y1 recebe uma LINHA e retorna o y do início da LINHA */
double linha_get_y1(linha li);


/** LINHA_GET_X2 recebe uma LINHA e retorna o x do fim da LINHA */
double linha_get_x2(linha li);


/** LINHA_GET_Y2 recebe uma LINHA e retorna o y do fim da LINHA */
double linha_get_y2(linha li);


/** LINHA_GET_COR recebe uma LINHA e retorna a cor da LINHA */
char* linha_get_cor(linha li);


/** LINHA_FREE recebe uma LINHA e libera a memória alocada para ela */
void linha_free(linha li);


#endif
