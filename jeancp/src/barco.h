#ifndef _BARCO_H
#define _BARCO_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef void* Barco;
typedef char* string;

//Um barco é uma estrutura que contém um tipo de barco e suas informações

Barco createBarco(char id, Item info);

//CREATE_BARCO recebe um caractere que representa o tipo de barco e um item que contém as informações do barco e retorna um barco

char getTipo(Barco b);

//GET_BARCO_TIPO recebe um barco e retorna o caractere que representa o tipo de barco

Item getInfo(Barco b);

//GET_BARCO_INFO recebe um barco e retorna um item que contém as informações do barco
 
void setInfo(Barco b, Item info);

//SET_BARCO_INFO recebe um barco e um item que contém as informações do barco e atualiza as informações do barco

#endif