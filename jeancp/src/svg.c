#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"
#include "retangulo.h"
#include "circulo.h"
#include "lista.h"
#include "linha.h"
#include "texto.h"

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

void rect(FILE *svg, Retangulo retangulo)
{
    fprintf(svg, "\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\"/>", get_rectangleX(retangulo), get_rectangleY(retangulo), get_rectangleW(retangulo), get_rectangleH(retangulo), get_rectangleCORP(retangulo), get_rectangleCORB(retangulo));
}

void circle(FILE *svg, Circulo circulo)
{
    fprintf(svg, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\"/>", get_circuloX(circulo), get_circuloY(circulo), get_circuloR(circulo), get_circuloCORP(circulo), get_circuloCORB(circulo));
}

void line(FILE *svg, Line linha)
{
    fprintf(svg, "\n\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\"/>", get_lineX1(linha), get_lineY1(linha), get_lineX2(linha), get_lineY2(linha), get_lineCOR(linha));
}

void text(FILE *svg, Text texto)
{
    fprintf(svg, "\n\t<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" text-anchor=\"%s\">%s</text>", get_textX(texto), get_textY(texto), get_textCORP(texto), get_textCORB(texto), get_textANCORA(texto), get_textTXT(texto));
}

void rec_sel(FILE *svg, Retangulo retangulo)
{
    fprintf(svg, "\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"none\" stroke=\"red\"/>", get_rectangleX(retangulo), get_rectangleY(retangulo), get_rectangleW(retangulo), get_rectangleH(retangulo));
}

void writeSvg(char *pathOut, char *nameArq, Lista list)
{
    char s[] = "svg";
    char *nameSvg = s;
    char *nameArqExtr = (char *)extractName(nameArq);
    char *nameArqSvg = insertExtension(nameArqExtr, nameSvg);
    char *fullPathSvg = catPath(pathOut, nameArqSvg);

    FILE *svg = createSvg(fullPathSvg, list);
    Node aux = getListFirst(list);

    while (aux != NULL)
    {
        switch (getTYPE(aux))
        {
        case 1:
            circle(svg, getListItem(aux));
            break;
        case 2:
            rect(svg, getListItem(aux));
            break;
        case 3:
            line(svg, getListItem(aux));
            break;
        case 4:
            text(svg, getListItem(aux));
            break;
        }
        aux = getListNext(aux);
    }

    endSvg(svg);

    free(nameArqExtr);
    free(nameArqSvg);
    free(fullPathSvg);
}
