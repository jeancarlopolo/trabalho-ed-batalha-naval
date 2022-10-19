#include "svg.h"

FILE *createSvg(char *fullPathSvg)
{
    FILE *svg = fopen(fullPathSvg, "w");
    if (!svg)
    {
        printf("Erro na criacao do SVG!!\n");
        free(fullPathSvg);
        exit(1);
    }
    fprintf(svg, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
    return svg;
}

void endSvg(FILE *svg)
{
    if (!svg)
    {
        printf("Erro na finalizacao do SVG!!\n");
        exit(1);
    }
    fprintf(svg, "\n</svg>");
    fclose(svg);
}

void rectSvg(FILE *svg, Barco retangulo)
{
    float x, y, w, h;
    char *corb, *cor;
    x = retangulo_get_x(getInfo(retangulo));
    y = retangulo_get_y(getInfo(retangulo));
    w = retangulo_get_w(getInfo(retangulo));
    h = retangulo_get_h(getInfo(retangulo));
    corb = retangulo_get_corb(getInfo(retangulo));
    cor = retangulo_get_corp(getInfo(retangulo));
    fprintf(svg, "\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\"/>", x, y, w, h, cor, corb);
}

void circleSvg(FILE *svg, Barco circulo)
{
    float x, y, r;
    char *corb, *cor;
    x = circulo_get_x(getInfo(circulo));
    y = circulo_get_y(getInfo(circulo));
    r = circulo_get_r(getInfo(circulo));
    corb = circulo_get_corb(getInfo(circulo));
    cor = circulo_get_corp(getInfo(circulo));
    fprintf(svg, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\"/>", x, y, r, cor, corb);
}

void lineSvg(FILE *svg, Barco linha)
{
    float x1, y1, x2, y2;
    char *cor;
    x1 = linha_get_x1(getInfo(linha));
    y1 = linha_get_y1(getInfo(linha));
    x2 = linha_get_x2(getInfo(linha));
    y2 = linha_get_y2(getInfo(linha));
    cor = linha_get_cor(getInfo(linha));
    fprintf(svg, "\n\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\"/>", x1, y1, x2, y2, cor);
}

void textSvg(FILE *svg, Barco texto)
{
    float x, y;
    char *corb, *corp, *ancora, *conteudo;
    x = texto_get_x(getInfo(texto));
    y = texto_get_y(getInfo(texto));
    corb = texto_get_corb(getInfo(texto));
    corp = texto_get_corp(getInfo(texto));
    ancora = texto_get_ancora(getInfo(texto));
    switch (ancora[0])
    {
    case 'i':
        ancora = "start";
        break;
    case 'm':
        ancora = "middle";
        break;
    case 'f':
        ancora = "end";
        break;
    default:
        ancora = "start";
        break;
    }
        conteudo = texto_get_conteudo(getInfo(texto));
        fprintf(svg, "\n\t<text font-size=\"5\" x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" text-anchor=\"%s\">%s</text>", x, y, corp, corb, ancora, conteudo);
    }

    FILE *writeSvg(char *pathOut, char *fileName)
    {
        char s[] = ".svg";
        char fullPathSvg[200] = "";
        joinAll(pathOut, fileName, s, fullPathSvg, 200);
        FILE *svg = createSvg(fullPathSvg);
        return svg;
    }

    void stringSvg(FILE * svg, char *string, float x, float y, char *corp, char *corb, char *ancora)
    {
        fprintf(svg, "\n\t<text font-size=\"5\" x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" text-anchor=\"%s\">%s</text>", x, y, corp, corb, ancora, string);
    }

    void barcosSvg(FILE * svg, Lista barcos)
    {
        Posic aux = getFirst(barcos);
        while (aux != NULL)
        {
            switch (getTipo(get(barcos, aux)))
            {
            case 'c':
                circleSvg(svg, get(barcos, aux));
                break;
            case 'r':
                rectSvg(svg, get(barcos, aux));
                break;
            case 'l':
                lineSvg(svg, get(barcos, aux));
                break;
            case 't':
                textSvg(svg, get(barcos, aux));
                break;
            case 'm':
                textSvg(svg, get(barcos, aux));
                break;
            }
            aux = getNext(barcos, aux);
        }
    }