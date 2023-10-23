#include <stdio.h>

int main(){
    // Switch question
    int choice = 2;
    switch (choice){
        case 1:
        printf("A");
        case 2:
        printf("B");
        case 3:
        printf("C");
        default:
        printf("D");
    }
    // outputs BCD

    // overflow question
    short a = 32767;
    printf("\n%d", a);
    a +=1;
    printf("\n%d", a);

    // overflow error, all 0s is mapped to -32768

    
    return 0;
}