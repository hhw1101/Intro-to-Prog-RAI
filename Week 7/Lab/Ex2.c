#include <stdio.h>

int main(){
    int array[10];
    int *ptrArray = array;
    for (int i = 0; i < 10; i++){
        printf("Enter an element: ");
        scanf("%d", &array[i]);
    }

    //Print in reverse
    for (size_t i = 10; i > 0; i--)
    {
        printf("%d ", *(ptrArray + i-1));
    }
    //The -1 is needed as there are 9 other elements asside from the first element that the pointer currently points to.
    //Therefore the -1 is needed to print the proper array.
}