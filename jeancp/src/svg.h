#ifndef _SVG_H
#define _SVG_H
#include <stdio.h>
#include <stdlib.h>

#include "retangulo.h"
#include "linha.h"
#include "circulo.h"
#include "texto.h"
#include "path.h"

FILE* createSvg(char *fullPathSvg, Lista l);

void endSvg(FILE *svg);

void rectSvg(FILE *svg, Retangulo r);

void lineSvg(FILE *svg, Linha l);

void circleSvg(FILE *svg, Circulo c);

void textSvg(FILE *svg, Texto t);

void writeSvg(char *pathOut, char *name, Lista l);

#endif
