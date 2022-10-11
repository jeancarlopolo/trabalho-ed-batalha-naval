#include "objetos.h"

int main(int argc, char const *argv[])
{
    if (argc < 4)
    {
        printf("Uso: ted [-e path] -f arq.geo [-q consulta.qry] -o dir");
        return 1;
    }
    char *arqQry = (char *)malloc(sizeof(char) * 100);
    char *arqGeo = (char *)malloc(sizeof(char) * 100);
    char *dir = (char *)malloc(sizeof(char) * 100);
    char *path = (char *)malloc(sizeof(char) * 100);
    if (argv[1] == "-e")
    {
        normalizePath(argv[2], path, strlen(path));
        if (argv[3] == "-f")
        {
            strcpy(arqGeo, argv[4]);
            if (argv[5] == "-q")
            {
                strcpy(arqQry, argv[6]);
                if (argv[7] == "-o")
                {
                    normalizePath(argv[8], dir, strlen(dir));
                }
                else
                {
                    printf("Uso: ted [-e path] -f arq.geo [-q consulta.qry] -o dir");
                    return 1;
                }
            }
            else if (argv[5] == "-o")
            {
                normalizePath(argv[6], dir, strlen(dir));
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
        if (argv[1] == "-f")
        {
            strcpy(arqGeo, argv[2]);
            if (argv[3] == "-q")
            {
                strcpy(arqQry, argv[4]);
                if (argv[5] == "-o")
                {
                    normalizePath(argv[6], dir, strlen(dir));
                }
                else
                {
                    printf("Uso: ted [-e path] -f arq.geo [-q consulta.qry] -o dir");
                    return 1;
                }
            }
            else if (argv[3] == "-o")
            {
                normalizePath(argv[4], dir, strlen(dir));
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
    read_geo(path, arqGeo, listabarcos);
    if (arqQry != NULL)
    {
        create_txt(dir);
        read_qry(path, arqQry, listabarcos);
    }
    create_svg(dir, listabarcos);
    free(arqQry);
    free(arqGeo);
    free(dir);
    free(path);
    return 0;
}