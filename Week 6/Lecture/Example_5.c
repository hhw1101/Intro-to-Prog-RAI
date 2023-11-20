#include <stdio.h>

int main()
{
    int *ptr1, *ptr2;
    int num1 = 93;
    ptr1 = &num1;
    ptr2 = ptr1;
    printf("The value of num1 is: %d\n", num1);
    printf("The address of num1 is: %u\n", &num1);
    printf("pointer1 value is: %u\n", ptr1);
    printf("pointer2 value is: %u\n", ptr2);
    printf("pointer1 address %u\n", &ptr1);
    printf("pointer2 address %u\n", &ptr2);

    return 0;
}
