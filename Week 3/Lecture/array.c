#include <stdio.h>
void sortArray(int *num)
{
    int temp;
    for (int i = 0; i < sizeof(num); i++)
    {
        for (int j = i + 1; j < sizeof(num); j++)
        {
            if (num[j] >= num[i])
            {
                temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
        }
    }
}

int main()
{
    int n = 5;
    int numbers[n];
    // int largest = 0, secondLargest= 0;
    for (int i = 0; i < n; i++)
    {
        puts("Enter a number:");
        scanf("%d", &numbers[i]);
    }
    for (int j = 0; j < n; j++)
    {
        printf("%d ", numbers[j]);
    }
    printf("\n");
    sortArray(numbers);
    for (int j = 0; j < n; j++)
    {
        printf("%d ", numbers[j]);
    }

    // for (int i = 0; i < sizeof(numbers); i++){
    //     if (i == 0){
    //         largest = numbers[i];
    //         secondLargest = numbers[i];
    //     } else if(numbers[i] > largest){
    //         secondLargest = largest;
    //         largest = numbers[i];
    //     }
    // }

    printf("\nThe largest number is: %d", numbers[0]);
    printf("\nThe second largest number is: %d", numbers[1]);

    return 0;
}