#include <stdio.h>

int main(){
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    // num1 = 432;
    // num2 = 124;

    if (num1>=num2){
        printf("Number 1: %d is greater than or equal to number 2: %d", num1, num2);
    }else{
        printf("Number 2: %d is greater than number 1:%d", num2, num1);
    }
}