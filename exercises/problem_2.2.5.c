#include <stdio.h>
#include <math.h>

int main()
{

    float side_1, side_2, side_3;

    printf("Enter the size of the sides of a triangle (Use spaces to separate them): ");
    scanf("%f %f %f", &side_1, &side_2, &side_3);

    if (side_1 < 0 || side_1 == 0 || side_2 < 0 || side_2 == 0 || side_3 < 0 || side_3 == 0)
    {
        fprintf(stderr, "Error: Only positives (zero not included) values accepted.");

        return 1;
    }

    /** @note - There is no real need to use the "fabs" fn since we are already checking the values before */
    if ((fabs(side_1) + fabs(side_2)) > fabs(side_3) && (fabs(side_1) + fabs(side_3)) > fabs(side_2) && (fabs(side_2) + fabs(side_3)) > fabs(side_1))
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

        int hypotenuse = (int)fmax(fmax(side_1, side_2), side_3);
        int a, b;

        if (hypotenuse == (int)side_1)
        {
            a = (int)side_2;
            b = (int)side_3;
        }
        else if (hypotenuse == (int)side_2)
        {
            a = (int)side_1;
            b = (int)side_3;
        }
        else
        {
            a = (int)side_2;
            b = (int)side_3;
        }

        if (hypotenuse * hypotenuse == a * a + b * b)
        {
            printf("And your triangle is a right triangle too!");
        }
        else
        {
            printf("But your triangle is not a right one :(");
        }
    }
    else
    {
        fprintf(stderr, "Error: The sizes of the sides you have entered do not form a valid triangle.");
    }

    return 0;
}