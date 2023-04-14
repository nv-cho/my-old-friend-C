#include <stdio.h>

int main()
{

    int day_of_the_day;

    printf("Enter the number of your favorite day of the week (ex Monday = 1): ");
    scanf("%d", &day_of_the_day);

    if (day_of_the_day > 7 || day_of_the_day < 1)
    {
        fprintf(stderr, "Error: Unless you're living in another planet, your number is out of range...");

        return 1;
    }

    switch (day_of_the_day)
    {
    case 1:
        printf("Monday!");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    case 7:
        printf("Sunday");
        break;
    }

    return 0;
}