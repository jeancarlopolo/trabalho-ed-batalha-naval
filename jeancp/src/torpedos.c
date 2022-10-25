#include "torpedos.h"

double torpedo(Lista lista, double x, double y, FILE *svg, FILE *textow)
{
    int i = 0, hp;
    double x1, y1, x2, y2, raio, w, h, pontos = 0;
    Posic elemento = getFirst(lista);
    Posic aux = elemento;
    Barco *barco = get(lista, elemento);
    bool destruido = false;
    char asterisco[10];
    while (elemento != NULL)
    {
        destruido = false;
        barco = get(lista, elemento);
        switch (barco_get_tipo(barco))
        {
        case 'c':
            raio = circulo_get_r(barco_get_info(barco));
            x1 = circulo_get_x(barco_get_info(barco));
            y1 = circulo_get_y(barco_get_info(barco));
            if (sqrt(pow(x - x1, 2) + pow(y - y1, 2)) < raio)
            {
                i++;
                hp = barco_get_hp(barco);
                barco_set_hp(barco, hp - 1);
                if (hp - 1 == 0)
                {
                    destruido = true;
                    fprintf(textow, "\nTorpedo destruiu: círculo \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \nraio: %lf \nárea: %lf \nX: %lf \nY: %lf \n", circulo_get_i(barco_get_info(barco)), circulo_get_corb(barco_get_info(barco)), circulo_get_corp(barco_get_info(barco)), circulo_get_r(barco_get_info(barco)), circulo_get_area(barco_get_info(barco)), circulo_get_x(barco_get_info(barco)), circulo_get_y(barco_get_info(barco)));
                }
                else
                {
                    fprintf(textow, "\nTorpedo atingiu: círculo \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \nraio: %lf \nárea: %lf \nX: %lf \nY: %lf \nHP: %d\n", circulo_get_i(barco_get_info(barco)), circulo_get_corb(barco_get_info(barco)), circulo_get_corp(barco_get_info(barco)), circulo_get_r(barco_get_info(barco)), circulo_get_area(barco_get_info(barco)), circulo_get_x(barco_get_info(barco)), circulo_get_y(barco_get_info(barco)), hp);
                }
            }
            break;
        case 'r':
            x1 = retangulo_get_x(barco_get_info(barco));
            y1 = retangulo_get_y(barco_get_info(barco));
            w = retangulo_get_w(barco_get_info(barco));
            h = retangulo_get_h(barco_get_info(barco));
            if (x >= x1 && x <= x1 + w && y >= y1 && y <= y1 + h)
            {
                i++;
                hp = barco_get_hp(barco);
                barco_set_hp(barco, hp - 1);
                if (hp - 1 == 0)
                {
                    destruido = true;
                    fprintf(textow, "\nTorpedo destruiu: retângulo \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \naltura: %lf \nlargura: %lf \nárea: %lf \nX: %lf \nY: %lf \n", retangulo_get_i(barco_get_info(barco)), retangulo_get_corb(barco_get_info(barco)), retangulo_get_corp(barco_get_info(barco)), retangulo_get_h(barco_get_info(barco)), retangulo_get_w(barco_get_info(barco)), retangulo_get_area(barco_get_info(barco)), retangulo_get_x(barco_get_info(barco)), retangulo_get_y(barco_get_info(barco)));
                }
                else
                {
                    fprintf(textow, "\nTorpedo atingiu: retângulo \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \naltura: %lf \nlargura: %lf \nárea: %lf \nX: %lf \nY: %lf \nHP: %d\n", retangulo_get_i(barco_get_info(barco)), retangulo_get_corb(barco_get_info(barco)), retangulo_get_corp(barco_get_info(barco)), retangulo_get_h(barco_get_info(barco)), retangulo_get_w(barco_get_info(barco)), retangulo_get_area(barco_get_info(barco)), retangulo_get_x(barco_get_info(barco)), retangulo_get_y(barco_get_info(barco)), hp);
                }
            }
            break;
        case 't':
            x1 = texto_get_x(barco_get_info(barco));
            y1 = texto_get_y(barco_get_info(barco));
            if (x == x1 && y == y1)
            {
                i++;
                hp = barco_get_hp(barco);
                barco_set_hp(barco, hp - 1);
                if (hp - 1 == 0)
                {
                    destruido = true;
                    fprintf(textow, "\nTorpedo destruiu: texto \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \nX: %lf \nY: %lf \n", texto_get_i(barco_get_info(barco)), texto_get_corb(barco_get_info(barco)), texto_get_corp(barco_get_info(barco)), texto_get_x(barco_get_info(barco)), texto_get_y(barco_get_info(barco)));
                }
                else
                {
                    fprintf(textow, "\nTorpedo atingiu: texto \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \nX: %lf \nY: %lf \nHP: %d\n", texto_get_i(barco_get_info(barco)), texto_get_corb(barco_get_info(barco)), texto_get_corp(barco_get_info(barco)), texto_get_x(barco_get_info(barco)), texto_get_y(barco_get_info(barco)), hp);
                }
            }
            break;
        case 'l':
            x1 = linha_get_x1(barco_get_info(barco));
            y1 = linha_get_y1(barco_get_info(barco));
            x2 = linha_get_x2(barco_get_info(barco));
            y2 = linha_get_y2(barco_get_info(barco));
            if (((x <= x1 && x >= x2) || (x >= x1 && x <= x2)) && ((y >= y1 && y <= y2) || (y <= y1 && y >= y2)))
            {
                i++;
                hp = barco_get_hp(barco);
                barco_set_hp(barco, hp - 1);
                if (hp - 1 == 0)
                {
                    destruido = true;
                    fprintf(textow, "\nTorpedo destruiu: linha \nid: %d \ncor: %s \nX1: %lf \nY1: %lf \nX2: %lf \nY2: %lf \n", linha_get_i(barco_get_info(barco)), linha_get_cor(barco_get_info(barco)), linha_get_x1(barco_get_info(barco)), linha_get_y1(barco_get_info(barco)), linha_get_x2(barco_get_info(barco)), linha_get_y2(barco_get_info(barco)));
                }
                else
                {
                    fprintf(textow, "\nTorpedo atingiu: linha \nid: %d \ncor: %s \nX1: %lf \nY1: %lf \nX2: %lf \nY2: %lf \nHP: %d\n", linha_get_i(barco_get_info(barco)), linha_get_cor(barco_get_info(barco)), linha_get_x1(barco_get_info(barco)), linha_get_y1(barco_get_info(barco)), linha_get_x2(barco_get_info(barco)), linha_get_y2(barco_get_info(barco)), hp);
                }
            }
            break;
        default:
            break;
        }
        if (destruido)
        {
            pontos += barco_get_point_destr(barco);
            fprintf(textow, "Pontos recebidos: %lf \nPontos totais: %lf\n\n", barco_get_point_destr(barco), pontos);
            aux = elemento;
            elemento = getNext(lista, elemento);
            remover(lista, aux);
        }
        else
        {
            elemento = getNext(lista, elemento);
        }
    }
    if (i > 0)
    {
        sprintf(asterisco, "*%d", i);
        svg_string(svg, asterisco, x, y, "red", "red", "middle");
    }
    else
    {
        svg_string(svg, "*", x, y, "gray", "gray", "middle");
        fprintf(textow, "\nÁGUA!\n");
    }
    return pontos;
}

