#include <stdio.h>

int recursiveFibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return recursiveFibonacci(n - 2) + recursiveFibonacci(n - 1);
    }
}

int standardFiconacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    int beforeN1 = 1;
    int beforeN2 = 0;
    int currentN;
    for (int i = 2; i <= n; i++)
    {
        currentN = beforeN1 + beforeN2;
        beforeN2 = beforeN1;
        beforeN1 = currentN;
    }
    return currentN;
}

int main()
{
    int terms;
    printf("Enter how many numbers of the Fibonacci sequence you want: ");
    scanf("%d", &terms);
    printf("Fibonacci Series: ");
    for (int i = 0; i < terms; i++)
    {
        printf("%d ", recursiveFibonacci(i));
    }
    printf("\nFibonacci Series: ");
    for (int i = 0; i < terms; i++)
    {
        printf("%d ", standardFiconacci(i));
    }

    return 0;
}