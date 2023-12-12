/*
Write a C program that initializes an integer variable with a value 
and demonstrates the difference between pre-increment and post-increment 
by using both operators on the variable. 
Print the values before and after the increment operations.
    a)Observe how the increment operation is performed. 
    Update the program to use the decrement operator instead. 
    Experiment with also first doing pre and then post and vice versa. 
    Observe the values in both cases.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = rand();
    int b = a;
    int pre,post;
    printf("This is using an pre-increment operator for on the initial value %d.\n", a);
    pre = ++a;
    printf("This is the values that are given using pre-increment, %d and %d.\n", pre,a);

    printf("This is using an pre-increment operator for on the initial value %d.\n", b);
    post = b++;
    printf("This is the values that are given using pre-increment, %d and %d.\n", post, b);

}