#include "mvh.h"

void move_retangulo(Barco b, float x, float y)
{
    retangulo r = getInfo(b);
    retangulo_set_x(r, x);
    retangulo_set_y(r, y);
}

void move_circulo(Barco b, float x, float y)
{
    circulo c = getInfo(b);
    circulo_set_x(c, x);
    circulo_set_y(c, y);
}

void move_texto(Barco b, float x, float y)
{
    texto t = getInfo(b);
    texto_set_x(t, x);
    texto_set_y(t, y);
}

void move_linha(Barco b, float x, float y)
{
    linha l = getInfo(b);
    linha_set_x1(l, x);
    linha_set_y1(l, y);
    linha_set_x2(l, x);
    linha_set_y2(l, y);
}

void move_barco(Lista *barcosSelec, float x, float y, Lista *listaminas, Lista *lista, FILE *svg)
{
    Posic elemento = getFirst(barcosSelec);
    float xfinal, yfinal, pontos = 0;
    xfinal = x + barco_get_x(getInfo(elemento));
    yfinal = y + barco_get_y(getInfo(elemento));
    while (elemento != NULL)
    {
        if (!passou_mina(barcosSelec, x, y, listaminas, lista, svg, barcosSelec))
        {
            switch (getTipo(barcosSelec))
            {
            case 'r':
                move_retangulo(getInfo(barcosSelec), xfinal, yfinal);
                break;
            case 'c':
                move_circulo(getInfo(barcosSelec), xfinal, yfinal);
                break;
            case 't':
                move_texto(getInfo(barcosSelec), xfinal, yfinal);
                break;
            case 'l':
                move_linha(getInfo(barcosSelec), xfinal, yfinal);
                break;
            }
        }
        else
        {
            pontos += getPontuacaoDestruicao(elemento);
        }
        elemento = getNext(barcosSelec, elemento);
    }
}

bool passou_mina(Barco b, float xend, float yend, Lista *listaminas, Lista *lista, FILE *svg, Lista *listaSelec)
{

    Posic elemento = getFirst(listaminas);
    switch (getTipo(b))
    {
    case 'c':
        float xmina = mina_get_x(getInfo(elemento));
        float ymina = mina_get_y(getInfo(elemento));
        float raio = circulo_get_r(getInfo(b));
        float x = circulo_get_x(getInfo(b));
        float y = circulo_get_y(getInfo(b));
        while (elemento != NULL)
        {
            // movimento vertical
            if (xend == x)
            {
                // caso o circulo vá para cima
                if (yend < y)
                {
                    if (yend - raio <= ymina && ymina <= y + raio && x - raio <= xmina && xmina <= x + raio)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                // caso o círculo vá para baixo
                else
                {
                    if (y - raio <= ymina && ymina <= yend + raio && x - raio <= xmina && xmina <= x + raio)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
            else
            { // caso o círculo vá para a esquerda
                if (xend < x)
                {
                    if (xend - raio <= xmina && xmina <= x + raio && y - raio <= ymina && ymina <= y + raio)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                else
                { // caso o círculo vá para a direita
                    if (x - raio <= xmina && xmina <= xend + raio && y - raio <= ymina && ymina <= y + raio)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
        }
        break;

    case 'r':
        float xmina = mina_get_x(getInfo(elemento));
        float ymina = mina_get_y(getInfo(elemento));
        float w = retangulo_get_w(getInfo(b));
        float h = retangulo_get_h(getInfo(b));
        float x = retangulo_get_x(getInfo(b));
        float y = retangulo_get_y(getInfo(b));
        while (elemento != NULL)
        {
            // movimento vertical
            if (xend == x)
            {
                // caso o retângulo vá para cima
                if (yend < y)
                {
                    if (yend - h <= ymina && ymina <= y + h && x - w <= xmina && xmina <= x + w)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                // caso o retângulo vá para baixo
                else
                {
                    if (y - h <= ymina && ymina <= yend + h && x - w <= xmina && xmina <= x + w)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
            else
            { // caso o retângulo vá para a esquerda
                if (xend < x)
                {
                    if (xend - w <= xmina && xmina <= x + w && y - h <= ymina && ymina <= y + h)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                else
                { // caso o retângulo vá para a direita
                    if (x - w <= xmina && xmina <= xend + w && y - h <= ymina && ymina <= y + h)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
        }
        break;

    case 't':
        float xmina = mina_get_x(getInfo(elemento));
        float ymina = mina_get_y(getInfo(elemento));
        float x = texto_get_x(getInfo(b));
        float y = texto_get_y(getInfo(b));
        while (elemento != NULL)
        {
            // movimento vertical
            if (xend == x)
            {
                // caso o texto vá para cima
                if (yend < y)
                {
                    if (yend <= ymina && ymina <= y && x <= xmina && xmina <= x)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                // caso o texto vá para baixo
                else
                {
                    if (y <= ymina && ymina <= yend && x <= xmina && xmina <= x)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
            else
            { // caso o texto vá para a esquerda
                if (xend < x)
                {
                    if (xend <= xmina && xmina <= x && y <= ymina && ymina <= y)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                else
                { // caso o texto vá para a direita
                    if (x <= xmina && xmina <= xend && y <= ymina && ymina <= y)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
        }
        break;

    case 'l':
        float xmina = mina_get_x(getInfo(elemento));
        float ymina = mina_get_y(getInfo(elemento));
        float w = fabs(linha_get_x1(getInfo(b)) - linha_get_x2(getInfo(b)));
        float h = fabs(linha_get_y1(getInfo(b)) - linha_get_y2(getInfo(b)));
        float x = barco_get_x(b);
        float y = barco_get_y(b);
        while (elemento != NULL)
        {
            // movimento vertical
            if (xend == x)
            {
                // caso a linha vá para cima
                if (yend < y)
                {
                    if (yend - h <= ymina && ymina <= y + h && x - w <= xmina && xmina <= x + w)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                // caso a linha vá para baixo
                else
                {
                    if (y - h <= ymina && ymina <= yend + h && x - w <= xmina && xmina <= x + w)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
            else
            { // caso a linha vá para a esquerda
                if (xend < x)
                {
                    if (xend - w <= xmina && xmina <= x + w && y - h <= ymina && ymina <= y + h)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                else
                { // caso a linha vá para a direita
                    if (x - w <= xmina && xmina <= xend + w && y - h <= ymina && ymina <= y + h)
                    {
                        remover(listaSelec, b);
                        stringSvg(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
        }
        break;

    default:
        break;
    }
    return false;
}


