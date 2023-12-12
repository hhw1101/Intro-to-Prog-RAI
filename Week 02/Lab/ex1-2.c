/*
Write a C program that take a temperature in Celsius from the user, and converts it into Fahrenheit. 
Prompt the user to enter the temperature in Celsius as a floating-point number, 
perform the conversion, and display the result as an integer (rounded to the nearest degree Fahrenheit).
*/

#include <stdio.h>

int main(){
    float celcius;
    int fahrenheit;

    puts("Enter the temperature in Celcius:");
    scanf("%f", &celcius);

    fahrenheit = celcius * 1.8 + 32;

    printf("The temperature in Fahrenheit is %d",fahrenheit);

}