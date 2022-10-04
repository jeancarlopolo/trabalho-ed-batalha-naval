#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

typedef struct texto
{
    int id;
    double x;
    double y;
    char *corb;
    char *corp;
    char *value;
    char anchor;
}Stext;

Stext* createText(){
    Stext *text = calloc(1, sizeof(Stext));
    return text;
}

item buildText(char *command, Text text){
    Stext *texto = (Stext*) text;
    char *ptr = strtok(command, " ");
    char *ept;
    texto->id = atoi(ptr);
    ptr = strtok(NULL, " ");
    texto->x = strtod(ptr, &ept);
    ptr = strtok(NULL, " ");
    texto->y = strtod(ptr, &ept);
    ptr = strtok(NULL, " ");
    strcpy(texto->corb, ptr);
    ptr = strtok(NULL, " ");
    strcpy(texto->corp, ptr);
    ptr = strtok(NULL, " ");
    texto->anchor = ptr[0];
    ptr = strtok(NULL, " ");
    strcpy(texto->value, ptr);
    return texto;
}

int getIdText(Stext *texto){
    return texto->id;
}

double getXText(Stext *texto){
    return texto->x;
}

double getYText(Stext *texto){
    return texto->y;
}

char* getCorBText(Stext *texto){
    return texto->corb;
}

char* getCorPText(Stext *texto){
    return texto->corp;
}

char* getCorValueText(Stext *texto){
    return texto->value;
}

char getAnchorText(Stext texto){
    return texto.anchor;
}