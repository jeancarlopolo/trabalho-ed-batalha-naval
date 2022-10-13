#include "freebarco.h"

void freeBarco(Barco b)
{
    switch (getTipo(b))
    {
    case 'c':
        circulo_free(b);
        break;
    case 'r':
        retangulo_free(b);
        break;
    case 't':
        texto_free(b);
        break;
    case 'l':
        linha_free(b);
        break;
    default:
        break;
    }
    free(b);
}