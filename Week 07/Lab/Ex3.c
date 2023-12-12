/*

a b c           g d a
d e f   ---->   h e b
g h i           i f c

Clockwise
00 --> 02       10 --> 01       20 --> 00
01 --> 12       11 --> 11       21 --> 10
02 --> 22       12 --> 21       22 --> 20

Anti-clockwise
00 --> 20       10 --> 21       20 --> 22
01 --> 10       11 --> 11       21 --> 12
02 --> 00       12 --> 01       22 --> 02

Pseudocode
int array[3][3];
int rotatedarray[3][3];
assign pointers
for loop
    assign array
end loop
get rotation direction
for loop
    new assignment
end for
*/

#include <stdio.h>

int main()
{
    const int SIZE = 3;
    int matrix[SIZE][SIZE];
    int matrixT[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("Enter the element in position %d, %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    int direction;
    printf("For a clockwise rotation enter 1.\nFor a anti-clockwise rotation enter 2.\nEnter the direction of rotation: ");
    scanf("%d", &direction);
    switch (direction)
    {
    case 1:
        // Clockwise Rotation
        for (size_t i = 0; i < SIZE; i++)
        {
            for (size_t j = 0; j < SIZE; j++)
            {
                *(*(matrixT + i) + j) = *(*(matrix + SIZE - 1 - j) + i);
            }
        }
        break;
    case 2:
        // Anti-Clockwise Rotation
        for (size_t i = 0; i < SIZE; i++)
        {
            for (size_t j = 0; j < SIZE; j++)
            {
                *(*(matrixT + i) + j) = *(*(matrix + j) + SIZE - 1 - i);
            }
        }
        break;

    default:
        printf("An Error has occured");
        break;
    }

    // Array/Matrix Print
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            printf("%d ", *(*(matrixT + i) + j));
        }
        printf("\n");
    }

    // This should now work for any dimension square matrix.
    // Done after seeing example in labs
    return 0;
}
//Extension to do this without the second 2D array
