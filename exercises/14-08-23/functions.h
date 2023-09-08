#define NOMBRE_CANT 32
#define APELLIDO_CANT 32
#define CANT_PERSONAS_INICIAL 5
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[NOMBRE_CANT];
    char apellido[APELLIDO_CANT];
} sfullname_t;

typedef struct
{
    sfullname_t fullname;
    int edad;
    float altura;
    char sexo;

} spersona_t;

spersona_t **ingreso(spersona_t **dataptr, int *cant);