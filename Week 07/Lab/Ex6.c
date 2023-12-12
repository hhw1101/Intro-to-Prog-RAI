#include <stdio.h>

int main()
{
    int nums[] = {2, 3, 5, 7, 9, 12, 50};
    int target = 8;
    int index[2];
    for (size_t i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        for (size_t j = i+1; j < sizeof(nums) / sizeof(nums[0]); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                index[0] = i + 1;
                index[1] = j + 1;
                break;
            }
        }
    }

    for (size_t i = 0; i < 2; i++)
    {
        printf("%d ", index[i]);
    }

    return 0;
}