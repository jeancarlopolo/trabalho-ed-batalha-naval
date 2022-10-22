#include "torpedos.h"

void torpedo(Lista lista, float x, float y, FILE *svg, FILE *textow)
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
        barco = get(lista, elemento);
        switch (getTipo(barco))
        {
        case 'c':
            raio = circulo_get_r(getInfo(barco));
            x1 = circulo_get_x(getInfo(barco));
            y1 = circulo_get_y(getInfo(barco));
            if (sqrt(pow(x - x1, 2) + pow(y - y1, 2)) < raio)
            {
                i++;
                hp = getHP(barco);
                setHP(barco, hp - 1);
                if (hp - 1 == 0)
                {
                    destruido = true;
                fprintf(textow, "Torpedo destruiu: circulo \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \nraio: %f \narea: %f \nX: %f \nY: %f \n", circulo_get_id(getInfo(barco)), circulo_get_corborda(getInfo(barco)), circulo_get_corpreenchimento(getInfo(barco)), circulo_get_r(getInfo(barco)), circulo_get_area(getInfo(barco)), circulo_get_x(getInfo(barco)), circulo_get_y(getInfo(barco)));
                }else{
                    fprintf(textow, "Torpedo atingiu: circulo \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \nraio: %f \narea: %f \nX: %f \nY: %f \nHP: %d\n", circulo_get_id(getInfo(barco)), circulo_get_corborda(getInfo(barco)), circulo_get_corpreenchimento(getInfo(barco)), circulo_get_r(getInfo(barco)), circulo_get_area(getInfo(barco)), circulo_get_x(getInfo(barco)), circulo_get_y(getInfo(barco)), hp);
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
                hp = getHP(barco);
                setHP(barco, hp - 1);
                if (hp - 1 == 0)
                {
                    destruido = true;
                    fprintf(textow, "Torpedo destruiu: retangulo \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \naltura: %f \nlargura: %f \narea: %f \nX: %f \nY: %f \n", retangulo_get_id(getInfo(barco)), retangulo_get_corborda(getInfo(barco)), retangulo_get_corpreenchimento(getInfo(barco)), retangulo_get_h(getInfo(barco)), retangulo_get_w(getInfo(barco)), retangulo_get_area(getInfo(barco)), retangulo_get_x(getInfo(barco)), retangulo_get_y(getInfo(barco)));
                }else{
                    fprintf(textow, "Torpedo atingiu: retangulo \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \naltura: %f \nlargura: %f \narea: %f \nX: %f \nY: %f \nHP: %d\n", retangulo_get_id(getInfo(barco)), retangulo_get_corborda(getInfo(barco)), retangulo_get_corpreenchimento(getInfo(barco)), retangulo_get_h(getInfo(barco)), retangulo_get_w(getInfo(barco)), retangulo_get_area(getInfo(barco)), retangulo_get_x(getInfo(barco)), retangulo_get_y(getInfo(barco)), hp);
                }
            }
            break;
        case 't':
            x1 = texto_get_x(getInfo(barco));
            y1 = texto_get_y(getInfo(barco));
            if (x == x1 && y == y1)
            {
                i++;
                hp = getHP(barco);
                setHP(barco, hp - 1);
                if (hp - 1 == 0)
                {
                    destruido = true;
                    fprintf(textow, "Torpedo destruiu: texto \nid: %d \ntexto: %s \nX: %f \nY: %f \n", texto_get_id(getInfo(barco)), texto_get_texto(getInfo(barco)), texto_get_x(getInfo(barco)), texto_get_y(getInfo(barco)));
                }else{
                    fprintf(textow, "Torpedo atingiu: texto \nid: %d \ntexto: %s \nX: %f \nY: %f \nHP: %d\n", texto_get_id(getInfo(barco)), texto_get_texto(getInfo(barco)), texto_get_x(getInfo(barco)), texto_get_y(getInfo(barco)), hp);
                }
            }
            break;
        case 'l':
            x1 = linha_get_x1(getInfo(barco));
            y1 = linha_get_y1(getInfo(barco));
            x2 = linha_get_x2(getInfo(barco));
            y2 = linha_get_y2(getInfo(barco));
            if (((x <= x1 && x >= x2) || (x >= x1 && x <= x2)) && ((y >= y1 && y <= y2) || (y <= y1 && y >= y2)))
            {
                i++;
                hp = getHP(barco);
                setHP(barco, hp - 1);
                if (hp - 1 == 0)
                {
                    destruido = true;
                    fprintf(textow, "Torpedo destruiu: linha \nid: %d \ncor da borda: %s \nX1: %f \nY1: %f \nX2: %f \nY2: %f \n", linha_get_id(getInfo(barco)), linha_get_corborda(getInfo(barco)), linha_get_x1(getInfo(barco)), linha_get_y1(getInfo(barco)), linha_get_x2(getInfo(barco)), linha_get_y2(getInfo(barco)));
                }else{
                    fprintf(textow, "Torpedo atingiu: linha \nid: %d \ncor da borda: %s \nX1: %f \nY1: %f \nX2: %f \nY2: %f \nHP: %d\n", linha_get_id(getInfo(barco)), linha_get_corborda(getInfo(barco)), linha_get_x1(getInfo(barco)), linha_get_y1(getInfo(barco)), linha_get_x2(getInfo(barco)), linha_get_y2(getInfo(barco)), hp);
                }
            }
            break;
        default:
            break;
        }
        if (destruido)
        {
            pontos += getPontuacaoDestruicao(barco);
            fprintf(textow, "Pontos recebidos: %d\n", getPontuacaoDestruicao(barco));
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
        stringSvg(svg, asterisco, x, y, "red", "red", "middle");
    }
    else
    {
        stringSvg(svg, "*", x, y, "gray", "gray", "middle");
        // AGUA no txt
    }
}

