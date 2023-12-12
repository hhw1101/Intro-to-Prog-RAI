#include <stdio.h>

int main()
{
    int city[4][7]; // 4 cities and 7 days
    int i, j, sum = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("Enter temperature for city %d and day %d ", i + 1, j + 1);
            scanf("%d", &city[i][j]);
            printf("Temperature for city %d and day %d is %d\n ", i + 1, j + 1, city[i][j]);
            sum += city[i][j]; // indexing by each dimension
        }
        
        printf("Average temperature for city %d is %d\n", i + 1, sum / 7);
    }

    return 0;
}