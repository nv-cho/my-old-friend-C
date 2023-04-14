#include <stdio.h>

int main()
{

    float side_1, side_2, side_3;

    printf("Enter the size of the sides of a triangle (Use spaces to separate them): ");
    scanf("%f %f %f", &side_1, &side_2, &side_3);

    if ((side_1 + side_2) > side_3 || (side_1 + side_3) > side_2 || (side_2 + side_3) > side_1)
    {
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
    }
    else
    {
        printf("Error: The sides entered do not form a valid triangle");

        return 1;
    }

    return 0;
}