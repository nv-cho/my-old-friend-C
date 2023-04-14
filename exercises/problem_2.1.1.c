#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
    float radius;
    float area;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    area = M_PI * radius * radius;

    printf("The area of a circle is: %f", area);

    return 0;
}