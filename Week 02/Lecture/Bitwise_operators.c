#include <stdio.h>

int main()
{
    int a = 12;
    int b = 9;
    int result = a & b;
    printf("a & b = %d\n", result);

    int x = 5;
    int y = 3;
    result = x | y;
    printf("a | b = %d\n", result);

    int m = 10;
    int n = 6;
    result = m^n;
    printf("m ^ n = %d\n", result);
}