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
        switch (type[0])
        {
        case 'c':
        {
            fscanf(geo, "%d %f %f %f %s %s", &id, &x, &y, &r, corb, corp);
            Barco *circulo = create_circulo(id, x, y, r, corb, corp);
            insert(lista, circulo);
            break;
        }
        case 'r':
        {
            fscanf(geo, "%d %f %f %f %f %s %s", &id, &x, &y, &w, &h, corb, corp);
            Barco *retangulo = create_retangulo(id, x, y, w, h, corb, corp);
            insert(lista, retangulo);
            break;
        }
        case 't':
        {
            fscanf(geo, "%d %f %f %s %s %c", &id, &x, &y, corb, corp, ancora);
            fgets(text, 200, geo);
            Barco *texto = create_texto(id, x, y, corb, corp, ancora, text);
            insert(lista, texto);
            break;
        }
        case 'l':
        {
            fscanf(geo, "%d %f %f %f %f %s", &id, &x, &y, &w, &h, corb);
            Barco *linha = create_linha(id, x, y, w, h, corb);
            insert(lista, linha);
            break;
        };
        default:
            break;
        }
    }
    fclose(geo);
    free(fullPath);
}
