#include <stdio.h>

int main(){
    int number;
    puts("Enter a number: ");
    scanf("%d", &number);
    
    int loopSummation = 0;
    // In C the curly bracket is not necessary.
    for (int i = 0; i <= number; i++)
        loopSummation += i;
    
    printf("The summation of all the natrual numbers up to %d is %d.", number, loopSummation);
}

int findSummation(int num){

}