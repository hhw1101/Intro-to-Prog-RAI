/*

for loop
    if x < y then
        switch
    end if
end loop
*/

#include <stdio.h>

void bubbleSort(int *nums, int size)
{
    for (size_t j = 0; j < size; j++)
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            if (*(nums + i) > *(nums + i + 1))
            {
                *(nums + i) += *(nums + i + 1);
                *(nums + i + 1) = *(nums + i) - *(nums + i + 1);
                *(nums + i) = *(nums + i) - *(nums + i + 1);
            }
        }
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arrayBubble[size];
    for (int i = 0; i < size; i++)
    {
        {
            printf("Enter an element: ");
            scanf("%d", &arrayBubble[i]);
        }
    }

    // Bubble Sort in main
    //  for (size_t i = 0; i < size; i++)
    //  {
    //      for (size_t j = 0; j < size - 1; j++)
    //      {

    //         if (arrayBubble[j] > arrayBubble[j + 1])
    //         {
    //             arrayBubble[j] += arrayBubble[j + 1];
    //             arrayBubble[j + 1] = arrayBubble[j] - arrayBubble[j + 1];
    //             arrayBubble[j] = arrayBubble[j] - arrayBubble[j + 1];
    //         }
    //     }
    // }

    bubbleSort(arrayBubble, size);

    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arrayBubble[i]);
    }

    return 0;
}