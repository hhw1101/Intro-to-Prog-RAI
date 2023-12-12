/*
Write a C program that takes two integers as input from the user,
and calculates the average of two integers.
Ensure that the result is a floating-point number.
Print the result with a floating point precision of 2 (display only 2 decimal places).
*/

#include <stdio.h>

int main()
{
    int a, b;
    float  avg;

    puts("Enter a number:");
    scanf("%d", &a);

    puts("Enter a number:");
    scanf("%d", &b);

    avg = 0.5 * (a+b);

    printf("The average of %d and %d is %.2f", a,b,avg);
    // %2f is 2 decimal place rounding
    //%.2f is print only 2 decimal places - no rounding

}