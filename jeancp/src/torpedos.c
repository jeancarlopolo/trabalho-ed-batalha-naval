#include "torpedos.h"

void torpedo(Lista lista, float x, float y, FILE *svg)
{
    int i = 0, hp;
    float x1, y1, x2, y2, raio, w, h, pontos = 0;
    Posic elemento = getFirst(lista);
    Posic aux = elemento;
    Barco *barco = get(lista, elemento);
    bool destruido = false;
    char asterisco[10];
    while (elemento != NULL)
    {
        destruido = false;
        switch (getTipo(barco))
        {
        case 'c':
            raio = circulo_get_r(getInfo(barco));
            x1 = circulo_get_x(getInfo(barco));
            y1 = circulo_get_y(getInfo(barco));
            if (sqrt(pow(x - x1, 2) + pow(y - y1, 2)) < raio)
            {
                i++;
                hp = circulo_get_hp(getInfo(barco));
                circulo_set_hp(getInfo(barco), hp - 1);
                if (hp - 1 == 0)
                {
                    destruido = true;
                }
            }
            break;
        case 'r':
            x1 = retangulo_get_x(getInfo(barco));
            y1 = retangulo_get_y(getInfo(barco));
            w = retangulo_get_w(getInfo(barco));
            h = retangulo_get_h(getInfo(barco));
            if (x >= x1 && x <= x1 + w && y >= y1 && y <= y1 + h)
            {
                i++;
                hp = retangulo_get_hp(getInfo(barco));
                retangulo_set_hp(getInfo(barco), hp - 1);
                if (hp - 1 == 0)
                {
                    destruido = true;
                }
            }
            break;
        case 't':
            x1 = texto_get_x(getInfo(barco));
            y1 = texto_get_y(getInfo(barco));
            if (x == x1 && y == y1)
            {
                i++;
                hp = texto_get_hp(getInfo(barco));
                texto_set_hp(getInfo(barco), hp - 1);
                if (hp - 1 == 0)
                {
                    destruido = true;
                }
            }
            break;
        case 'l':
            x1 = linha_get_x(getInfo(barco));
            y1 = linha_get_y(getInfo(barco));
            x2 = linha_get_x2(getInfo(barco));
            y2 = linha_get_y2(getInfo(barco));
            if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
            {
                i++;
                hp = linha_get_hp(getInfo(barco));
                linha_set_hp(getInfo(barco), hp - 1);
                if (hp - 1 == 0)
                {
                    destruido = true;
                }
            }
            break;
        default:
            break;
        }
        if (destruido)
        {
            pontos += getPontuacaoDestruicao(barco);
            // @Geroldor: pega daqui os pontos pra colocar no txt
            aux = elemento;
            elemento = getNext(lista, elemento);
            remover(lista, aux);
            //reportar destruição
        }
        else
        {
            elemento = getNext(lista, elemento);
        }
    }
    if (i > 0)
    {
        sprintf(asterisco, "*%d", i);
        stringSvg(svg, asterisco, x, y, "red", "red", "m");
    }
    else
    {
        stringSvg(svg, "*", x, y, "gray", "gray", "m");
        //AGUA no txt
    }
