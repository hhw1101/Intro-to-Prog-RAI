#include <stdio.h>

int findSummation(int num);

int main()
{
    int number;
    puts("Enter a number: ");
    scanf("%d", &number);

    int loopSummation = 0;
    // In C the curly bracket is not necessary.
    for (int i = 0; i <= number; i++)
        loopSummation += i;

    printf("The summation of all the natrual numbers up to %d is %d.", number, loopSummation);
    printf("\nThe summation of all the natrual numbers up to %d is %d.", number, findSummation(number));

}

int findSummation(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else
    {
        return num + findSummation(num - 1);
    }
}