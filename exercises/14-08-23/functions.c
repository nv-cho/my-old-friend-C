#include "functions.h"

spersona_t **ingreso(spersona_t **dataptr, int *cant)
{
    if (dataptr == NULL)
    {
        printf("El argumento 'dataptr' es un puntero nulo");
        return NULL;
    }
    else if (cant == NULL)
    {
        printf("El argumento 'cant' es un puntero nulo");
        return NULL;
    }

    dataptr = malloc(CANT_PERSONAS_INICIAL * sizeof(spersona_t *));

    if (dataptr == NULL)
    {
        printf("Error al asignar memoria. pos 0\n");
        return NULL;
    }

    int user_exit;
    int iterator = 0, person_counter = 0;

    do
    {
        printf("----- Ingreso de personas ----- \n*Seleccione 1 para continuar \n*Seleccione 0 para terminar el ingreso \n-----\n");
        scanf("%d", &user_exit);
        getchar();

        if (user_exit != 1)
        {
            break;
        }

        if (person_counter == CANT_PERSONAS_INICIAL)
        {
            spersona_t **temp = realloc(dataptr, (CANT_PERSONAS_INICIAL + 1) * sizeof(spersona_t *));

            if (temp == NULL)
            {
                printf("Error al asignar memoria. pos 1\n");
                return NULL;
            }
            else
            {
                dataptr = temp;
            }
        }

        dataptr[iterator] = malloc(sizeof(spersona_t));

        if (dataptr[iterator] == NULL)
        {
            printf("Error al asignar memoria. pos 3\n");
            return NULL;
        }

        printf("----- Comienzo de ingreso de persona %d -----\n", iterator + 1);

        printf("Ingrese el nombre: ");
        fgets(dataptr[iterator]->fullname.nombre, sizeof(dataptr[iterator]->fullname.nombre), stdin);

        printf("Ingrese el apellido: ");
        fgets(dataptr[iterator]->fullname.apellido, sizeof(dataptr[iterator]->fullname.apellido), stdin);

        printf("Ingrese la edad: ");
        scanf("%d", &dataptr[iterator]->edad);
        getchar();

        printf("Ingrese la altura: ");
        scanf("%f", &dataptr[iterator]->altura);
        getchar();

        printf("Ingrese el sexo: ");
        scanf("%c", &dataptr[iterator]->sexo);
        getchar();

        printf("----- Fin del ingreso de persona %d -----\n\n", iterator + 1);

        person_counter++;
        iterator++;

    } while (user_exit != 0);

    if (user_exit == 0)
    {
        dataptr[iterator] = NULL;
    }

    printf("----- Ingreso finalizado ----- \n\n");

    return dataptr;
}

void imprimir(spersona_t **dataptr)
{
    if (dataptr == NULL)
    {
        printf("El argumento 'dataptr' es un puntero nulo");
    }

    int iterator = 0;

    while (dataptr[iterator] != NULL)
    {
        spersona_t *person = dataptr[iterator];

        printf("----- Persona %d -----\n", iterator + 1);

        printf("Nombre: %s", person->fullname.nombre);
        printf("Apellido: %s", person->fullname.apellido);
        printf("Edad: %d\n", person->edad);
        printf("Altura: %.2f\n", person->altura);
        printf("Sexo: %c\n", person->sexo);

        printf("-----\n");

        printf("\n");

        iterator++;
    }
}