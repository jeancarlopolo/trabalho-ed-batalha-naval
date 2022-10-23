#ifndef _BARCO_H
#define _BARCO_H

#include "linha.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"

/**
Um barco é uma estrutura que contém um id, um id de capitão, um item, hp, proteção. Ele pode ser destruído de três maneiras:
1. Seu hp chegar a 0 ao ser bombardeado
2. Seu nível de proteção chegar a 0 ao ser atingido por uma bomba de radiação
3. Ao passar por uma mina
*/
typedef void *Barco;

/** Aloca memória para um barco e inicializa seus valores */
Barco create_barco(char id, void *info);

/** Retorna o tipo de um barco */
char barco_get_tipo(Barco b);

/** Retorna o item que o barco carrega */
void *barco_get_info(Barco b);

/** Retorna o hp de um barco */
int barco_get_hp(Barco b);

/** Retorna o nível de proteção de um barco */
double barco_get_protecao(Barco b);

/** Retorna a pontuação recebida pela inativação de um barco */
double barco_get_point_desat(Barco b);

/** Retorna a pontuação recebida pela destruição de um barco */
double barco_get_point_destr(Barco b);

/** Seta o item que o barco carrega */
void barco_set_info(Barco b, void *info);

/** Seta o tipo de um barco */
void barco_set_tipo(Barco b, char tipo);

/** Seta o hp de um barco */
void barco_set_hp(Barco b, int hp);

/** Seta o nível de proteção de um barco */
void barco_set_protecao(Barco b, double protecao);

/** Libera a memória alocada para um barco */
void barco_kill(Barco b);

/** Retorna a coordenada x do barco */
double barco_get_x(Barco b);

/** Retorna a coordenada y do barco */
double barco_get_y(Barco b);

/** Retorna o id de capitão do barco */
int barco_get_capitaoid(Barco b);

/** Seta o id de capitão do barco */
void barco_set_capitaoid(Barco b, int capitao);

/** Retorna o id do barco */
int barco_get_id(Barco b);

#endif