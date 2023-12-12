#include <stdio.h>

float VAT(int original){
    return original * 1.2;
}


int main(){
    float amount = 100;
    puts("Enter a the cost:");
    scanf("%f", &amount);

    printf("The cost of the item without VAT is %.2f, with VAT the cost is %.2f.", amount, VAT(amount));
}