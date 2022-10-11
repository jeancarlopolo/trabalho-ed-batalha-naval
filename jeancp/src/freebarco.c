#include "freebarco.h"

void freeBarco(Barco b)
{
    switch (getTipo(b))
    {
    case 'c':
        circulo_free(getInfo(b));
        break;
    case 'r':
        retangulo_free(getInfo(b));
        break;
    case 't':
        texto_free(getInfo(b));
        break;
    case 'l':
        linha_free(getInfo(b));
        break;
    default:
        break;
    }
    free(b);
}