void torpedo_replicante(Lista lista, double x, double y, double x1, double y1, int id, FILE *svg, FILE *textow)
{
    int contador = 0;
    double x2, y2, x3, y3, raio, w, h;
    Posic elemento = getFirst(lista);
    Barco *barco;
    char *corb, *corp, *texto, *ancora;
    while (elemento != NULL)
    {
        barco = get(lista, elemento);
        switch (barco_get_tipo(barco))
        {
        case 'c':
            raio = circulo_get_r(barco_get_info(barco));
            x2 = circulo_get_x(barco_get_info(barco));
            y2 = circulo_get_y(barco_get_info(barco));
            if (sqrt(pow(x - x2, 2) + pow(y - y2, 2)) < raio)
            {
                contador++;
                corb = circulo_get_corb(barco_get_info(barco));
                corp = circulo_get_corp(barco_get_info(barco));
                Barco *circle = create_barco('c', create_circulo(id + contador, x2 + x1, y2 + y1, raio, corp, corb));
                insert(lista, circle);
                fprintf(textow, "\nTorpedo replicante: círculo \nid: %d \nraio: %lf \ncor da borda: %s \ncor de preenchimento: %s \nX: %lf \nY: %lf \n", circulo_get_i(barco_get_info(barco)), circulo_get_r(barco_get_info(barco)), circulo_get_corb(barco_get_info(barco)), circulo_get_corp(barco_get_info(barco)), circulo_get_x(barco_get_info(barco)), circulo_get_y(barco_get_info(barco)));
                fprintf(textow, "\nCópia: círculo \nid: %d \nraio: %lf \ncor da borda: %s \ncor de preenchimento: %s \nX: %lf \nY: %lf \n", circulo_get_i(barco_get_info(circle)), circulo_get_r(barco_get_info(circle)), circulo_get_corb(barco_get_info(circle)), circulo_get_corp(barco_get_info(circle)), circulo_get_x(barco_get_info(circle)), circulo_get_y(barco_get_info(circle)));
            }
            break;
        case 'r':
            x2 = retangulo_get_x(barco_get_info(barco));
            y2 = retangulo_get_y(barco_get_info(barco));
            w = retangulo_get_w(barco_get_info(barco));
            h = retangulo_get_h(barco_get_info(barco));
            if (x >= x2 && x <= x2 + w && y >= y2 && y <= y2 + h)
            {
                contador++;
                corb = retangulo_get_corb(barco_get_info(barco));
                corp = retangulo_get_corp(barco_get_info(barco));
                Barco *rectangle = create_barco('r', create_retangulo(id + contador, x2 + x1, y2 + y1, w, h, corp, corb));
                insert(lista, rectangle);
                fprintf(textow, "\nTorpedo replicante: retângulo \nid: %d \naltura: %lf \nlargura: %lf \ncor da borda: %s \ncor de preenchimento: %s \nX: %lf \nY: %lf \n", retangulo_get_i(barco_get_info(barco)), retangulo_get_h(barco_get_info(barco)), retangulo_get_w(barco_get_info(barco)), retangulo_get_corb(barco_get_info(barco)), retangulo_get_corp(barco_get_info(barco)), retangulo_get_x(barco_get_info(barco)), retangulo_get_y(barco_get_info(barco)));
                fprintf(textow, "\nCópia: retangulo \nid: %d \naltura: %lf \nlargura: %lf \ncor da borda: %s \ncor de preenchimento: %s \nX: %lf \nY: %lf \n", retangulo_get_i(barco_get_info(rectangle)), retangulo_get_h(barco_get_info(rectangle)), retangulo_get_w(barco_get_info(rectangle)), retangulo_get_corb(barco_get_info(rectangle)), retangulo_get_corp(barco_get_info(rectangle)), retangulo_get_x(barco_get_info(rectangle)), retangulo_get_y(barco_get_info(rectangle)));
            }
            break;
        case 't':
            x2 = texto_get_x(barco_get_info(barco));
            y2 = texto_get_y(barco_get_info(barco));
            if (x == x2 && y == y2)
            {
                contador++;
                corb = texto_get_corb(barco_get_info(barco));
                corp = texto_get_corp(barco_get_info(barco));
                texto = texto_get_conteudo(barco_get_info(barco));
                ancora = texto_get_ancora(barco_get_info(barco));
                Barco *text = create_barco('t', create_texto(id + contador, x2 + x1, y2 + y1, corp, corb, texto, ancora));
                insert(lista, text);
                fprintf(textow, "\nTorpedo replicante: texto \nid: %d \nconteúdo: %scor da borda: %s \ncor de preenchimento: %s \nX: %lf \nY: %lf \n", texto_get_i(barco_get_info(barco)), texto_get_conteudo(barco_get_info(barco)), texto_get_corb(barco_get_info(barco)), texto_get_corp(barco_get_info(barco)), texto_get_x(barco_get_info(barco)), texto_get_y(barco_get_info(barco)));
                fprintf(textow, "\nCópia: texto \nid: %d \nconteúdo: %scor da borda: %s \ncor de preenchimento: %s \nX: %lf \nY: %lf \n", texto_get_i(barco_get_info(text)), texto_get_conteudo(barco_get_info(text)), texto_get_corb(barco_get_info(text)), texto_get_corp(barco_get_info(text)), texto_get_x(barco_get_info(text)), texto_get_y(barco_get_info(text)));
            }
            break;
        case 'l':
            x2 = linha_get_x1(barco_get_info(barco));
            y2 = linha_get_y1(barco_get_info(barco));
            x3 = linha_get_x2(barco_get_info(barco));
            y3 = linha_get_y2(barco_get_info(barco));
            if (((x <= x2 && x >= x3) || (x >= x2 && x <= x3)) && ((y >= y2 && y <= y3) || (y <= y2 && y >= y3)))
            {
                contador++;
                corb = linha_get_cor(barco_get_info(barco));
                Barco *line = create_barco('l', create_linha(id + contador, x2 + x1, y2 + y1, x3 + x1, y3 + y1, corb));
                insert(lista, line);
                fprintf(textow, "\nTorpedo replicante: linha \nid: %d \ncor: %s \nX1: %lf \nY1: %lf \nX2: %lf \nY2: %lf \n", linha_get_i(barco_get_info(barco)), linha_get_cor(barco_get_info(barco)), linha_get_x1(barco_get_info(barco)), linha_get_y1(barco_get_info(barco)), linha_get_x2(barco_get_info(barco)), linha_get_y2(barco_get_info(barco)));
                fprintf(textow, "\nCópia: linha \nid: %d \ncor: %s \nX1: %lf \nY1: %lf \nX2: %lf \nY2: %lf \n", linha_get_i(barco_get_info(line)), linha_get_cor(barco_get_info(line)), linha_get_x1(barco_get_info(line)), linha_get_y1(barco_get_info(line)), linha_get_x2(barco_get_info(line)), linha_get_y2(barco_get_info(line)));
            }
            break;
        default:
            break;
        }
        elemento = getNext(lista, elemento);
    }
    svg_string(svg, "@", x, y, "red", "red", "middle");
}