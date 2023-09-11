#include "functions.h"

int main()
{
    spersona_t **dataptr = malloc(sizeof(spersona_t *));

    int cant = 0;

    dataptr = ingreso(dataptr, &cant);

    imprimir(dataptr);

    return 0;
}