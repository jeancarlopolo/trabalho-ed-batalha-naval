#ifndef _MINA_H_
#define _MINA_H_

#include <stdio.h>
#include <stdlib.h>
#include "texto.h"

typedef void* Mina;

/**
Uma mina é um objeto que pode ser colocado no campo de batalha e que explode quando um barco passa por cima dela
*/

Mina createMina(int id, float x, float y, char* corb, char* corp, char* ancora);

//Cria uma mina

void setMinaId(Mina mina, int id);

//Seta o id da mina

void setMinaX(Mina mina, float x);

//Seta a coordenada x da ancora da mina

void setMinaY(Mina mina, float y);

//Seta a coordenada y da ancora da mina

void setMinaCorb(Mina mina, char* cor);

//Seta a cor da mina

void setMinaCorp(Mina mina, char* cor);

void setMinaAncora(Mina mina, char* ancora);

//Seta a ancora da mina

int getMinaId(Mina mina);

//Retorna o id da mina

float getMinaX(Mina mina);

//Retorna a coordenada x da ancora da mina

float getMinaY(Mina mina);

//Retorna a coordenada y da ancora da mina

char* getMinaCorB(Mina mina);

//Retorna a cor da borda da mina

char* getMinaCorp(Mina mina);

//Retorna a cor de preenchimento da mina

char* getMinaAncora(Mina mina);

//Retorna a ancora da mina

void killMina(Mina mina);

//Libera a memoria alocada para a mina


#endif