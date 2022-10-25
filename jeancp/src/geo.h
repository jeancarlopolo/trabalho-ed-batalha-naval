#ifndef _GEO_H
#define _GEO_H

#include "lista.h"

/** geo_read recebe o caminho do arquivo geo e o nome do arquivo geo e uma lista e adiciona os elementos do arquivo geo na lista */
void geo_read(char *path, char *fileName, Lista *lista, Lista *listaminas);

#endif
