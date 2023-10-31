#include <stdio.h>

float power(int base, int power)
{
    float result = 1;
    if (power < 0)
    {
        for (int i = 0; i < -power; i++)
        {
            result = result / base;
        }
    }
    else
    {
        for (int i = 0; i < power; i++)
        {
            result = result * base;
        }
    }
    return result;
}
int fibonarcci(int terms)
{
    if(terms == 0){
        return 0;
    }else if(terms ==1){
        return 1;
    }
    return fibonarcci(terms-1)+ fibonarcci(terms-2);
}

int main()
{
    int b, e;

    printf("Enter the base: ");
    scanf("%d", &b);
    printf("Enter the exponent: ");
    scanf("%d", &e);

    printf("The power of %d to %d is %.3f", b, e, power(b, e));

    // task b
    int n = -1;
    do
    {
        printf("\nEnter a positive number: ");
        scanf("%d", &n);

    } while (n < 0);
    printf("The %d term of the fibonacci sequence is %d", n, fibonarcci(n));
}