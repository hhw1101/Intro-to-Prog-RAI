/*
Jennifer Huang
20089947
Assessment 5 Exercise 1 
27/11/2023
*/
#include <stdio.h>
#include <stdlib.h>

void PrintMatrix(int *matrix){
    for(int j = 0; j< 4;j++){
        printf("%d ", (*(matrix+j)));
    }
    printf("\n");
}

void FindMaxEachRow(int *(matrix), int *max){
    *(max) = *(matrix);
    for(int j = 0; j < 3;j++){
        if(*(max) < *(matrix+j+1)){
            *(max) = *(matrix+j+1);
        }
    }
}

void PrintMax(int *max){
    printf("Maximum of each row\n");
    for(int i = 0; i < 3;i++){
        printf("%d ", *(max+i));
    }
}
int main()
{   
    // Declaration of Array (1)
    int M[3][4] = {{98,79,241,39},{67,128,5,87},{10,163,55,201}};
    // Printing the matrix (2)  
    int *max = malloc(3*sizeof(int));
    for (int i = 0; i < 3; i++){
        PrintMatrix(M[i]);
        // Finding the max 
        FindMaxEachRow(M[i], max+i);
    }
    
    // Print max
    PrintMax(max);
    free(max);
    return 0;
}
