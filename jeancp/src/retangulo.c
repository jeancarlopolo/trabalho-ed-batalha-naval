#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

typedef struct retangulo{
    int id;
    float h;
    float w;
    float x;
    float y;
    string corb;
    string corp;
    int np;
    int hp;
    float area;
    float pi;
    float pd;
} Retangle;

Retangulo create_retangulo(int id, float x, float y, float w, float h, string corb, string corp){
    Retangle *ret = (Retangle*)malloc(sizeof(Retangle));
    ret->id = id;
    ret->x = x;
    ret->y = y;
    ret->w = w;
    ret->h = h;
    ret->corb = corb;
    ret->corp = corp;
    ret->hp = 3;
    ret->np = 60;
    ret->area = w*h;
    ret->pi = 90;
    return ret;
}

void retangulo_set_id(Retangulo ret, int id){
    Retangle r = (Retangle*)ret;
    r->id = id;
}

void retangulo_set_x(Retangulo ret, float x){
    Retangle r = (Retangle*)ret;
    r->x = x;
}

void retangulo_set_y(Retangulo ret, float y){
    Retangle r = (Retangle*)ret;
    r->y = y;
}

void retangulo_set_w(Retangulo ret, float w){
    Retangle r = (Retangle*)ret;
    r->w = w;
}

void retangulo_set_h(Retangulo ret, float h){
    Retangle r = (Retangle*)ret;
    r->h = h;
}

void retangulo_set_corb(Retangulo ret, string corb){
    Retangle r = (Retangle*)ret;
    r->corb = corb;
}

void retangulo_set_corp(Retangulo ret, string corp){
    Retangle r = (Retangle*)ret;
    r->corp = corp;
}

int retangulo_get_i(Retangulo ret){
    Retangle r = (Retangle*)ret;
    return r->id;
}

float retangulo_get_x(Retangulo ret){
    Retangle r = (Retangle*)ret;
    return r->x;
}

float retangulo_get_y(Retangulo ret){
    Retangle r = (Retangle*)ret;
    return r->y;
}

float retangulo_get_w(Retangulo ret){
    Retangle r = (Retangle*)ret;
    return r->w;
}

float retangulo_get_h(Retangulo ret){
    Retangle r = (Retangle*)ret;
    return r->h;
}

string retangulo_get_corb(Retangulo ret){
    Retangle r = (Retangle*)ret;
    return r->corb;
}

string retangulo_get_corp(Retangulo ret){
    Retangle r = (Retangle*)ret;
    return r->corp;
}

float retangulo_get_area(Retangulo ret){
    Retangle r = (Retangle*)ret;
    return r->area;
}

float retangulo_get_pontos_inativo(Retangulo ret){
    Retangle r = (Retangle*)ret;
    return r->pi;
}

float retangulo_get_pontos_destruido(Retangulo ret){
    Retangle r = (Retangle*)ret;
    r->pd = 90/(r->area/5);
    return r->pd;
}

void retangulo_free(Retangulo ret){
    free(ret);
}