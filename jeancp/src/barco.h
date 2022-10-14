#ifndef _BARCO_H
#define _BARCO_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef void* Barco;

/**
Um barco é uma estrutura que contém um id, um item, hp e proteção. Ele pode ser destruído de três maneiras:
1. Seu hp chegar a 0 ao ser bombardeado
2. Seu nível de proteção chegar a 0 ao ser atingido por uma bomba de radiação
3. Ao passar por uma mina
*/

Barco create_barco(char id, Item info);

//CREATE_BARCO recebe um caractere que representa o tipo de barco e um item que contém as informações do barco e retorna um barco

char getTipo(Barco b);

//GET_BARCO_TIPO recebe um barco e retorna o caractere que representa o tipo de barco

Item getInfo(Barco b);

//GET_BARCO_INFO recebe um barco e retorna um item que contém as informações do barco

float getHP(Barco b);

//GET_BARCO_HP recebe um barco e retorna o HP do barco

float getProtecao(Barco b);

//GET_BARCO_PROTECAO recebe um barco e retorna o nível de proteção do barco

float getPontuacaoDesativ(Barco b);

//GET_BARCO_PONTUACAO_DESATIV recebe um barco e retorna a pontuação recebida pela inativação do barco

float getPontuacaoDestruicao(Barco b);

//GET_BARCO_PONTUACAO_DESTRUIR recebe um barco e retorna a pontuação recebida pela destruição do barco

void setInfo(Barco b, Item info);

//SET_BARCO_INFO recebe um barco e um item que contém as informações do barco e seta as informações do barco

void setTipo(Barco b, char tipo);

//SET_BARCO_TIPO recebe um barco e um caractere que representa o tipo de barco e seta o tipo de barco

void setHP(Barco b, float hp);

//SET_BARCO_HP recebe um barco e um float que representa o HP do barco e seta o HP do barco

void setProtecao(Barco b, float protecao);

//SET_BARCO_PROTECAO recebe um barco e um float que representa o nível de proteção do barco e seta o nível de proteção do barco

void freeBarco(Barco b);

//FREE_BARCO recebe um barco e libera a memória alocada para o barco


#endif