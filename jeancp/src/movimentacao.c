#include "movimentacao.h"

void move_retangulo(Barco b, double x, double y)
{
    retangulo r = barco_get_info(b);
    retangulo_set_x(r, x);
    retangulo_set_y(r, y);
}

void move_circulo(Barco b, double x, double y)
{
    circulo c = barco_get_info(b);
    circulo_set_x(c, x);
    circulo_set_y(c, y);
}

void move_texto(Barco b, double x, double y)
{
    texto t = barco_get_info(b);
    texto_set_x(t, x);
    texto_set_y(t, y);
}

void move_linha(Barco b, double x, double y)
{
    linha l = barco_get_info(b);
    linha_set_x1(l, x);
    linha_set_y1(l, y);
    linha_set_x2(l, x);
    linha_set_y2(l, y);
}

double move_barco(Lista barcosSelec, double x, double y, Lista *listaminas, Lista *lista, FILE *svg, int j, int k, FILE *textow)
{
    Barco *b = escolher_barco(barcosSelec, j, k);
    double xfinal, yfinal, pontos = 0;
    xfinal = x + barco_get_x(b);
    yfinal = y + barco_get_x(b);
    if (!passou_mina(barcosSelec, x, y, listaminas, lista, svg, barcosSelec, textow))
    {
        switch (barco_get_tipo(barcosSelec))
        {
        case 'r':
            move_retangulo(barco_get_info(barcosSelec), xfinal, yfinal);
            fprintf(textow, "Barco %d movido para (%lf, %lf)", retangulo_get_i(barco_get_info(barcosSelec)), xfinal, yfinal);
            break;
        case 'c':
            move_circulo(barco_get_info(barcosSelec), xfinal, yfinal);
            fprintf(textow, "Barco %d movido para (%lf, %lf)", circulo_get_i(barco_get_info(barcosSelec)), xfinal, yfinal);
            break;
        case 't':
            move_texto(barco_get_info(barcosSelec), xfinal, yfinal);
            fprintf(textow, "Barco %d movido para (%lf, %lf)", texto_get_i(barco_get_info(barcosSelec)), xfinal, yfinal);
            break;
        case 'l':
            move_linha(barco_get_info(barcosSelec), xfinal, yfinal);
            fprintf(textow, "Barco %d movido para (%lf, %lf)", linha_get_i(barco_get_info(barcosSelec)), xfinal, yfinal);
            break;
        }
    }
    else
    {
        pontos = barco_get_point_destr(b);
    }
    return pontos;
}

