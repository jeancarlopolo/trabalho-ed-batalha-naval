#include "bomba.h"

float calcular_reducao(float area, float r, float na)
{
    float reducao = 0;
    float pi = 3.14159265358979323846;
    r = r * r * pi;
    reducao = (area * na) / r;
    return reducao;
}

void bomba_rad(Lista *l, float x, float y, float r, float na, FILE *svg)
{
    int np;
    float x1, y1, x2, y2, raio, w, h, pontos = 0, area;
    Posic elemento = getFirst(l);
    Posic aux = elemento;
    Barco *barco = get(l, elemento);
    bool desativado = false;
    while (elemento != NULL)
    {
        desativado = false;
        barco = get(l, elemento);
        switch (getTipo(barco))
        {
        case 'c':
            raio = circulo_get_r(getInfo(barco));
            x1 = circulo_get_x(getInfo(barco));
            y1 = circulo_get_y(getInfo(barco));
            if (sqrt(((x - x1) * (x - x1)) + ((y - y1) * (y - y1))) + r <= raio)
            {
                np = getProtecao(barco);
                area = circulo_get_area(getInfo(barco));
                setProtecao(barco, np - calcular_reducao(area, r, na));
                if (getProtecao(barco) <= 0)
                {
                    desativado = true;
                }
                // ponto vermelho na âncora do barco atingido
                fprintf(svg, "<circle cx=\"%f\" cy=\"%f\" r=\"2\" fill=\"red\" stroke=\"red\" stroke-width=\"1\"/>\n", x1, y1);
            }
            break;
        case 'r':
            x1 = retangulo_get_x(getInfo(barco));
            y1 = retangulo_get_y(getInfo(barco));
            w = retangulo_get_w(getInfo(barco));
            h = retangulo_get_h(getInfo(barco));
            if (x + r >= x1 && x - r <= x1 + w && y + r >= y1 && y - r <= y1 + h)
            {
                np = getProtecao(barco);
                area = retangulo_get_area(getInfo(barco));
                setProtecao(barco, np - calcular_reducao(area, r, na));
                if (getProtecao(barco) <= 0)
                {
                    desativado = true;
                }
                // ponto vermelho na âncora do barco atingido
                fprintf(svg, "<circle cx=\"%f\" cy=\"%f\" r=\"2\" fill=\"red\" stroke=\"red\" stroke-width=\"1\"/>\n", x1, y1);
            }
            break;
        case 't':
            x1 = texto_get_x(getInfo(barco));
            y1 = texto_get_y(getInfo(barco));
            if (sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)) < r)
            {
                np = getProtecao(barco);
                setProtecao(barco, np - calcular_reducao(0.1, r, na));
                if (getProtecao(barco) <= 0)
                {
                    desativado = true;
                }
                // ponto vermelho na âncora do barco atingido
                fprintf(svg, "<circle cx=\"%f\" cy=\"%f\" r=\"2\" fill=\"red\" stroke=\"red\" stroke-width=\"1\"/>\n", x1, y1);
            }
            break;
        case 'l':
            x1 = linha_get_x1(getInfo(barco));
            y1 = linha_get_y1(getInfo(barco));
            x2 = linha_get_x2(getInfo(barco));
            y2 = linha_get_y2(getInfo(barco));
            if (sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)) < r || sqrt(pow(x2 - x, 2) + pow(y2 - y, 2)) < r)
            {
                np = getProtecao(barco);
                setProtecao(barco, np - calcular_reducao((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1), r, na));
                if (getProtecao(barco) <= 0)
                {
                    desativado = true;
                }
                // ponto vermelho na âncora do barco atingido
                fprintf(svg, "<circle cx=\"%f\" cy=\"%f\" r=\"2\" fill=\"red\" stroke=\"red\" stroke-width=\"1\"/>\n", x1, y1);
            }
            break;
        default:
            break;
        }
        if (desativado)
        {
            pontos += getPontuacaoDesativ(barco);
            // @Geroldor: pega daqui os pontos pra colocar no txt
            aux = elemento;
            elemento = getNext(l, elemento);
            remover(l, aux);
            // reportar destruição
        }
        else
        {
            elemento = getNext(l, elemento);
        }
    }
    //círculo da bomba pontilhado
    fprintf(svg, "<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"none\" stroke=\"red\" stroke-dasharray=\"5,5\" stroke-width=\"1\"/>\n", x, y, r);
}
