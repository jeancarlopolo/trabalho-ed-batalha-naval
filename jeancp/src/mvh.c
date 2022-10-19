#include "mvh.h"
#include "lista.h"
#include "barco.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "linha.h"
#include "circulo.c"



//movimenta barco horizontalmente (muda o x)

void move_barco_x(Barco b, int x)
{
    switch (getInfo(b))
    {
    case 'r':
        move_retangulo(getRetangulo(b), x, 0);
        break;
    case 'c':
        move_circulo(getCirculo(b), x, 0);
        break;
    case 't':
        move_texto(getTexto(b), x, 0);
        break;
    case 'l':
        move_linha(getLinha(b), x, 0);
        break;
    }   
}

void move_horizontal()
{
    int x;
    printf("Digite a nova posição do barco: ");
    scanf("%d", &x);
    move_barco_x(b, x);
}

void move_vertical()
{
    int y;
    printf("Digite a nova posição do barco: ");
    scanf("%d", &y);
    move_barco_y(b, y);
}

void move_barco_y(Barco b, int y)
{
    switch (getInfo(b))
    {
    case 'r':
        move_retangulo(getRetangulo(b), 0, y);
        break;
    case 'c':
        move_circulo(getCirculo(b), 0, y);
        break;
    case 't':
        move_texto(getTexto(b), 0, y);
        break;
    case 'l':
        move_linha(getLinha(b), 0, y);
        break;
    }   
}

void passou_mina(circulo cir, lista l, int x, int y)
{
    float cx = circulo_get_x(cir);
    float cy = circulo_get_y(cir);
    float r = circulo_get_r(cir);
    float x1 = cx - r;
    float x2 = cx + r;
    float y1 = cy - r;
    float y2 = cy + r;
    if (x1 <= x && x <= x2 && y1 <= y && y <= y2)
    {
        printf("passou por uma mina");
    }
}

