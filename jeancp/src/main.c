#include "objetos.h"

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Uso: ted [-e path] -f arq.geo [-q consulta.qry] -o dir");
        return 1;
    }
    char *arqQry = (char *)malloc(sizeof(char) * 200);
    char *arqGeo = (char *)malloc(sizeof(char) * 200);
    char *dir = (char *)malloc(sizeof(char) * 200);
    char *path = (char *)malloc(sizeof(char) * 200);
    if (strcmp(argv[1], "-e") == 0)
    {
        normalizePath(argv[2], path, strlen(argv[2]));
        if (strcmp(argv[3], "-f") == 0)
        {
            strcpy(arqGeo, argv[4]);
            if (strcmp(argv[5], "-q") == 0)
            {
                strcpy(arqQry, argv[6]);
                if (strcmp(argv[7], "-o") == 0)
                {
                    normalizePath(argv[8], dir, strlen(argv[8]));
                }
                else
                {
                    printf("Uso: ted [-e path] -f arq.geo [-q consulta.qry] -o dir");
                    return 1;
                }
            }
            else if (strcmp(argv[5], "-o") == 0)
            {
                normalizePath(argv[6], dir, strlen(argv[6]));
            }
            else
            {
                printf("Uso: ted [-e path] -f arq.geo [-q consulta.qry] -o dir");
                return 1;
            }
        }
        else
        {
            printf("Uso: ted [-e path] -f arq.geo [-q consulta.qry] -o dir");
            return 1;
        }
    }
    else
    {
        path = ".";
        if (strcmp(argv[1], "-f") == 0)
        {
            strcpy(arqGeo, argv[2]);
            if (strcmp(argv[3], "-q") == 0)
            {
                strcpy(arqQry, argv[4]);
                if (strcmp(argv[5], "-o") == 0)
                {
                    normalizePath(argv[6], dir, strlen(argv[6]));
                }
                else
                {
                    printf("Uso: ted [-e path] -f arq.geo [-q consulta.qry] -o dir");
                    return 1;
                }
            }
            else if (strcmp(argv[3], "-o") == 0)
            {
                normalizePath(argv[4], dir, strlen(argv[4]));
            }
            else
            {
                printf("Uso: ted [-e path] -f arq.geo [-q consulta.qry] -o dir");
                return 1;
            }
        }
        else
        {
            printf("Uso: ted [-e path] -f arq.geo [-q consulta.qry] -o dir");
            return 1;
        }
    }
    Lista listabarcos = createLista(-1);
    Lista listaminas = createLista(-1);
    geo_read(path, arqGeo, listabarcos, listaminas);
    FILE *svg = svg_write(dir, arqGeo);
    if (arqQry != NULL)
    {
        qry_read(path, arqQry, listabarcos, svg, listaminas);
    }
    svg_barcos(svg, listabarcos);
    svg_end(svg);
    killLista(listabarcos);
    killLista(listaminas);
    free(arqQry);
    free(arqGeo);
    free(dir);
    free(path);
    return 0;
}