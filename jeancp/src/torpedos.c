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
            // reportar destruição
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
        // AGUA no txt
    }
}

void torpedo_replicante(Lista lista, float x, float y, float x1, float y1, int id, FILE *svg)
{
    int hp, contador = 0;
    float x2, y2, x3, y3, raio, w, h;
    Posic elemento = getFirst(lista);
    Posic aux = elemento;
    Barco *barco = get(lista, elemento);
    char arroba[10], *corb, *corp, *texto, *ancora;
    while (elemento != NULL)
    {
        switch (getTipo(barco))
        {
        case 'c':
            raio = circulo_get_r(getInfo(barco));
            x2 = circulo_get_x(getInfo(barco));
            y2 = circulo_get_y(getInfo(barco));
            if (sqrt(pow(x - x2, 2) + pow(y - y2, 2)) < raio)
            {
                corb = circulo_get_corb(getInfo(barco));
                corp = circulo_get_corp(getInfo(barco));
                Barco *circle = create_barco('c', create_circulo(id + contador, x2 + x1, y2 + y1, raio, corp, corb));
                insert(lista, circle);
            }
            break;
        case 'r':
            x2 = retangulo_get_x(getInfo(barco));
            y2 = retangulo_get_y(getInfo(barco));
            w = retangulo_get_w(getInfo(barco));
            h = retangulo_get_h(getInfo(barco));
            if (x >= x2 && x <= x2 + w && y >= y2 && y <= y2 + h)
            {
                corb = retangulo_get_corb(getInfo(barco));
                corp = retangulo_get_corp(getInfo(barco));
                Barco *rectangle = create_barco('r', create_retangulo(id + contador, x2 + x1, y2 + y1, w, h, corp, corb));
                insert(lista, rectangle);
            }
            break;
        case 't':
            x2 = texto_get_x(getInfo(barco));
            y2 = texto_get_y(getInfo(barco));
            if (x == x2 && y == y2)
            {
                corb = texto_get_corb(getInfo(barco));
                corp = texto_get_corp(getInfo(barco));
                texto = texto_get_texto(getInfo(barco));
                ancora = texto_get_ancora(getInfo(barco));
                Barco *text = create_barco('t', create_texto(id + contador, x2 + x1, y2 + y1, corp, corb, texto, ancora));
                insert(lista, text);
            }
            break;
        case 'l':
            x2 = linha_get_x(getInfo(barco));
            y2 = linha_get_y(getInfo(barco));
            x3 = linha_get_x2(getInfo(barco));
            y3 = linha_get_y2(getInfo(barco));
            if (x >= x2 && x <= x3 && y >= y2 && y <= y3)
            {
                corb = linha_get_cor(getInfo(barco));
                Barco *line = create_barco('l', create_linha(id + contador, x2 + x1, y2 + y1, x3 + x1, y3 + y1, corb));
                insert(lista, line);
            }
            break;
        default:
            break;
        }
        contador++;
        elemento = getNext(lista, elemento);
    }
    stringSvg(svg, "@", x, y, "red", "red", "m");
}