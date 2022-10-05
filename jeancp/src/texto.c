#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

typedef void *Text;
typedef char *string;
typedef struct texto
{
    int id;
    float x;
    float y;
    char *corb;
    char *corp;
    char *value;
    char anchor;
}Stext;

Text createText(int id, float x, float y, char *corb, char *corp, char *value, char anchor)
{
    Stext *text = (Stext*)malloc(sizeof(Stext));
    text->id = id;
    text->x = x;
    text->y = y;
    text->corb = corb;
    text->corp = corp;
    text->value = value;
    text->anchor = anchor;
    return text;
}

void setTextX(Text text, float x)
{
    Stext *t = (Stext*)text;
    t->x = x;
}

void setTextY(Text text, float y)
{
    Stext *t = (Stext*)text;
    t->y = y;
}

void setTextCorb(Text text, char *corb)
{
    Stext *t = (Stext*)text;
    t->corb = corb;
}

void setTextCorp(Text text, char *corp)
{
    Stext *t = (Stext*)text;
    t->corp = corp;
}

void setTextValue(Text text, char *value)
{
    Stext *t = (Stext*)text;
    t->value = value;
}

void setTextAnchor(Text text, char anchor)
{
    Stext *t = (Stext*)text;
    t->anchor = anchor;
}

int getTextId(Text text)
{
    Stext *t = (Stext*)text;
    return t->id;
}

float getTextX(Text text)
{
    Stext *t = (Stext*)text;
    return t->x;
}

float getTextY(Text text)
{
    Stext *t = (Stext*)text;
    return t->y;
}

char *getTextCorb(Text text)
{
    Stext *t = (Stext*)text;
    return t->corb;
}

char *getTextCorp(Text text)
{
    Stext *t = (Stext*)text;
    return t->corp;
}

char *getTextValue(Text text)
{
    Stext *t = (Stext*)text;
    return t->value;
}

char getTextAnchor(Text text)
{
    Stext *t = (Stext*)text;
    return t->anchor;
}

void freeText(Text text)
{
    Stext *t = (Stext*)text;
    free(t->corb);
    free(t->corp);
    free(t->value);
    free(t);
}

// Language: c