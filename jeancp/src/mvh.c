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

void move_barco(Lista barcosSelec, float x, float y, Lista *listaminas, Lista *lista, FILE *svg, int j, int k, FILE *textow)
{
    Barco *b = escolher_barco(barcosSelec, j, k);
    float xfinal, yfinal, pontos = 0;
    xfinal = x + getBarcoX(b);
    yfinal = y + getBarcoX(b);
    if (!passou_mina(barcosSelec, x, y, listaminas, lista, svg, barcosSelec, textow))
    {
        switch (getTipo(barcosSelec))
        {
        case 'r':
            move_retangulo(getInfo(barcosSelec), xfinal, yfinal);
            fprintf(textow, "Barco %d movido para (%f, %f)", retangulo_get_i(getInfo(barcosSelec)), xfinal, yfinal);
            break;
        case 'c':
            move_circulo(getInfo(barcosSelec), xfinal, yfinal);
            fprintf(textow, "Barco %d movido para (%f, %f)", circulo_get_i(getInfo(barcosSelec)), xfinal, yfinal);
            break;
        case 't':
            move_texto(getInfo(barcosSelec), xfinal, yfinal);
            fprintf(textow, "Barco %d movido para (%f, %f)", texto_get_i(getInfo(barcosSelec)), xfinal, yfinal);
            break;
        case 'l':
            move_linha(getInfo(barcosSelec), xfinal, yfinal);
            fprintf(textow, "Barco %d movido para (%f, %f)", linha_get_i(getInfo(barcosSelec)), xfinal, yfinal);
            break;
        }
    }
    else
    {
        pontos += getPontuacaoDestruicao(b);
    }
}

bool passou_mina(Barco b, float xend, float yend, Lista *listaminas, Lista *lista, FILE *svg, Lista *listaSelec, FILE *textow)
{

    Posic elemento = getFirst(listaminas);
    float xmina, ymina, raio, x, y, w, h;
    switch (getTipo(b))
    {
    case 'c':
        xmina = getMinaX(getInfo(elemento));
        ymina = getMinaY(getInfo(elemento));
        raio = circulo_get_r(getInfo(b));
        x = circulo_get_x(getInfo(b));
        y = circulo_get_y(getInfo(b));
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
                        fprintf(textow, "circulo(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", circulo_get_i(getInfo(b)), xmina, ymina);
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
                        fprintf(textow, "circulo(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", circulo_get_i(getInfo(b)), xmina, ymina);
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
                        fprintf(textow, "circulo(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", circulo_get_i(getInfo(b)), xmina, ymina);
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
                        fprintf(textow, "circulo(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", circulo_get_i(getInfo(b)), xmina, ymina);
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
        xmina = getMinaX(getInfo(elemento));
        ymina = getMinaY(getInfo(elemento));
        w = retangulo_get_w(getInfo(b));
        h = retangulo_get_h(getInfo(b));
        x = retangulo_get_x(getInfo(b));
        y = retangulo_get_y(getInfo(b));
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
                        fprintf(textow, "retangulo(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", retangulo_get_i(getInfo(b)), xmina, ymina);
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
                        fprintf(textow, "retangulo(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", retangulo_get_i(getInfo(b)), xmina, ymina);
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
                        fprintf(textow, "retangulo(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", retangulo_get_i(getInfo(b)), xmina, ymina);
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
                        fprintf(textow, "retangulo(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", retangulo_get_i(getInfo(b)), xmina, ymina);
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
        xmina = getMinaX(getInfo(elemento));
        ymina = getMinaY(getInfo(elemento));
        x = texto_get_x(getInfo(b));
        y = texto_get_y(getInfo(b));
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
                        fprintf(textow, "texto(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", texto_get_i(getInfo(b)), xmina, ymina);
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
                        fprintf(textow, "texto(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", texto_get_i(getInfo(b)), xmina, ymina);
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
                        fprintf(textow, "texto(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", texto_get_i(getInfo(b)), xmina, ymina);
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
                        fprintf(textow, "texto(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", texto_get_i(getInfo(b)), xmina, ymina);
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
        xmina = getMinaX(getInfo(elemento));
        ymina = getMinaY(getInfo(elemento));
        w = fabs(linha_get_x1(getInfo(b)) - linha_get_x2(getInfo(b)));
        h = fabs(linha_get_y1(getInfo(b)) - linha_get_y2(getInfo(b)));
        x = getBarcoX(b);
        y = getBarcoY(b);
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
                        fprintf(textow, "linha(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", linha_get_i(getInfo(b)), xmina, ymina);
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
                        fprintf(textow, "linha(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", linha_get_i(getInfo(b)), xmina, ymina);
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
                        fprintf(textow, "linha(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", linha_get_i(getInfo(b)), xmina, ymina);
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
                        fprintf(textow, "linha(id: %d) passou por uma mina em: \nX: %f \nY: %f\n", linha_get_i(getInfo(b)), xmina, ymina);
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

Barco escolher_barco(Lista barcosSelec, int j, int k)
{
    Posic p = getFirst(barcosSelec);
    Posic barcoSelecionado;
    Barco *b;
    while (p != NULL)
    {
        b = get(barcosSelec, p);
        if (isCapitao(b) == j)
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