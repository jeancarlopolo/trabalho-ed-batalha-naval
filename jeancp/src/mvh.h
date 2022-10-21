#ifndef _M_V_H_
#define _M_V_H_

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "mina.h"
#include "barco.h"
#include "math.h"
#include "svg.h"
//funções de movimentação

/**MOVE_BARCOS move os barcos de acordo com o comando mv*/
void move_barco(Lista barcosSelec, float x, float y, Lista *listaminas, Lista *lista, FILE* svg, int j, int k);

/**passou_mina verifica se o barco passou por uma mina*/
bool passou_mina(Barco b, float x, float y, Lista *listaminas, Lista *lista, FILE* svg, Lista *listaSelec);

/**move_retangulo move o retangulo de acordo com o comando mv*/
void move_retangulo(Barco b, float x, float y);

/**move_circulo move o circulo de acordo com o comando mv*/
void move_circulo(Barco b, float x, float y);

/**move_texto move o texto de acordo com o comando mv*/
void move_texto(Barco b, float x, float y);

/**move_linha move a linha de acordo com o comando mv*/
void move_linha(Barco b, float x, float y);

/**escolher_barco escolhe o barco da posição relativa à nau capitã da lista de barcos selecionados*/
Barco escolher_barco(Lista barcosSelec, int j, int k);
#endif