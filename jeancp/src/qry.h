#ifndef _QRY_H
#define _QRY_H

#include "lista.h"
#include "torpedos.h"

/**READ_QRY lê o arquivo qry e chama as funções necessárias para a execução dos comandos*/
void read_qry(char *path, char *fileName, Lista *lista, FILE* svg);
#endif