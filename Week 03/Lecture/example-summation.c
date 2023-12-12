#include <stdio.h>
// This is Daniel"s solution
unsigned int find_summation(const unsigned int number);

int main(void)
{

    const unsigned int Number;
    printf("Enter a number: ");
    scanf(" %d", &Number);
    printf("The summation of all natural numebr up to %d is %d\n", Number, find_summation(Number));
    return 0;
}

unsigned int find_summation(const unsigned int number)
{
    // task is to find summation of all natural numbers up to n
    unsigned static int CallCount = 0;
    CallCount++;
    printf("Call count: %d\n", CallCount);

    if (number == 0)
    {
        return 0;
    }
    else
    {
        return number + find_summation(number - 1);
    }
}