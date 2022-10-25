#include "svg.h"

FILE *svg_create(char *fullPathSvg)
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

void svg_end(FILE *svg)
{
    if (!svg)
    {
        printf("Erro na finalizacao do SVG!!\n");
        exit(1);
    }
    fprintf(svg, "\n</svg>");
    fclose(svg);
}

void svg_rect(FILE *svg, Barco retangulo)
{
    double x, y, w, h;
    char *corb, *cor;
    x = retangulo_get_x(barco_get_info(retangulo));
    y = retangulo_get_y(barco_get_info(retangulo));
    w = retangulo_get_w(barco_get_info(retangulo));
    h = retangulo_get_h(barco_get_info(retangulo));
    corb = retangulo_get_corb(barco_get_info(retangulo));
    cor = retangulo_get_corp(barco_get_info(retangulo));
    fprintf(svg, "\n\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\"/>", x, y, w, h, cor, corb);
}

void svg_circle(FILE *svg, Barco circulo)
{
    double x, y, r;
    char *corb, *cor;
    x = circulo_get_x(barco_get_info(circulo));
    y = circulo_get_y(barco_get_info(circulo));
    r = circulo_get_r(barco_get_info(circulo));
    corb = circulo_get_corb(barco_get_info(circulo));
    cor = circulo_get_corp(barco_get_info(circulo));
    fprintf(svg, "\n\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\"/>", x, y, r, cor, corb);
}

void svg_line(FILE *svg, Barco linha)
{
    double x1, y1, x2, y2;
    char *cor;
    x1 = linha_get_x1(barco_get_info(linha));
    y1 = linha_get_y1(barco_get_info(linha));
    x2 = linha_get_x2(barco_get_info(linha));
    y2 = linha_get_y2(barco_get_info(linha));
    cor = linha_get_cor(barco_get_info(linha));
    fprintf(svg, "\n\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>", x1, y1, x2, y2, cor);
}

void svg_text(FILE *svg, Barco texto)
{
    double x, y;
    char *corb, *corp, *ancora, *conteudo;
    x = texto_get_x(barco_get_info(texto));
    y = texto_get_y(barco_get_info(texto));
    corb = texto_get_corb(barco_get_info(texto));
    corp = texto_get_corp(barco_get_info(texto));
    ancora = texto_get_ancora(barco_get_info(texto));
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
    conteudo = texto_get_conteudo(barco_get_info(texto));
    fprintf(svg, "\n\t<text font-size=\"5\" x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\" text-anchor=\"%s\">%s</text>", x, y, corp, corb, ancora, conteudo);
}

FILE *svg_write(char *pathOut, char *fileName)
{
    char s[] = ".svg";
    char fullPathSvg[200] = "";
    joinAll(pathOut, fileName, s, fullPathSvg, 200);
    FILE *svg = svg_create(fullPathSvg);
    return svg;
}

void svg_string(FILE *svg, char *string, double x, double y, char *corp, char *corb, char *ancora)
{
    fprintf(svg, "\n\t<text font-size=\"5\" x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\" text-anchor=\"%s\">%s</text>", x, y, corp, corb, ancora, string);
}

void svg_barcos(FILE *svg, Lista barcos)
{
    Posic aux = getFirst(barcos);
    while (aux != NULL)
    {
        switch (barco_get_tipo(get(barcos, aux)))
        {
        case 'c':
            svg_circle(svg, get(barcos, aux));
            break;
        case 'r':
            svg_rect(svg, get(barcos, aux));
            break;
        case 'l':
            svg_line(svg, get(barcos, aux));
            break;
        case 't':
            svg_text(svg, get(barcos, aux));
            break;
        case 'm':
            svg_text(svg, get(barcos, aux));
            break;
        }
        aux = getNext(barcos, aux);
    }
}