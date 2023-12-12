#include <stdio.h>

int main()
{
    int length, min, newValue, counter = 0;
    printf("Enter the total number of integers: ");
    scanf("%d", &length);

    while (counter < length)
    {
        printf("Enter the next integer: ");
        scanf("%d", &newValue);
        if (counter == 0)
        {
            min = newValue;
        }
        if (min > newValue)
        {
            min = newValue;
        }
        counter++;
    }

    printf("The smallest integer entered was %d.", min);
    return 0;
}