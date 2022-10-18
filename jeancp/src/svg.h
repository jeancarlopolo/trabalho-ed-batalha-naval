#ifndef _SVG_H
#define _SVG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "barco.h"
#include "retangulo.h"
#include "linha.h"
#include "circulo.h"
#include "texto.h"
#include "path.h"

/**
Um arquivo SVG é um arquivo de texto que contém informações sobre formas geométricas, textos e imagens. Ele é composto
por tags que definem o que será desenhado e como será desenhado. É possível abrir um arquivo SVG em qualquer navegador
e visualizar o que foi desenhado. Sua sintaxe é baseada em XML. 
**/

/** CREATE_SVG recebe uma string com o caminho completo do arquivo SVG e uma lista de formas e retorna um arquivo SVG */
FILE* createSvg(char *fullPathSvg);

/** END_SVG finaliza o arquivo SVG */
void endSvg(FILE *svg);

/** RECT_SVG recebe um arquivo SVG e um barco contendo um retângulo e desenha o retângulo no arquivo SVG */
void rectSvg(FILE *svg, Barco r);

/** LINE_SVG recebe um arquivo SVG e um barco contendo uma linha e desenha a linha no arquivo SVG */
void lineSvg(FILE *svg, Barco l);

/** CIRCLE_SVG recebe um arquivo SVG e um barco contendo um círculo e desenha o círculo no arquivo SVG */
void circleSvg(FILE *svg, Barco c);

/** TEXT_SVG recebe um arquivo SVG e um barco contendo um texto e desenha o texto no arquivo SVG */
void textSvg(FILE *svg, Barco t);

/** STRING_SVG recebe um arquivo SVG e uma string e desenha a string no arquivo SVG */
void stringSvg(FILE *svg, char *string, float x, float y, char *corp, char *corb, char *ancora);

/** BARCOS_SVG recebe um arquivo SVG e uma lista de barcos e desenha os barcos no arquivo SVG */
void barcosSvg(FILE *svg, Lista barcos);

/** WRITE_SVG recebe uma string com o caminho de saída, uma string com o nome do arquivo SVG e uma lista de formas e cria um arquivo SVG */
FILE *writeSvg(char *pathOut, char *name);

#endif
