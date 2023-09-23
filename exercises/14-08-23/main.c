#include "functions.h"

int main()
{
    spersona_t **dataptr = malloc(sizeof(spersona_t *));

    int cant = 0;

    dataptr = ingreso(dataptr, &cant);

    imprimir(dataptr);

    int i = 0;

    while (dataptr[i] != NULL)
    {
        free(dataptr[i]);
        i++;
    }

    free(dataptr);

    return 0;
}