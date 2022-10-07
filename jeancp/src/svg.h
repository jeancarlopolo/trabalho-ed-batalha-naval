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

FILE* createSvg(char *fullPathSvg, Lista l);

//CREATE_SVG recebe uma string com o caminho completo do arquivo SVG e uma lista de formas e retorna um arquivo SVG

void endSvg(FILE *svg);

//END_SVG finaliza o arquivo SVG

void rectSvg(FILE *svg, Retangulo r);

//RECT_SVG recebe um arquivo SVG e um retângulo e desenha o retângulo no arquivo SVG

void lineSvg(FILE *svg, Linha l);

//LINE_SVG recebe um arquivo SVG e uma linha e desenha a linha no arquivo SVG

void circleSvg(FILE *svg, Circulo c);

//CIRCLE_SVG recebe um arquivo SVG e um círculo e desenha o círculo no arquivo SVG

void textSvg(FILE *svg, Texto t);

//TEXT_SVG recebe um arquivo SVG e um texto e desenha o texto no arquivo SVG

void writeSvg(char *pathOut, char *name, Lista l);

//WRITE_SVG recebe uma string com o caminho de saída, uma string com o nome do arquivo SVG e uma lista de formas e cria um arquivo SVG

#endif
