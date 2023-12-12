#include <stdio.h>

int factorial(int n);

int main(){
    int number;

    puts("Enter a number");
    scanf("%d", &number);

    printf("%d factorial is %d", number, factorial(number));
    return 0;
}

int factorial (int n){
    if (n == 0){
        return 1;
    }else{
        return factorial(n-1)*n;
    }
}