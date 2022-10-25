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

/** recebe uma string com o caminho completo do arquivo SVG e uma lista de formas e retorna um arquivo SVG */
FILE *svg_create(char *fullPathSvg);

/** finaliza o arquivo SVG */
void svg_end(FILE *svg);

/** recebe um arquivo SVG e um barco contendo um retângulo e desenha o retângulo no arquivo SVG */
void svg_rect(FILE *svg, Barco r);

/** recebe um arquivo SVG e um barco contendo uma linha e desenha a linha no arquivo SVG */
void svg_line(FILE *svg, Barco l);

/** recebe um arquivo SVG e um barco contendo um círculo e desenha o círculo no arquivo SVG */
void svg_circle(FILE *svg, Barco c);

/** recebe um arquivo SVG e um barco contendo um texto e desenha o texto no arquivo SVG */
void svg_text(FILE *svg, Barco t);

/** recebe um arquivo SVG e uma string e desenha a string no arquivo SVG */
void svg_string(FILE *svg, char *string, double x, double y, char *corp, char *corb, char *ancora);

/** recebe um arquivo SVG e uma lista de barcos e desenha os barcos no arquivo SVG */
void svg_barcos(FILE *svg, Lista barcos);

/** recebe uma string com o caminho de saída, uma string com o nome do arquivo SVG e uma lista de formas e cria um arquivo SVG */
FILE *svg_write(char *pathOut, char *name);

#endif
