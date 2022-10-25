#include "bomba.h"

double calcular_reducao(double area, double r, double na)
{
    double reducao = 0;
    double pi = 3.14159265358979323846;
    r = r * r * pi;
    reducao = (area * na) / r;
    return reducao;
}

double bomba_rad(Lista *l, double x, double y, double r, double na, FILE *svg, FILE *textow)
{
    double np;
    double x1, y1, x2, y2, raio, w, h, pontos = 0, area, comprimento;
    Posic elemento = getFirst(l);
    Posic aux = elemento;
    Barco *barco = get(l, elemento);
    bool desativado = false;
    while (elemento != NULL)
    {
        desativado = false;
        barco = get(l, elemento);
        switch (barco_get_tipo(barco))
        {
        case 'c':
            raio = circulo_get_r(barco_get_info(barco));
            x1 = circulo_get_x(barco_get_info(barco));
            y1 = circulo_get_y(barco_get_info(barco));
            if (sqrt(((x - x1) * (x - x1)) + ((y - y1) * (y - y1))) + raio <= r)
            {
                np = barco_get_protecao(barco);
                area = circulo_get_area(barco_get_info(barco));
                barco_set_protecao(barco, np - calcular_reducao(area, r, na));
                if (barco_get_protecao(barco) <= 0)
                {
                    desativado = true;
                    fprintf(textow, "\nBomba desativou: círculo \nid: %d \ncor da borda: %s \ncor de preenchimento: %s \nraio: %lf \nárea: %lf \nX: %lf \nY: %lf \nHP: %d \nProteção: %lf\n", circulo_get_i(barco_get_info(barco)), circulo_get_corb(barco_get_info(barco)), circulo_get_corp(barco_get_info(barco)), circulo_get_r(barco_get_info(barco)), circulo_get_area(barco_get_info(barco)), circulo_get_x(barco_get_info(barco)), circulo_get_y(barco_get_info(barco)), barco_get_hp(barco), barco_get_protecao(barco));
                }
                else
                {
                    fprintf(textow, "\nBomba atingiu: círculo \nid: %d \ncor da borda: %s \ncor de preenchimento: %s \nraio: %lf \nárea: %lf \nX: %lf \nY: %lf \nHP: %d \nProteção: %lf\n", circulo_get_i(barco_get_info(barco)), circulo_get_corb(barco_get_info(barco)), circulo_get_corp(barco_get_info(barco)), circulo_get_r(barco_get_info(barco)), circulo_get_area(barco_get_info(barco)), circulo_get_x(barco_get_info(barco)), circulo_get_y(barco_get_info(barco)), barco_get_hp(barco), barco_get_protecao(barco));
                }
                fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" fill=\"red\" stroke=\"red\" stroke-width=\"1\"/>\n", x1, y1);
            }
            break;
        case 'r':
            x1 = retangulo_get_x(barco_get_info(barco));
            y1 = retangulo_get_y(barco_get_info(barco));
            w = retangulo_get_w(barco_get_info(barco));
            h = retangulo_get_h(barco_get_info(barco));
            if (x + r >= x1 && x - r <= x1 + w && y + r >= y1 && y - r <= y1 + h)
            {
                if (sqrt(pow(x - x1, 2) + pow(y - y1, 2)) < r && sqrt(pow(x - x1 - w, 2) + pow(y - y1, 2)) < r && sqrt(pow(x - x1, 2) + pow(y - y1 - h, 2)) < r && sqrt(pow(x - x1 - w, 2) + pow(y - y1 - h, 2)) < r)
                {
                    np = barco_get_protecao(barco);
                    area = retangulo_get_area(barco_get_info(barco));
                    barco_set_protecao(barco, np - calcular_reducao(area, r, na));
                    if (barco_get_protecao(barco) <= 0)
                    {
                        desativado = true;
                        fprintf(textow, "\nBomba desativou: retângulo \nid: %d \ncor da borda: %s \ncor de preenchimento: %s \naltura: %lf \nlargura: %lf \nárea: %lf \nX: %lf \nY: %lf \nHP: %d \nProteção: %lf\n", retangulo_get_i(barco_get_info(barco)), retangulo_get_corb(barco_get_info(barco)), retangulo_get_corp(barco_get_info(barco)), retangulo_get_h(barco_get_info(barco)), retangulo_get_w(barco_get_info(barco)), retangulo_get_area(barco_get_info(barco)), retangulo_get_x(barco_get_info(barco)), retangulo_get_y(barco_get_info(barco)), barco_get_hp(barco), barco_get_protecao(barco));
                    }
                    else
                    {
                        fprintf(textow, "\nBomba atingiu: retângulo \nid: %d \ncor da borda: %s \ncor de preenchimento: %s \naltura: %lf \nlargura: %lf \nárea: %lf \nX: %lf \nY: %lf \nHP: %d \nProteção: %lf\n", retangulo_get_i(barco_get_info(barco)), retangulo_get_corb(barco_get_info(barco)), retangulo_get_corp(barco_get_info(barco)), retangulo_get_h(barco_get_info(barco)), retangulo_get_w(barco_get_info(barco)), retangulo_get_area(barco_get_info(barco)), retangulo_get_x(barco_get_info(barco)), retangulo_get_y(barco_get_info(barco)), barco_get_hp(barco), barco_get_protecao(barco));
                    }
                    fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" fill=\"red\" stroke=\"red\" stroke-width=\"1\"/>\n", x1, y1);
                }
            }
            break;
        case 't':
            x1 = texto_get_x(barco_get_info(barco));
            y1 = texto_get_y(barco_get_info(barco));
            if (sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)) < r)
            {
                np = barco_get_protecao(barco);
                barco_set_protecao(barco, np - calcular_reducao(0.1, r, na));
                if (barco_get_protecao(barco) <= 0)
                {
                    desativado = true;
                    fprintf(textow, "\nBomba desativou: texto \nid: %d \ncor de borda: %s \ncor de preenchimento: %s \nX: %lf \nY: %lf \nHP: %d \nProteção: %lf\n", texto_get_i(barco_get_info(barco)), texto_get_corb(barco_get_info(barco)), texto_get_corp(barco_get_info(barco)), texto_get_x(barco_get_info(barco)), texto_get_y(barco_get_info(barco)), barco_get_hp(barco), barco_get_protecao(barco));
                }
                else
                {
                    fprintf(textow, "\nBomba atingiu: texto \nid: %d \ncor de borda: %s \ncor de preenchimento: %s \nX: %lf \nY: %lf \nHP: %d \nProteção: %lf\n", texto_get_i(barco_get_info(barco)), texto_get_corb(barco_get_info(barco)), texto_get_corp(barco_get_info(barco)), texto_get_x(barco_get_info(barco)), texto_get_y(barco_get_info(barco)), barco_get_hp(barco), barco_get_protecao(barco));
                }
                fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" fill=\"red\" stroke=\"red\" stroke-width=\"1\"/>\n", x1, y1);
            }
            break;
        case 'l':
            x1 = linha_get_x1(barco_get_info(barco));
            y1 = linha_get_y1(barco_get_info(barco));
            x2 = linha_get_x2(barco_get_info(barco));
            y2 = linha_get_y2(barco_get_info(barco));
            if (sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)) < r && sqrt(pow(x2 - x, 2) + pow(y2 - y, 2)) < r)
            {
                np = barco_get_protecao(barco);
                comprimento = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                barco_set_protecao(barco, np - calcular_reducao(comprimento, r, na));
                if (barco_get_protecao(barco) <= 0)
                {
                    desativado = true;
                    fprintf(textow, "\nBomba desativou: linha \nid: %d \ncor: %s \nX1: %lf \nY1: %lf \nX2: %lf \nY2: %lf \nHP: %d \nProteção: %lf\n", linha_get_i(barco_get_info(barco)), linha_get_cor(barco_get_info(barco)), linha_get_x1(barco_get_info(barco)), linha_get_y1(barco_get_info(barco)), linha_get_x2(barco_get_info(barco)), linha_get_y2(barco_get_info(barco)), barco_get_hp(barco), barco_get_protecao(barco));
                }
                else
                {
                    fprintf(textow, "\nBomba atingiu: linha \nid: %d \ncor: %s\nX1: %lf \nY1: %lf \nX2: %lf \nY2: %lf \nHP: %d \nProteção: %lf\n", linha_get_i(barco_get_info(barco)), linha_get_cor(barco_get_info(barco)), linha_get_x1(barco_get_info(barco)), linha_get_y1(barco_get_info(barco)), linha_get_x2(barco_get_info(barco)), linha_get_y2(barco_get_info(barco)), barco_get_hp(barco), barco_get_protecao(barco));
                }
                fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"2\" fill=\"red\" stroke=\"red\" stroke-width=\"1\"/>\n", x1, y1);
            }
            break;
        default:
            break;
        }
        if (desativado)
        {
            pontos += barco_get_point_desat(barco);
            fprintf(textow, "Pontos recebidos: %lf \nPontos totais: %lf\n\n", barco_get_point_desat(barco), pontos);
            aux = elemento;
            elemento = getNext(l, elemento);
            remover(l, aux);
        }
        else
        {
            elemento = getNext(l, elemento);
        }
    }
    fprintf(svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"none\" stroke=\"red\" stroke-dasharray=\"5,5\" stroke-width=\"1\"/>\n", x, y, r);
    return pontos;
}
