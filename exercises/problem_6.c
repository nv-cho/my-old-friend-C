#include <stdio.h>

int main()
{

    float side_1, side_2, side_3;

    printf("Enter the size of the sides of a triangle (Use spaces to separate them): ");
    scanf("%f %f %f", &side_1, &side_2, &side_3);

    if (side_1 < 0 || side_1 == 0 || side_2 < 0 || side_2 == 0 || side_3 < 0 || side_3 == 0)
    {
        fprintf(stderr, "Error: Only positives (zero not included) values accepted");

        return 1;
    }

    if (side_1 == side_2 && side_1 == side_3 && side_2 == side_3)
    {
        printf("Your triangle is Equilateral!");
    }
    else if (side_1 != side_2 && side_1 != side_3 && side_2 != side_3)
    {
        printf("Your triangle is Scalene!");
    }
    else
    {
        printf("Your triangle is Isosceles!");
    }

    return 0;
}