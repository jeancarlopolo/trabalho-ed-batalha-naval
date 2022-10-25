#ifndef _LINHA_H
#define _LINHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
linha é um polígono que possui dois pontos de origem (âncora definida por x e y) e cor.
*/
typedef void *linha;

/** create_linha retorna uma linha; */
linha create_linha(int id, double x1, double y1, double x2, double y2, char *cor);

/** linha_set_i recebe uma linha e um inteiro e seta o id da linha */
void linha_set_i(linha li, int i);

/** linha_set_x1 recebe uma linha e um double e seta o x do início da linha */
void linha_set_x1(linha li, double x1);

/** linha_set_y1 recebe uma linha e um double e seta o y do início da linha */
void linha_set_y1(linha li, double y1);

/** linha_set_x2 recebe uma linha e um double e seta o x do fim da linha */
void linha_set_x2(linha li, double x2);

/** linha_set_y2 recebe uma linha e um double e seta o y do fim da linha */
void linha_set_y2(linha li, double y2);

/** linha_set_cor recebe uma linha e uma string e seta a cor da linha */
void linha_set_cor(linha li, char *cor);

/** linha_get_i recebe uma linha e retorna o id da linha */
int linha_get_i(linha li);

/** linha_get_x1 recebe uma linha e retorna o x do início da linha */
double linha_get_x1(linha li);

/** linha_get_y1 recebe uma linha e retorna o y do início da linha */
double linha_get_y1(linha li);

/** linha_get_x2 recebe uma linha e retorna o x do fim da linha */
double linha_get_x2(linha li);

/** linha_get_y2 recebe uma linha e retorna o y do fim da linha */
double linha_get_y2(linha li);

/** linha_get_cor recebe uma linha e retorna a cor da linha */
char *linha_get_cor(linha li);

/** linha_free recebe uma linha e libera a memória alocada para ela */
void linha_free(linha li);

#endif
