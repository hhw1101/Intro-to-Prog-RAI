/*
Write a program to take two variables (one of character type and one of integer type) as input,
add them and print the sum both in integer and ASCII value.
*/

#include <stdio.h>

int main()
{

    int value, sum;
    char c, c_sum;

    puts("Enter a letter:");
    c = getchar();
    // When enter a letter is later does not take a letter

    puts("Enter an integer:");
    scanf("%d", &value);

    sum = c + value;
    c_sum = sum;

    printf("You integer sum is %d, and this value in ascii is %c.", sum, c_sum);
}