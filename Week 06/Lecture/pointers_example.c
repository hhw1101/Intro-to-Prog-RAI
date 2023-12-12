#include <stdio.h>

int main()
{
    int *ptr;
    int n;
    ptr = &n;  // address of n assigned to ptr
    *ptr = 10; // value of n assigned to 10
    printf("n = %d\n", n);
    printf("*ptr = %d\n", *ptr);
    *ptr += 1; // value of n incremented by 1
    printf("n = %d\n", n);
    printf("*ptr = %d\n", *ptr);
    (*ptr)++;
    printf("n = %d\n", n);
    printf("*ptr = %d\n", *ptr);
}