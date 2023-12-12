#include <stdio.h>

int main()
{
    // array to store string taken as input
    char color[20];
    char name[20];

    /*
    // 4.b Takes user input and outputs name
    //take user input
    printf("Enter your Name: ");
    scanf("%s", name);

    printf("Enter your favourite colour: ");
    scanf("%s", color);
    */

    /*
    // 4.c Using gets instead of scanf
    //take user input
    printf("Enter your Name: ");
    gets(name);

    printf("Enter your favourite colour: ");
    gets(color);
    */

    
    // 4.d uses puts instead of printf for single print statements, no variables
    // puts defaults an extra new line at the end
    //take user input
    puts("Enter your Name: ");
    gets(name);

    puts("Enter your favourite colour: ");
    gets(color);
    

    // printing the input value
    // printf("Hello %s, your favourite color is %s", name, color);
    
    // puts doesn"t allow for formatting.
    char string[50];
    // sprintf is needed to combine the string of the text and variables into one long character array
    sprintf(string, "Hello %s, your favourite color is %s", name, color);
    puts(string);

    return 0;
}
/*
4.a
- ‘&’ is used to get the address of the variable.
C does not have a string type,
String is just an array of characters
and an array variable stores the address of the first index location.
- By default the variable itself points to the base address
and therefore to access base address of string,
there is no need of adding an extra ‘&’
*/
