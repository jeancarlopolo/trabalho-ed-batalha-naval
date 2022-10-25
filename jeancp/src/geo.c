#include <stdio.h>
#include <stdlib.h>

#include "path.h"
#include "geo.h"
#include "barco.h"
#include "mina.h"

void geo_read(char *path, char *fileName, Lista *lista, Lista *listaminas)
{
    char type[200];
    double x, y, w, h, r;
    char corb[200], corp[200], text[200];
    int id;
    char ancora[1];
    char fullPath[200];
    joinFilePath(path, fileName, fullPath, 200);
    FILE *geo = fopen(fullPath, "r");
    if (geo == NULL)
    {
        printf("Erro ao abrir o arquivo %s!", fullPath);
        exit(1);
    }
    while (true)
    {
        fscanf(geo, "%s", type);
        if (feof(geo))
        {
            break;
        }
        switch (type[0])
        {
        case 'c':
        {
            fscanf(geo, "%d %lf %lf %lf %s %s", &id, &x, &y, &r, corb, corp);
            Barco *circle = create_barco('c', create_circulo(id, x, y, r, corb, corp));
            insert(lista, circle);
            break;
        }
        case 'r':
        {
            fscanf(geo, "%d %lf %lf %lf %lf %s %s", &id, &x, &y, &w, &h, corb, corp);
            Barco *retan = create_barco('r', create_retangulo(id, x, y, w, h, corb, corp));
            insert(lista, retan);
            break;
        }
        case 't':
        {
            fscanf(geo, "%d %lf %lf %s %s %c", &id, &x, &y, corb, corp, ancora);
            fgets(text, 200, geo);
            Barco *txt;
            if (strcmp(text, "#") == 0)
            {
                txt = createMina(id, x, y, corb, corp, ancora);
                insert(listaminas, txt);
            }
            else
            {
                txt = create_barco('t', create_texto(id, x, y, corb, corp, text, ancora));
                insert(lista, txt);
            }
            break;
        }
        case 'l':
        {
            fscanf(geo, "%d %lf %lf %lf %lf %s", &id, &x, &y, &w, &h, corb);
            Barco *linha = create_barco('l', create_linha(id, x, y, w, h, corb));
            insert(lista, linha);
            break;
        };
        default:
            break;
        }
    }
    fclose(geo);
}