void torpedo_replicante(Lista lista, float x, float y, float x1, float y1, int id, FILE *svg, FILE *textow)
{
    int contador = 0;
    float x2, y2, x3, y3, raio, w, h;
    Posic elemento = getFirst(lista);
    Barco *barco;
    char *corb, *corp, *texto, *ancora;
    while (elemento != NULL)
    {
        barco = get(lista, elemento);
        switch (getTipo(barco))
        {
        case 'c':
            raio = circulo_get_r(getInfo(barco));
            x2 = circulo_get_x(getInfo(barco));
            y2 = circulo_get_y(getInfo(barco));
            if (sqrt(pow(x - x2, 2) + pow(y - y2, 2)) < raio)
            {
                contador++;
                corb = circulo_get_corb(getInfo(barco));
                corp = circulo_get_corp(getInfo(barco));
                Barco *circle = create_barco('c', create_circulo(id + contador, x2 + x1, y2 + y1, raio, corp, corb));
                insert(lista, circle);
                fprintf(textow, "Torpedo replicante: circulo \nid: %d \nraio: %f \ncor da borda: %s \ncor de preenchimento: %s \nX: %f \nY: %f \n", circulo_get_id(getInfo(barco)), circulo_get_r(getInfo(barco)), circulo_get_corb(getInfo(barco)), circulo_get_corp(getInfo(barco)), circulo_get_x(getInfo(barco)), circulo_get_y(getInfo(barco)));
                fprintf(textow, "Copia de: circulo \nid: %d \nraio: %f \ncor da borda: %s \ncor de preenchimento: %s \nX: %f \nY: %f \n", circulo_get_id(getInfo(circle)), circulo_get_r(getInfo(circle)), circulo_get_corb(getInfo(circle)), circulo_get_corp(getInfo(circle)), circulo_get_x(getInfo(circle)), circulo_get_y(getInfo(circle)));
            }
            break;
        case 'r':
            x2 = retangulo_get_x(getInfo(barco));
            y2 = retangulo_get_y(getInfo(barco));
            w = retangulo_get_w(getInfo(barco));
            h = retangulo_get_h(getInfo(barco));
            if (x >= x2 && x <= x2 + w && y >= y2 && y <= y2 + h)
            {
                contador++;
                corb = retangulo_get_corb(getInfo(barco));
                corp = retangulo_get_corp(getInfo(barco));
                Barco *rectangle = create_barco('r', create_retangulo(id + contador, x2 + x1, y2 + y1, w, h, corp, corb));
                insert(lista, rectangle);
                fprintf(textow, "Torpedo replicante: retangulo \nid: %d \naltura: %f \nlargura: %f \ncor da borda: %s \ncor de preenchimento: %s \nX: %f \nY: %f \n", retangulo_get_id(getInfo(barco)), retangulo_get_h(getInfo(barco)), retangulo_get_w(getInfo(barco)), retangulo_get_corb(getInfo(barco)), retangulo_get_corp(getInfo(barco)), retangulo_get_x(getInfo(barco)), retangulo_get_y(getInfo(barco)));
                fprintf(textow, "Copia de: retangulo \nid: %d \naltura: %f \nlargura: %f \ncor da borda: %s \ncor de preenchimento: %s \nX: %f \nY: %f \n", retangulo_get_id(getInfo(rectangle)), retangulo_get_h(getInfo(rectangle)), retangulo_get_w(getInfo(rectangle)), retangulo_get_corb(getInfo(rectangle)), retangulo_get_corp(getInfo(rectangle)), retangulo_get_x(getInfo(rectangle)), retangulo_get_y(getInfo(rectangle)));
            }
            break;
        case 't':
            x2 = texto_get_x(getInfo(barco));
            y2 = texto_get_y(getInfo(barco));
            if (x == x2 && y == y2)
            {
                contador++;
                corb = texto_get_corb(getInfo(barco));
                corp = texto_get_corp(getInfo(barco));
                texto = texto_get_conteudo(getInfo(barco));
                ancora = texto_get_ancora(getInfo(barco));
                Barco *text = create_barco('t', create_texto(id + contador, x2 + x1, y2 + y1, corp, corb, texto, ancora));
                insert(lista, text);
                fprintf(textow, "Torpedo replicante: texto \nid: %d \nconteudo: %s \ncor da borda: %s \ncor de preenchimento: %s \nX: %f \nY: %f \n", texto_get_id(getInfo(barco)), texto_get_conteudo(getInfo(barco)), texto_get_corb(getInfo(barco)), texto_get_corp(getInfo(barco)), texto_get_x(getInfo(barco)), texto_get_y(getInfo(barco)));
                fprintf(textow, "Copia de: texto \nid: %d \nconteudo: %s \ncor da borda: %s \ncor de preenchimento: %s \nX: %f \nY: %f \n", texto_get_id(getInfo(text)), texto_get_conteudo(getInfo(text)), texto_get_corb(getInfo(text)), texto_get_corp(getInfo(text)), texto_get_x(getInfo(text)), texto_get_y(getInfo(text)));
            }
            break;
        case 'l':
            x2 = linha_get_x1(getInfo(barco));
            y2 = linha_get_y1(getInfo(barco));
            x3 = linha_get_x2(getInfo(barco));
            y3 = linha_get_y2(getInfo(barco));
            if (((x <= x2 && x >= x3) || (x >= x2 && x <= x3)) && ((y >= y2 && y <= y3) || (y <= y2 && y >= y3)))
            {
                contador++;
                corb = linha_get_cor(getInfo(barco));
                Barco *line = create_barco('l', create_linha(id + contador, x2 + x1, y2 + y1, x3 + x1, y3 + y1, corb));
                insert(lista, line);
                fprintf(textow, "Torpedo replicante: linha \nid: %d \ncor: %s \nX1: %f \nY1: %f \nX2: %f \nY2: %f \n", linha_get_id(getInfo(barco)), linha_get_cor(getInfo(barco)), linha_get_x1(getInfo(barco)), linha_get_y1(getInfo(barco)), linha_get_x2(getInfo(barco)), linha_get_y2(getInfo(barco)));
                fprintf(textow, "Copia de: linha \nid: %d \ncor: %s \nX1: %f \nY1: %f \nX2: %f \nY2: %f \n", linha_get_id(getInfo(line)), linha_get_cor(getInfo(line)), linha_get_x1(getInfo(line)), linha_get_y1(getInfo(line)), linha_get_x2(getInfo(line)), linha_get_y2(getInfo(line)));
            }
            break;
        default:
            break;
        }
        elemento = getNext(lista, elemento);
    }
    stringSvg(svg, "@", x, y, "red", "red", "middle");
}