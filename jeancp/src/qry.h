#ifndef _QRY_H
#define _QRY_H

#include "lista.h"
#include "torpedos.h"
#include "bomba.h"
#include "movimentacao.h"

/** qry_read lê o arquivo qry e chama as funções necessárias para a execução dos comandos*/
void qry_read(char *path, char *fileName, Lista *lista, FILE *svg, Lista *listaminas);
#endif