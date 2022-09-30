#include <stdio.h>
#include <stdlib.h>

#include "retangulo.h"
#include "linha.h"
#include "circulo.h"
#include "texto.h"
#include "path.h"
#include "geo.h"

void readGeo(char *path, char *fileName, char *ext, Lista *lista)
{
    char type[100];
    float x, y, w, h, r;
    char corb[100], corp[100], text[200];
    int id;
    char ancora[1];
    char *fullPath = (char *)malloc(sizeof(char) * 100);
    joinAll(path, fileName, ext, fullPath, strlen(fullPath));
    FILE *geo = fopen(fullPath, "r");
    while (!feof(geo))
    {
        fscanf(geo, "%s", type);
        if (strcmp(type, "c") == 0)
        {
            fscanf(geo, "%d %f %f %f %s %s", &id, &r, &x, &y, corb, corp);
            Circulo *circulo = criaCirculo(id, r, x, y, corb, corp);
            insereLista(lista, circulo);
        }
        else if (strcmp(type, "r") == 0)
        {
            fscanf(geo, "%d %f %f %f %f %s %s", &id, &w, &h, &x, &y, corb, corp);
            Retangulo *retangulo = criaRetangulo(id, w, h, x, y, corb, corp);
            insereLista(lista, retangulo);
        }
        else if (strcmp(type, "t") == 0)
        {
            fscanf(geo, "%d %f %f %s %s", &id, &x, &y, ancora, corb);
            fgets(text, 200, geo);
            Texto *texto = criaTexto(id, x, y, ancora, corb, text);
            insereLista(lista, texto);
        }
        else if (strcmp(type, "l") == 0)
        {
            fscanf(geo, "%d %f %f %f %f %s", &id, &x, &y, &w, &h, corb);
            Linha *linha = criaLinha(id, x, y, w, h, corb);
            insereLista(lista, linha);
        };
    }
}
