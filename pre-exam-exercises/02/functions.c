#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

int cuantas_veces(char *string, char character, int *counter_placeholder)
{
    if (string == NULL || counter_placeholder == NULL)
    {
        return ERROR;
    }

    int iterator, counter = 0;

    for (iterator = 0; string[iterator] != '\0'; iterator++)
    {
        if (string[iterator] == character)
        {
            counter++;
        }
    }

    *counter_placeholder = counter;

    return counter;
}

void en_reversa(char *string, char *reversed_string_placeholder)
{
    if (string == NULL || reversed_string_placeholder == NULL)
    {
        return ERROR;
    }

    int iterator, string_length = strlen(string), end_of_string = string_length - 1;

    for (iterator = 0; iterator < string_length; iterator++)
    {
        reversed_string_placeholder[iterator] = string[end_of_string];

        end_of_string--;
    }

    reversed_string_placeholder[string_length] = '\0';
}

int es_palindromo(char *string)
{
    int iterator;
    char *reversed_string = malloc((strlen(string) + 1) * sizeof(char));

    if (string == NULL || reversed_string == NULL)
    {
        return ERROR;
    }

    for (iterator = 0; string[iterator] != '\0'; iterator++)
    {
        string[iterator] = tolower((unsigned char)string[iterator]);
    }

    en_reversa(string, reversed_string);

    if (strcmp(string, reversed_string) == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

    free(reversed_string);
}

void contador_de_palindromos(char **array_of_words)
{
    if (array_of_words == NULL)
    {
        return ERROR;
    }

    int iterator = 0, counter = 0;

    while (array_of_words[iterator] != NULL)
    {
        if (es_palindromo(array_of_words[iterator]) == TRUE)
        {
            counter++;
        }

        iterator++;
    }

    float percentage_of_palindromes = ((float)counter / (iterator - 1)) * 100;

    printf("The number of word entered is %d, and the percentage of words that are palindromes is %.2f%% \n", iterator - 1, percentage_of_palindromes);
}