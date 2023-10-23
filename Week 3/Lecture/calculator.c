#include <stdio.h>
#include <math.h>

float power(float power, float base)
{
    float result = 1;

    for (int i = 0; i < power; i++)
    {
        result = result * base;
    }
    return result;
}

float add(float a, float b)
{
    return a + b;
}

float minus(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    return a / b;
}

int modulus(int a, int b)
{
    return a % b;
}

int main()
{
    /* Code to test math.h library
    // int n = 4;

    // printf("%f", pow(2, n));
    // return 0;

    */
    printf("4 to the power of 5 is %.0f\n", power(5.0, 4.0));
    printf("234 + 5324 = %.0f\n", add(234,5324));
    printf("3454 - 3432 = %.0f\n", minus(3454,3432));
    printf("234 x 42 = %.0f\n", multiply(234,42));
    printf("493 divided by 23 is %.2f\n", divide(493.0,23.0));

}
