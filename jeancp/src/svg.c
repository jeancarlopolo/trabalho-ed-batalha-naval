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
    fprintf(svg, "\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\"/>", retangulo_get_x(retangulo), retangulo_get_y(retangulo), retangulo_get_w(retangulo), retangulo_get_h(retangulo), retangulo_get_corp(retangulo), retangulo_get_corb(retangulo));
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
    char *fullPathSvg = (char *)malloc(sizeof(char) * 100);
    joinAll(pathOut, fileName, s, fullPathSvg, 100);
    FILE *svg = createSvg(fullPathSvg);
    Barco aux = getFirst(list);
    while (aux != NULL)
    {
        switch (getTipo(aux))
        {
        case 'c':
            circleSvg(svg, aux);
            break;
        case 'r':
            rectSvg(svg, aux);
            break;
        case 'l':
            lineSvg(svg, aux);
            break;
        case 't':
            textSvg(svg, aux);
            break;
        }
        aux = getNext(list, aux);
    }
    free(fullPathSvg);
    endSvg(svg);
}
