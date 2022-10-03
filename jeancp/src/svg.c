#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "path.h"
#include "retangulo.h"
#include "circulo.h"
#include "lista.h"
#include "linha.h"
#include "texto.h"
#include "barco.h"

FILE *createSvg(char *fullPathSvg, Lista list)
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

void rectSvg(FILE *svg, Retangulo retangulo)
{
    fprintf(svg, "\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\"/>", retangulo_get_x(retangulo), retangulo_get_y(retangulo), retangulo_get_w(retangulo), retangulo_get_h(retangulo), retangulo_get_corp(retangulo), retangulo_get_corb(retangulo));
}

void circleSvg(FILE *svg, Circulo circulo)
{
    fprintf(svg, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\"/>", circulo_get_x(circulo), circulo_get_y(circulo), circulo_get_r(circulo), circulo_get_corp(circulo), circulo_get_corb(circulo));
}

void lineSvg(FILE *svg, Linha linha)
{
    fprintf(svg, "\n\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\"/>", linha_get_x1(linha), linha_get_y1(linha), linha_get_x2(linha), linha_get_y2(linha), linha_get_cor(linha));
}

void textSvg(FILE *svg, Texto texto)
{
    fprintf(svg, "\n\t<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" text-anchor=\"%s\">%s</text>", texto_get_x(texto), texto_get_y(texto), texto_get_corp(texto), texto_get_corb(texto), texto_get_ancora(texto), texto_get_conteudo(texto));
}

void writeSvg(char *pathOut, char *fileName, Lista list)
{
    char s[] = "svg";
    char *fullPathSvg = (char *)malloc(sizeof(char) * 100);
    joinAll(pathOut, fileName, s, fullPathSvg, 100);
    FILE *svg = createSvg(fullPathSvg, list);
    Barco aux = getFirst(list);
    while (aux != NULL)
    {
        switch (getBarcoTipo(aux))
        {
        case 'c':
            circleSvg(svg, getListItem(aux));
            break;
        case 'r':
            rectSvg(svg, getListItem(aux));
            break;
        case 'l':
            lineSvg(svg, getListItem(aux));
            break;
        case 't':
            textSvg(svg, getListItem(aux));
            break;
        }
        aux = getNext(list, aux);
    }
    free(fullPathSvg);
    endSvg(svg);
}
