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
    int nums[] = {2, 3, 5, 7, 9, 12, 50};
    int target = 9;
    int index[2];
    for (size_t i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (i == j)
            {
                continue;
                ;
            }
            else if (nums[i] + nums[j] == target)
            {
                index[0] = i + 1;
                index[1] = j + 1;
                break;
            }
        }
    }
    // Order the list as checks above do not ensure the output is ordered.
    bubbleSort(index, 2);

    for (size_t i = 0; i < 2; i++)
    {
        printf("%d ", index[i]);
    }

    return 0;
}