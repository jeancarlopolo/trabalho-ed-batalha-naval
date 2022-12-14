#include "objetos.h"

int main(int argc, char *argv[])
{

    char *arqQry = (char *)malloc(sizeof(char) * 200);
    char *arqGeo = (char *)malloc(sizeof(char) * 200);
    char *dir = (char *)malloc(sizeof(char) * 200);
    char *path = (char *)malloc(sizeof(char) * 200);
    char *resultado = (char *)malloc(sizeof(char) * 200);
    char *aux = (char *)malloc(sizeof(char) * 200);
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-e") == 0)
        {
            normalizePath(argv[i + 1], path, strlen(argv[i + 1]));
        }
        if (strcmp(argv[i], "-f") == 0)
        {
            strcpy(arqGeo, argv[i + 1]);
        }
        if (strcmp(argv[i], "-q") == 0)
        {
            strcpy(arqQry, argv[i + 1]);
        }
        if (strcmp(argv[i], "-o") == 0)
        {
            normalizePath(argv[i + 1], dir, strlen(argv[i + 1]));
        }
    }
    Lista listabarcos = createLista(-1);
    Lista listaminas = createLista(-1);
    geo_read(path, arqGeo, listabarcos, listaminas);
    strcpy(resultado, arqGeo);
    strcpy(aux, arqQry);
    char *pointerchar = strrchr(resultado, '.');
    *pointerchar = '\0';
    pointerchar = strrchr(aux, '.');
    *pointerchar = '\0';
    strcat(resultado, aux);
    FILE *svg = svg_write(dir, resultado);
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
    free(resultado);
    free(aux);
    return 0;
}