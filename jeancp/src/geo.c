#include <stdio.h>
#include <stdlib.h>

#include "retangulo.h"
#include "linha.h"
#include "circulo.h"
#include "texto.h"
#include "path.h"
#include "geo.h"
#include "barco.h"
#include "mina.h"

void readGeo(char *path, char *fileName, Lista *lista)
{
    char type[200];
    float x, y, w, h, r;
    char corb[200], corp[200], text[200];
    int id;
    char ancora[1];
    char fullPath[200];
    ;
    joinFilePath(path, fileName, fullPath, 200);
    FILE *geo = fopen(fullPath, "r");
    if (geo == NULL)
    {
        printf("Erro ao abrir o arquivo %s!", fullPath);
        exit(1);
    }
    while (fscanf(geo, "%[^\n] ", type) != EOF)
    {
        fscanf(geo, "%s", type);
        switch (type[0])
        {
        case 'c':
        {
            fscanf(geo, "%d %f %f %f %s %s", &id, &x, &y, &r, corb, corp);
            Barco *circle = create_barco((char*)'c', create_circulo(id, x, y, r, corb, corp));
            insert(lista, circle);
            break;
        }
        case 'r':
        {
            fscanf(geo, "%d %f %f %f %f %s %s", &id, &x, &y, &w, &h, corb, corp);
            Barco *retan = create_barco((char*)'r', create_retangulo(id, x, y, w, h, corb, corp));
            insert(lista, retan);
            break;
        }
        case 't':
        {
            fscanf(geo, "%d %f %f %s %s %c", &id, &x, &y, corb, corp, ancora);
            fgets(text, 200, geo);
            Barco *txt;
            if (strcmp(text, "#")==0)
            {
                createMina(id, x, y, corb, corp, ancora);
            }else{
            txt = create_barco((char*)'t', create_texto(id, x, y, corb, corp, text, ancora));
            }
            insert(lista, txt);
            break;
        }
        case 'l':
        {
            fscanf(geo, "%d %f %f %f %f %s", &id, &x, &y, &w, &h, corb);
            Barco *linha = create_barco((char*)'l', create_linha(id, x, y, w, h, corb));
            insert(lista, linha);
            break;
        };
        default:
            break;
        }
    }
    fclose(geo);
}
