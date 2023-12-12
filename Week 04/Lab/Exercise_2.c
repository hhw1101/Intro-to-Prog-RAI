#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

void areaOfCircle(int r);
void areaOfSquare(int l);
void areaOfRectangle(int l, int w);

int main()
{
    // char shape[15];
    int shape, l, r, w;

    puts("Enter the shape you wish to find the area:\n1 is for Circles\n2 is for Squares\n3 is for a Rectangle");
    scanf("%d", &shape);
    switch (shape)
    {
    case (1):
        printf("Enter the Radius: ");
        scanf("%d", &r);
        areaOfCircle(r);
        break;

    case (2):
        printf("Enter the Length of one side: ");
        scanf("%d", &l);
        areaOfSquare(l);
        break;

    case (3):
        printf("Enter the Length: ");
        scanf("%d", &l);
        printf("Enter the Width: ");
        scanf("%d", &w);
        areaOfRectangle(l, w);
        break;

    default:
        printf("Error invalid Shape");
        break;
    }
    return 0;
}

void areaOfCircle(int r)
{
    printf("The area of a circle with the radius %d is %.3fm^2.", r, (r * r * M_PI));
}
void areaOfSquare(int l)
{
    printf("The area of a square with the side length %d is %dm^2.", l, l * l);
}
void areaOfRectangle(int l, int w)
{
    printf("The area of a rectangle with length %d and width %d is %dm^2.", l, w, l * w);
}