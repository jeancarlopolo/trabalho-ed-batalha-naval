#ifndef _M_V_H_
#define _M_V_H_

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "mina.h"
#include "barco.h"
#include "math.h"
#include "svg.h"

/** move_barco move os barcos de acordo com o comando mv*/
double move_barco(Lista barcosSelec, double x, double y, Lista *listaminas, Lista *lista, FILE *svg, int j, int k, FILE *textow);

/** passou_mina verifica se o barco passou por uma mina*/
bool passou_mina(Barco b, double x, double y, Lista *listaminas, Lista *lista, FILE *svg, Lista *listaSelec, FILE *textow);

/** move_retangulo move o retângulo de acordo com o comando mv*/
void move_retangulo(Barco b, double x, double y);

/** move_circulo move o círculo de acordo com o comando mv*/
void move_circulo(Barco b, double x, double y);

/** move_texto move o texto de acordo com o comando mv*/
void move_texto(Barco b, double x, double y);

/** move_linha move a linha de acordo com o comando mv*/
void move_linha(Barco b, double x, double y);

/** escolher_barco escolhe o barco da posição relativa à nau capitã da lista de barcos selecionados*/
Barco escolher_barco(Lista barcosSelec, int j, int k);
#endif