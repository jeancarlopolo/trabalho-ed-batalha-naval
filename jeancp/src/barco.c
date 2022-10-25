#include "barco.h"

struct Boat
{
    char tipo;
    Item info;
    double protecao;
    int hp;
    int capitaoid;
};

int barco_get_capitaoid(Barco b)
{
    struct Boat *pointer = b;
    return pointer->capitaoid;
}

void barco_set_capitaoid(Barco b, int capitaoid)
{
    struct Boat *pointer = b;
    pointer->capitaoid = capitaoid;
}
void barco_set_info(Barco b, void *info)
{
    struct Boat *pointer = b;
    pointer->info = info;
}

void barco_set_tipo(Barco b, char tipo)
{
    struct Boat *pointer = b;
    pointer->tipo = tipo;
}

void barco_set_protecao(Barco sh, double protecao)
{
    struct Boat *pointer = sh;
    pointer->protecao = protecao;
}

void barco_set_hp(Barco sh, int hp)
{
    struct Boat *pointer = sh;
    pointer->hp = hp;
}

double barco_get_x(Barco b)
{
    switch (barco_get_tipo(b))
    {
    case 'r':
        return retangulo_get_x(barco_get_info(b));
        break;
    case 'c':
        return circulo_get_x(barco_get_info(b));
        break;
    case 't':
        return texto_get_x(barco_get_info(b));
        break;
    case 'l':
        if (linha_get_x1(barco_get_info(b)) > linha_get_x2(barco_get_info(b)))
        {
            return linha_get_x2(barco_get_info(b));
        }
        else
        {
            return linha_get_x1(barco_get_info(b));
        }
        break;
    default:
        return 0;
        break;
    }
}

double barco_get_y(Barco b)
{
    switch (barco_get_tipo(b))
    {
    case 'r':
        return retangulo_get_y(barco_get_info(b));
        break;
    case 'c':
        return circulo_get_y(barco_get_info(b));
        break;
    case 't':
        return texto_get_y(barco_get_info(b));
        break;
    case 'l':
        if (linha_get_y1(barco_get_info(b)) < linha_get_y2(barco_get_info(b)))
            return linha_get_y1(barco_get_info(b));
        else
            return linha_get_y2(barco_get_info(b));
        break;
    default:
        return 0;
        break;
    }
}

Barco create_barco(char tipo, void *info)
{
    struct Boat *sh = malloc(sizeof(struct Boat));
    barco_set_tipo(sh, tipo);
    barco_set_info(sh, info);
    barco_set_capitaoid(sh, -1);
    switch (sh->tipo)
    {
    case 'r':
        barco_set_protecao(sh, 60);
        barco_set_hp(sh, 3);
        break;
    case 'c':
        barco_set_protecao(sh, 60);
        barco_set_hp(sh, 2);
        break;
    case 't':
        barco_set_protecao(sh, 50);
        barco_set_hp(sh, 1);
        break;
    case 'l':
        barco_set_protecao(sh, 50);
        barco_set_hp(sh, 1);
        break;
    }
    return sh;
}

char barco_get_tipo(Barco b)
{
    struct Boat *pointer = b;
    return pointer->tipo;
}

void *barco_get_info(Barco b)
{
    struct Boat *pointer = (struct Boat *)b;
    return pointer->info;
}

double barco_get_protecao(Barco b)
{
    struct Boat *pointer = b;
    return pointer->protecao;
}

int barco_get_hp(Barco b)
{
    struct Boat *pointer = b;
    return pointer->hp;
}

double barco_get_point_desat(Barco b)
{
    struct Boat *pointer = b;
    double pt;
    char tipo = barco_get_tipo(pointer);
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

double barco_get_point_destr(Barco b)
{
    struct Boat *pointer = b;
    double pt, a;
    char tipo = barco_get_tipo(pointer);
    switch (tipo)
    {
    case 'r':
        a = retangulo_get_area(barco_get_info(pointer));
        pt = 90 / (a / 5);
        break;
    case 'c':
        a = circulo_get_area(barco_get_info(pointer));
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

void barco_kill(Barco b)
{
    switch (barco_get_tipo(b))
    {
    case 'r':
        retangulo_free(barco_get_info(b));
        break;
    case 'c':
        circulo_free(barco_get_info(b));
        break;
    case 'l':
        linha_free(barco_get_info(b));
        break;
    case 't':
        texto_free(barco_get_info(b));
        break;
    default:
        break;
    }
    free(b);
}

int barco_get_id(Barco b)
{
    switch (barco_get_tipo(b))
    {
    case 'r':
        return retangulo_get_i(barco_get_info(b));
        break;
    case 'c':
        return circulo_get_i(barco_get_info(b));
        break;
    case 't':
        return texto_get_i(barco_get_info(b));
        break;
    case 'l':
        return linha_get_i(barco_get_info(b));
        break;
    default:
        return 0;
        break;
    }
}