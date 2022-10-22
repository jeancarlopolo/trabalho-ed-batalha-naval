#include "qry.h"
#include "path.h"

void read_qry(char *path, char *fileName, Lista *lista, FILE *svg, Lista *listaminas)
{
    FILE *textow = fopen("relatorio.txt", "w");
    Lista listasSelec = createLista(-1);
    char type[100];
    float x, y, dx, dy, r, na = 0;
    int id, j, k, idc;
    char *fullPath = (char *)malloc(sizeof(char) * 100);
    Posic elemento;
    Barco *barco;
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
                torpedo(lista, x, y, svg, textow);
            }
            else if (type[1] == 'r')
            {
                fscanf(qry, "%f %f %f %f %d", &x, &y, &dx, &dy, &id);
                torpedo_replicante(lista, x, y, dx, dy, id, svg, textow);
            }
        }
        else if (type[0] == 'b' && type[1] == 'e')
        {
            fscanf(qry, "%f %f %f", &x, &y, &r);
            bomba_rad(lista, x, y, r, na, svg, textow);
        }
        else if (type[0] == 'm' && type[1] == 'v')
        {
            if (type[2] == 'h')
            {
                fscanf(qry, "%d %d %f", &j, &k, &x);
                move_barco(listasSelec, x, 0, listaminas, lista, svg, j, k);
            }
            else if (type[2] == 'v')
            {
                fscanf(qry, "%d %d %f", &j, &k, &y);
                move_barco(listasSelec, 0, y, listaminas, lista, svg, j, k);
                // move_vertical(lista, j, k, y);
            }
        }
        else if (type[0] == 's' && type[1] == 'e')
        {
            if (type[2] == 'c')
            {
                fscanf(qry, "%d %d", &id, &idc);
                elemento = getFirst(lista);
                while (elemento != NULL)
                {
                    barco = get(lista, elemento);
                    switch (getTipo(barco))
                    {
                    case 'r':
                        if (id == retangulo_get_i(getInfo(barco)))
                        {
                            setCapitao(barco, idc);
                            insert(listasSelec, barco);
                        }
                        break;
                    case 'c':
                        if (id == circulo_get_i(getInfo(barco)))
                        {
                            setCapitao(barco, idc);
                            insert(listasSelec, barco);
                        }
                        break;
                    case 't':
                        if (id == texto_get_i(getInfo(barco)))
                        {
                            setCapitao(barco, idc);
                            insert(listasSelec, barco);
                        }
                        break;
                    case 'l':
                        if (id == linha_get_i(getInfo(barco)))
                        {
                            setCapitao(barco, idc);
                            insert(listasSelec, barco);
                        }
                        break;
                    default:
                        break;
                    }
                    elemento = getNext(lista, elemento);
                }
            }
            else
            {
                fscanf(qry, "%d", &id);
                elemento = getFirst(lista);
                while (elemento != NULL)
                {
                    barco = get(lista, elemento);
                    switch (getTipo(barco))
                    {
                    case 'r':
                        if (retangulo_get_i(getInfo(barco)) == id)
                        {
                            insert(listasSelec, barco);
                            break;
                        }
                        break;
                    case 'c':
                        if (circulo_get_i(getInfo(barco)) == id)
                        {
                            insert(listasSelec, barco);
                            break;
                        }
                        break;
                    case 't':
                        if (texto_get_i(getInfo(barco)) == id)
                        {
                            insert(listasSelec, barco);
                            break;
                        }
                        break;
                    case 'l':
                        if (linha_get_i(getInfo(barco)) == id)
                        {
                            insert(listasSelec, barco);
                            break;
                        }
                        break;
                    default:
                        break;
                    }

                    elemento = getNext(lista, elemento);
                }
            }
        }
    }
    free(fullPath);
    fclose(qry);
}