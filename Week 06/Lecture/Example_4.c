#include <stdio.h>

int main(){
    int *ptr;
    int num1=0;
    ptr = &num1;

    printf("%u\n", ptr);
    printf("%d\n", *ptr);
    ptr++; // 1000 + 1*4 = 1004

    printf("%u\n", ptr);
    printf("%d", *ptr);

    return 0;
}