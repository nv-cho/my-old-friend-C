#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void min_max(int *vector, int size, int limit)
{
    int iterator, over_the_limit_counter = 0, under_the_limit_counter = 0;

    for (iterator = 0; iterator < size; iterator++)
    {
        if (vector[iterator] > limit)
        {
            over_the_limit_counter++;
        }
        else
        {
            under_the_limit_counter++;
        }
    }

    printf("%d number of elements are over the limit. \n", over_the_limit_counter);
    printf("%d number of elements are under the limit. \n", under_the_limit_counter);
}

void broken_printer(char *string)
{
    if (string == NULL)
    {
        return ERROR;
    }

    int parameter_string_length = strlen(string);

    if (parameter_string_length == 0)
    {
        return ERROR;
    }

    int iterator;
    char user_strings[USER_STRINGS_LIMIT][STRING_MAX_SIZE];

    for (iterator = 0; iterator < USER_STRINGS_LIMIT; iterator++)
    {
        printf("Enter the string number %d: ", iterator + 1);
        fgets(user_strings[iterator], STRING_MAX_SIZE, stdin);

        user_strings[iterator][strcspn(user_strings[iterator], '\n')] = '\0';

        int inner_iterator;
        char *string_match_position = strstr(user_strings[iterator], string);

        while (string_match_position != NULL)
        {
            for (inner_iterator = 0; inner_iterator < parameter_string_length; inner_iterator++)
            {
                *(string_match_position + inner_iterator) = 'X';
            }

            string_match_position = strstr(string_match_position + parameter_string_length, string);
        }

        printf("String entered by the user is: %s \n", user_strings[iterator]);
    }
}

/** @note DON'T FORGET TO FREE THE MEMORY RECEIVED */
char *array_compressor(char *string)
{
    if (string == NULL || sizeof(string) > STRING_MAX_SIZE)
    {
        return ERROR;
    }

    char *string_copy = malloc(strlen(string) + 1);

    if (string_copy == NULL)
    {
        return ERROR;
    }

    strcpy(string_copy, string);

    return string_copy;
}

unsigned int my_streq(char *string_1, char *string_2)
{
    if (string_1 == NULL || string_2 == NULL)
    {
        return ERROR;
    }

    if (strcmp(string_1, string_2) == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void average_number(int number_of_numbers)
{
    if (number_of_numbers == 0)
    {
        return ERROR;
    }

    int *entered_numbers = (int *)malloc(number_of_numbers * sizeof(int));

    if (entered_numbers == NULL)
    {
        return ERROR;
    }

    int entered_number, sum = 0, iterator;

    for (iterator = 0; iterator < number_of_numbers; iterator++)
    {
        printf("Enter the number %d: ", iterator + 1);
        scanf("%d", &entered_number);
        printf("\n");

        sum += entered_number;
        entered_numbers[iterator] = entered_number;
    }

    printf("The average is %d \n", sum / number_of_numbers);

    free(entered_numbers);
}