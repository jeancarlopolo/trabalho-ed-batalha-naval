#ifndef _M_V_H_
#define _M_V_H_

#include <stdio.h>
#include <stdlib.h>


//funções de movimentação

void move_barco_x(Barco b, int x);
void move_horizontal();
void move_vertical();
void move_barco_y(Barco b, int y);
void passou_mina(circulo cir, lista l, int x, int y);
