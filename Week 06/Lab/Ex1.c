#include <stdio.h>

int frequency(int *num, int value)
{
    int count = 0;
    for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++)
    {
        if (num[i] == value)
        {
            count++;
        }
    }
    printf("%d occurs %d times.", value, count);
}

int main()
{
    int arrayLength;
    printf("Enter size of array: ");
    scanf("%d", &arrayLength);
    int inputNumbers[2][arrayLength];
    puts("Enter elemnts in array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        scanf("%d", &inputNumbers[0][i]);
    }
    int uniqueValues[arrayLength];
    
    
}
