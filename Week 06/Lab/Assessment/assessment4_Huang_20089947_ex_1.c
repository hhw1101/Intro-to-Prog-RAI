/*
Jennifer Huang
20089947
Assessment 4 Exercise 1
13/11/2023
*/

#include <stdio.h>

int main()
{
    //part a
    int valueOne = 4, valueTwo = 23;
    int *value1 = &valueOne, *value2 = &valueTwo;
    
    // part b
    printf("The value of integer 1 is %d. \n", valueOne);
    printf("The address of integer 1 is %p. \n", &valueOne);
    printf("The size of integer 1 is %ld bytes.\n", sizeof(valueOne));
    printf("The value of integer 2 is %d. \n", valueTwo);
    printf("The address of integer 2 is %p. \n", &valueTwo);
    printf("The size of integer 2 is %ld bytes. \n", sizeof(valueTwo));
    
    // part c
    printf("\nThe value of pointer 1 is %p. \n", value1);
    printf("The address of pointer 1 is %p. \n", &value1);
    printf("The value pointer 1 points to is %d.\n", *value1);
    printf("The value of pointer 2 is %p. \n", value2);
    printf("The address of pointer 2 is %p. \n", &value2);
    printf("The value pointer 2 points to is %d. \n", *value2);
    
    // part d
    *value1 = *value1 + *value2;
    printf("\nThe sum of the two integers is %d.\n", *value1);
    printf("The value of integer 1 is now %d.\n", valueOne);
    printf("The value of integer 2 is now %d.", valueTwo);
    return 0;
}
