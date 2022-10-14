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
    fprintf(svg, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\"/>", circulo_get_x(circulo), circulo_get_y(circulo), circulo_get_r(circulo), circulo_get_corp(circulo), circulo_get_corb(circulo));
}

void lineSvg(FILE *svg, Barco linha)
{
    fprintf(svg, "\n\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\"/>", linha_get_x1(linha), linha_get_y1(linha), linha_get_x2(linha), linha_get_y2(linha), linha_get_cor(linha));
}

void textSvg(FILE *svg, Barco texto)
{
    fprintf(svg, "\n\t<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" text-anchor=\"%s\">%s</text>", texto_get_x(texto), texto_get_y(texto), texto_get_corp(texto), texto_get_corb(texto), texto_get_ancora(texto), texto_get_conteudo(texto));
}

void writeSvg(char *pathOut, char *fileName, Lista list)
{
    char s[] = ".svg";
    char fullPathSvg[200] = "";
    joinAll(pathOut, fileName, s, fullPathSvg, 200);
    FILE *svg = createSvg(fullPathSvg);
    Barco aux = getFirst(list);
    while (aux != NULL)
    {
        switch (getTipo(get(list, aux)))
        {
        case 'c':
            circleSvg(svg, (Barco) get(list, aux));
            break;
        case 'r':
            rectSvg(svg, get(list, aux));
            break;
        case 'l':
            lineSvg(svg, get(list, aux));
            break;
        case 't':
            textSvg(svg, get(list, aux));
            break;
        }
        aux = getNext(list, aux);
    }
    endSvg(svg);
}
