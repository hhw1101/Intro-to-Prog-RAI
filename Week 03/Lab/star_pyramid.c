#include <stdio.h>

int main()
{
    int rows;
    puts("Enter the number of rows: ");
    scanf("%d", &rows);
    // char list[2*rows];
    for (int i = 1; i < rows+1; i++)
    {
        for (int j = 0; j < rows -i; j++)
        {
            printf(" ");
        }
        
        for (int k=1; k < i+1;k++){
            printf("* ");
        }

        printf("\n");
    }
    return 0;
}
