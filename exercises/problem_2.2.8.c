#include <stdio.h>
#include <ctype.h>

int main()
{
    char day;

    printf("Enter your favorite day of the week (L or l = Monday, M or m = Tuesday, X or x = Wednesday, J or j = Thursday, V or v = Friday, S or s = Saturday, D or d = Sunday): ");
    scanf("%c", &day);

    day = toupper(day);

    if (day != 'L' && day != 'M' && day != 'X' && day != 'J' && day != 'V' && day != 'S' && day != 'D')
    {
        fprintf(stderr, "Error: Unless you're living in another planet, your day is not in the week...");

        return 1;
    }

    switch (day)
    {
    case 'L':
        printf("Monday!");
        break;
    case 'M':
        printf("Tuesday");
        break;
    case 'X':
        printf("Wednesday");
        break;
    case 'J':
        printf("Thursday");
        break;
    case 'V':
        printf("Friday");
        break;
    case 'S':
        printf("Saturday");
        break;
    case 'D':
        printf("Sunday");
        break;
    }

    return 0;
}