#include <stdio.h>
#include <math.h>

int main(){
    float rad = 0;

    printf("Enter the radius: ");
    scanf("%f", &rad);

    float area = 0;
    area = rad*rad*M_PI;

    printf("The area of a circle radius %3f is %4f.", rad, area);
    return 0;
}