#include <stdio.h>

int main()
{
    int num;
    puts("Enter a number:");
    scanf("%d", &num);

    // for (int i = 0; i < num; i++)
    // {
    //     // for loop that prints all numbers up to and including number entered by user
    //     printf("%d\n", i + 1);
    // }
    int counter = 0;
    int sum = 0;

    while (counter <= num)
    {
        sum += (counter % 2 == 0) ? counter : 0;
        counter++;
    }
    printf("The sum of all the even numbers up till %d is %d.\n", num, sum);
    counter = 0;
    sum = 0;
    do
    {
        sum += counter;
        counter += 2;
    } while (counter <= num);

    printf("The sum of all the even numbers up till %d is %d.\n", num, sum);
    return 0;
}