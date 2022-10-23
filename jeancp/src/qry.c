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
                move_barco(listasSelec, x, 0, listaminas, lista, svg, j, k, textow);
            }
            else if (type[2] == 'v')
            {
                fscanf(qry, "%d %d %f", &j, &k, &y);
                move_barco(listasSelec, 0, y, listaminas, lista, svg, j, k, textow);
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
                            fprintf(textow, "retangulo selecionado para nau capita \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \narea: %f \nX: %f \nY: %f \n", retangulo_get_i(getInfo(barco)), retangulo_get_corb(getInfo(barco)), retangulo_get_corp(getInfo(barco)), retangulo_get_area(getInfo(barco)), retangulo_get_x(getInfo(barco)), retangulo_get_y(getInfo(barco)));
                        }
                        break;
                    case 'c':
                        if (id == circulo_get_i(getInfo(barco)))
                        {
                            setCapitao(barco, idc);
                            insert(listasSelec, barco);
                            fprintf(textow, "circulo selecionado para nau capita \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \nraio: %f \narea: %f \nX: %f \nY: %f \n", circulo_get_i(getInfo(barco)), circulo_get_corb(getInfo(barco)), circulo_get_corp(getInfo(barco)), circulo_get_r(getInfo(barco)), circulo_get_area(getInfo(barco)), circulo_get_x(getInfo(barco)), circulo_get_y(getInfo(barco)));
                        }
                        break;
                    case 't':
                        if (id == texto_get_i(getInfo(barco)))
                        {
                            setCapitao(barco, idc);
                            insert(listasSelec, barco);
                            fprintf(textow, "texto selecionado para nau capita \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \nX: %f \nY: %f \n", texto_get_i(getInfo(barco)), texto_get_corb(getInfo(barco)), texto_get_corp(getInfo(barco)), texto_get_x(getInfo(barco)), texto_get_y(getInfo(barco)));
                        }
                        break;
                    case 'l':
                        if (id == linha_get_i(getInfo(barco)))
                        {
                            setCapitao(barco, idc);
                            insert(listasSelec, barco);
                            fprintf(textow, "linha selecionada para nau capita \nid: %d \ncor: %s \nX1: %f \nY1: %f \nX2: %f \nY2: %f \n", linha_get_i(getInfo(barco)), linha_get_cor(getInfo(barco)), linha_get_x1(getInfo(barco)), linha_get_y1(getInfo(barco)), linha_get_x2(getInfo(barco)), linha_get_y2(getInfo(barco)));
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
                            fprintf(textow, "retangulo selecionado \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \narea: %f \nX: %f \nY: %f \n", retangulo_get_i(getInfo(barco)), retangulo_get_corb(getInfo(barco)), retangulo_get_corp(getInfo(barco)), retangulo_get_area(getInfo(barco)), retangulo_get_x(getInfo(barco)), retangulo_get_y(getInfo(barco)));
                            break;
                        }
                        break;
                    case 'c':
                        if (circulo_get_i(getInfo(barco)) == id)
                        {
                            insert(listasSelec, barco);
                            fprintf(textow, "circulo selecionado \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \nraio: %f \narea: %f \nX: %f \nY: %f \n", circulo_get_i(getInfo(barco)), circulo_get_corb(getInfo(barco)), circulo_get_corp(getInfo(barco)), circulo_get_r(getInfo(barco)), circulo_get_area(getInfo(barco)), circulo_get_x(getInfo(barco)), circulo_get_y(getInfo(barco)));
                            break;
                        }
                        break;
                    case 't':
                        if (texto_get_i(getInfo(barco)) == id)
                        {
                            insert(listasSelec, barco);
                            fprintf(textow, "texto selecionado \nid: %d \ncor da borda: %s \ncor do preenchimento: %s \nX: %f \nY: %f \n", texto_get_i(getInfo(barco)), texto_get_corb(getInfo(barco)), texto_get_corp(getInfo(barco)), texto_get_x(getInfo(barco)), texto_get_y(getInfo(barco)));
                            break;
                        }
                        break;
                    case 'l':
                        if (linha_get_i(getInfo(barco)) == id)
                        {
                            insert(listasSelec, barco);
                            fprintf(textow, "linha selecionada \nid: %d \ncor: %s \nX1: %f \nY1: %f \nX2: %f \nY2: %f \n", linha_get_i(getInfo(barco)), linha_get_cor(getInfo(barco)), linha_get_x1(getInfo(barco)), linha_get_y1(getInfo(barco)), linha_get_x2(getInfo(barco)), linha_get_y2(getInfo(barco)));
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
    fclose(textow);
    fclose(qry);
}