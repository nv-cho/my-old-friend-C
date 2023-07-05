#include <stdio.h>
#include "functions.h"

int obtener_mayores(int *vector, int length, int max_number)
{
    if (vector == NULL)
    {
        return ERROR;
    }

    int bigger_than_max_number_counter = 0, iterator;

    for (iterator = 0; iterator < length; iterator++)
    {
        if (vector[iterator] > max_number)
        {
            bigger_than_max_number_counter++;
        }
    }

    return bigger_than_max_number_counter;
}

void controlar_medidas()
{
    int counter = 0;
    int entered_number;
    int size = INITIAL_SIZE;
    int *number_list = malloc(INITIAL_SIZE * sizeof(int));

    if (number_list == NULL)
    {
        return ERROR;
    }

    printf("Enter numbers as much as you want, to finish the loading enter: 2222 \n");
    do
    {
        if (size == counter)
        {
            size *= 2;
            int *temp_pointer = realloc(number_list, size * sizeof(int));

            if (temp_pointer == NULL)
            {
                return ERROR;
            }

            number_list = temp_pointer;
        }

        printf("Enter your number selection: ");
        scanf("%d", &entered_number);
        printf('\n');

        number_list[counter++] = entered_number;
    } while (entered_number != END_OF_LOOP_CODE);

    printf("Now, tell me which is your acceptance number limit: ");
    scanf("%d", &entered_number);
    printf("\n");

    printf("Doing some black magic... \n");

    int answer = obtener_mayores(number_list, counter - 1, entered_number);

    printf("%d number of numbers are over the limit", answer);

    free(number_list);
}