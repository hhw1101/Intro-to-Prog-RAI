/*
a) Write a C program that takes a character as input, 
type cast it into an integer(ASCII value) and print the character and its ASCII value.

b) Extend this C program to now also take an ASCII value (1-255), 
type cast it into a character and print the ASCII value and its character.
*/

#include <stdio.h>

int main(){
    char c;
    int c_ascii;
    int a_value;
    char a;

    // part a
    puts("Enter a character:");
    c = getchar();
    c_ascii = c;

    printf("You entered %c, which is %d in ASCII.\n",c,c_ascii);

    // part b
    puts("Enter a number:");
    scanf("%d", &a_value);
    a = a_value;

    printf("You entered %d as ASCII, which is the character %c.",a_value,a);
    
}