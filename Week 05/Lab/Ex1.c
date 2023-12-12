#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    int matrix1[n][n];
    int matrix2[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the value in the First matrix for position %d, %d:", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
            printf("Enter the value in the Second matrix for position %d, %d:", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }
    int operation;
    do
    {
        printf("Press 1 to add the Matices\nPress 2 to subtract the Matrices\nPress 3 to multiply the Matrices\nEnter your operation: ");
        scanf("%d", &operation);
    } while (operation < 0 && operation > 3);

    switch (operation)
    {
    case 1:
        
        break;
    case 2:
        break;
    case 3:
        break;
    }
    return 0;
}