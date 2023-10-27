#include <stdio.h>

int main()
{
    long int input, carry; 
    int digits = 0;


    printf("Enter a number: ");
    scanf("%d", &input);
    carry = input;

    while (carry !=0){
        digits++;
        carry =  carry/10;
    }

    printf("%d has %d digits.", input, digits);
}