bool passou_mina(Barco b, double xend, double yend, Lista *listaminas, Lista *lista, FILE *svg, Lista *listaSelec, FILE *textow)
{

    Posic elemento = getFirst(listaminas);
    double xmina, ymina, raio, x, y, w, h;
    switch (barco_get_tipo(b))
    {
    case 'c':
        xmina = getMinaX(barco_get_info(elemento));
        ymina = getMinaY(barco_get_info(elemento));
        raio = circulo_get_r(barco_get_info(b));
        x = circulo_get_x(barco_get_info(b));
        y = circulo_get_y(barco_get_info(b));
        while (elemento != NULL)
        {
            if (xend == x)
            {
                if (yend < y)
                {
                    if (yend - raio <= ymina && ymina <= y + raio && x - raio <= xmina && xmina <= x + raio)
                    {
                        fprintf(textow, "circulo(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", circulo_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                else
                {
                    if (y - raio <= ymina && ymina <= yend + raio && x - raio <= xmina && xmina <= x + raio)
                    {
                        fprintf(textow, "circulo(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", circulo_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
            else
            {
                if (xend < x)
                {
                    if (xend - raio <= xmina && xmina <= x + raio && y - raio <= ymina && ymina <= y + raio)
                    {
                        fprintf(textow, "circulo(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", circulo_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                else
                {
                    if (x - raio <= xmina && xmina <= xend + raio && y - raio <= ymina && ymina <= y + raio)
                    {
                        fprintf(textow, "circulo(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", circulo_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
        }
        break;

    case 'r':
        xmina = getMinaX(barco_get_info(elemento));
        ymina = getMinaY(barco_get_info(elemento));
        w = retangulo_get_w(barco_get_info(b));
        h = retangulo_get_h(barco_get_info(b));
        x = retangulo_get_x(barco_get_info(b));
        y = retangulo_get_y(barco_get_info(b));
        while (elemento != NULL)
        {
            if (xend == x)
            {
                if (yend < y)
                {
                    if (yend - h <= ymina && ymina <= y + h && x - w <= xmina && xmina <= x + w)
                    {
                        fprintf(textow, "retangulo(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", retangulo_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                else
                {
                    if (y - h <= ymina && ymina <= yend + h && x - w <= xmina && xmina <= x + w)
                    {
                        fprintf(textow, "retangulo(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", retangulo_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
            else
            {
                if (xend < x)
                {
                    if (xend - w <= xmina && xmina <= x + w && y - h <= ymina && ymina <= y + h)
                    {
                        fprintf(textow, "retangulo(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", retangulo_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                else
                {
                    if (x - w <= xmina && xmina <= xend + w && y - h <= ymina && ymina <= y + h)
                    {
                        fprintf(textow, "retangulo(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", retangulo_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
        }
        break;

    case 't':
        xmina = getMinaX(barco_get_info(elemento));
        ymina = getMinaY(barco_get_info(elemento));
        x = texto_get_x(barco_get_info(b));
        y = texto_get_y(barco_get_info(b));
        while (elemento != NULL)
        {
            if (xend == x)
            {
                if (yend < y)
                {
                    if (yend <= ymina && ymina <= y && x <= xmina && xmina <= x)
                    {
                        fprintf(textow, "texto(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", texto_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                else
                {
                    if (y <= ymina && ymina <= yend && x <= xmina && xmina <= x)
                    {
                        fprintf(textow, "texto(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", texto_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
            else
            {
                if (xend < x)
                {
                    if (xend <= xmina && xmina <= x && y <= ymina && ymina <= y)
                    {
                        fprintf(textow, "texto(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", texto_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                else
                {
                    if (x <= xmina && xmina <= xend && y <= ymina && ymina <= y)
                    {
                        fprintf(textow, "texto(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", texto_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
        }
        break;

    case 'l':
        xmina = getMinaX(barco_get_info(elemento));
        ymina = getMinaY(barco_get_info(elemento));
        w = fabs(linha_get_x1(barco_get_info(b)) - linha_get_x2(barco_get_info(b)));
        h = fabs(linha_get_y1(barco_get_info(b)) - linha_get_y2(barco_get_info(b)));
        x = barco_get_x(b);
        y = barco_get_y(b);
        while (elemento != NULL)
        {
            if (xend == x)
            {
                if (yend < y)
                {
                    if (yend - h <= ymina && ymina <= y + h && x - w <= xmina && xmina <= x + w)
                    {
                        fprintf(textow, "linha(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", linha_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                else
                {
                    if (y - h <= ymina && ymina <= yend + h && x - w <= xmina && xmina <= x + w)
                    {
                        fprintf(textow, "linha(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", linha_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
            }
            else
            {
                if (xend < x)
                {
                    if (xend - w <= xmina && xmina <= x + w && y - h <= ymina && ymina <= y + h)
                    {
                        fprintf(textow, "linha(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", linha_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
                        killMina(elemento);
                        remover(lista, b);
                        return true;
                    }
                }
                else
                {
                    if (x - w <= xmina && xmina <= xend + w && y - h <= ymina && ymina <= y + h)
                    {
                        fprintf(textow, "linha(id: %d) passou por uma mina em: \nX: %lf \nY: %lf\n", linha_get_i(barco_get_info(b)), xmina, ymina);
                        remover(listaSelec, b);
                        svg_string(svg, "&", xmina, ymina, "red", "red", "middle");
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

Barco escolher_barco(Lista barcosSelec, int j, int k)
{
    Posic p = getFirst(barcosSelec);
    Posic barcoSelecionado;
    Barco *b;
    while (p != NULL)
    {
        b = get(barcosSelec, p);
        if (barco_get_capitaoid(b) == j)
        {
            break;
        }
        p = getNext(barcosSelec, p);
    }
    if (p == NULL)
    {
        return NULL;
    }
    if (k > 0)
    {
        for (int i = 0; i < k; i++)
        {
            barcoSelecionado = getNext(barcosSelec, p);
            if (barcoSelecionado == NULL)
            {
                barcoSelecionado = getFirst(barcosSelec);
            }
        }
    }
    else
    {
        for (int i = 0; i > k; i--)
        {
            barcoSelecionado = getPrevious(barcosSelec, p);
            if (barcoSelecionado == NULL)
            {
                barcoSelecionado = getLast(barcosSelec);
            }
        }
    }
    return barcoSelecionado;
}