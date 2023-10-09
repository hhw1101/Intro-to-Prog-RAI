#include <stdio.h>

int main(){
    //Integer variable
    int age = 25;

    // Input age from user
    printf("Enter your age: ");
    scanf("%d", &age);

    // Displaying the age
    printf("You entered: %d\n", age);

    return 0;
    
}

/*
a. What happens if you enter a real number as age input?
    The age is then printed in the display text.
b. How to update this code to enable taking real number input?
    No update is needed, unless decimals are needed then floats will be needed for age instead.
c. What does '\n'? From the recommended textbooks, read about the 'excape sequences'.
    \n is new line
    escape sequences are when certain a specific sequence of characters produce a symbol or action ie. new line or backspace.
*/