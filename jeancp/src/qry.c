#include "qry.h"
#include "path.h"

void read_qry(char *path, char *fileName, Lista *lista, FILE* svg, Lista *listaminas)
{
    Lista listasSelec = createLista(-1);
    char type[100];
    float x, y, dx, dy, r, na = 0;
    int id, j, k;
    char *fullPath = (char *)malloc(sizeof(char) * 100);
    joinFilePath(path, fileName, fullPath, 100);
    FILE *qry = fopen(fullPath, "r");
    while (!feof(qry))
    {
        fscanf(qry, "%s", type);
        if (type[0] == 'n' && type[1] == 'a')
        {
            fscanf(qry, "%f", &na);
        }
        else if (type[0] == 't')
        {
            if (type[1] == 'p')
            {
                fscanf(qry, "%f %f", &x, &y);
                torpedo(lista, x, y, svg);
            }
            else if (type[1] == 'r')
            {
                fscanf(qry, "%f %f %f %f %d", &x, &y, &dx, &dy, &id);
                torpedo_replicante(lista, x, y, dx, dy, id, svg);
            }
        }
        else if (type[0] == 'b' && type[1] == 'e')
        {
            fscanf(qry, "%f %f %f", &x, &y, &r);
            bomba_rad(lista, x, y, r, na, svg);
        }
        else if (type[0] == 'm' && type[1] == 'v')
        {
            if (type[2] == 'h')
            {
                fscanf(qry, "%d %d %f", &j, &k, &x);
                move_barco(listasSelec, x, 0, listaminas, lista, svg);
            }
            else if (type[2] == 'v')
            {
                fscanf(qry, "%d %d %f", &j, &k, &y);
                move_barco(listasSelec, 0, y, listaminas, lista, svg);
                //move_vertical(lista, j, k, y);
            }
        }

    }
    free(fullPath);
    fclose(qry);
}