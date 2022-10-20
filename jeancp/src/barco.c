#include "barco.h"

struct Ship
{
    char tipo;
    Item info;
    float protecao;
    int hp;
    bool isCapitao;
};

bool isCapitao(Barco b)
{
    struct Ship *ponteiro = b;
    return ponteiro->isCapitao;
}

void setCapitao(Barco b, bool capitao)
{
    struct Ship *ponteiro = b;
    ponteiro->isCapitao = capitao;
}
void setInfo(Barco b, void *info)
{
    struct Ship *ponteiro = b;
    ponteiro->info = info;
}

void setTipo(Barco b, char tipo)
{
    struct Ship *ponteiro = b;
    ponteiro->tipo = tipo;
}

void setProtecao(Barco sh, float protecao)
{
    struct Ship *ponteiro = sh;
    ponteiro->protecao = protecao;
}

void setHP(Barco sh, int hp)
{
    struct Ship *ponteiro = sh;
    ponteiro->hp = hp;
}

float barco_get_x(Barco b)
{
    switch (getTipo(b))
    {
    case 'r':
        return retangulo_get_x(getInfo(b));
        break;
    case 'c':
        return circulo_get_x(getInfo(b));
        break;
    case 't':
        return texto_get_x(getInfo(b));
        break;
    case 'l':
        if (linha_get_x1(getInfo(b)) > linha_get_x2(getInfo(b)))
        {
            return linha_get_x2(getInfo(b));
        }
        else
        {
            return linha_get_x1(getInfo(b));
        }
    }
}

float barco_get_y(Barco b)
{
    switch (getTipo(b))
    {
    case 'r':
        return retangulo_get_y(getInfo(b));
        break;
    case 'c':
        return circulo_get_y(getInfo(b));
        break;
    case 't':
        return texto_get_y(getInfo(b));
        break;
    case 'l':
        if (linha_get_y1(getInfo(b)) < linha_get_y2(getInfo(b)))
            return linha_get_y1(getInfo(b));
        else
            return linha_get_y2(getInfo(b));
        break;
    }
}

Barco create_barco(char tipo, void *info)
{
    struct Ship *sh = malloc(sizeof(struct Ship));
    setTipo(sh, tipo);
    setInfo(sh, info);
    switch (sh->tipo)
    {
    case 'r':
        setProtecao(sh, 60);
        setHP(sh, 3);
        break;
    case 'c':
        setProtecao(sh, 60);
        setHP(sh, 2);
        break;
    case 't':
        setProtecao(sh, 50);
        setHP(sh, 1);
        break;
    case 'l':
        setProtecao(sh, 50);
        setHP(sh, 1);
        break;
    }
    return sh;
}

char getTipo(Barco b)
{
    struct Ship *ponteiro = b;
    return ponteiro->tipo;
}

void *getInfo(Barco b)
{
    struct Ship *ponteiro = (struct Ship *)b;
    return ponteiro->info;
}

float getProtecao(Barco b)
{
    struct Ship *ponteiro = b;
    return ponteiro->protecao;
}

int getHP(Barco b)
{
    struct Ship *ponteiro = b;
    return ponteiro->hp;
}

float getPontuacaoDesativ(Barco b)
{
    struct Ship *ponteiro = b;
    float pt;
    char tipo = getTipo(ponteiro);
    switch (tipo)
    {
    case 'r':
        pt = 90;
        break;
    case 'c':
        pt = 75;
        break;
    case 't':
        pt = 30;
        break;
    case 'l':
        pt = 50;
        break;
    }
    return pt;
}

float getPontuacaoDestruicao(Barco b)
{
    struct Ship *ponteiro = b;
    float pt, a;
    char tipo = getTipo(ponteiro);
    switch (tipo)
    {
    case 'r':
        a = retangulo_get_area(b);
        pt = 90 / (a / 5);
        break;
    case 'c':
        a = circulo_get_area(b);
        pt = 75 / (a / 5);
        break;
    case 't':
        pt = 500;
        break;
    case 'l':
        pt = 50;
        break;
    }
    return pt;
}

void freeBarco(Barco b)
{
    switch (getTipo(b))
    {
    case 'r':
        retangulo_free(getInfo(b));
        break;
    case 'c':
        circulo_free(getInfo(b));
        break;
    case 'l':
        linha_free(getInfo(b));
        break;
    case 't':
        texto_free(getInfo(b));
        break;
    default:
        break;
    }
    free(b);
}