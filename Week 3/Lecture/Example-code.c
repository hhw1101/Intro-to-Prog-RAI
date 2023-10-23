
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* Write a C program that takes an integer input between 1 and 10
from the user and converts it into its corresponding word form.
For example, if the user inputs 5, the program should print
"Five". Ensure that the program displays an appropriate
message if the user enters a number outside the specified range. */

bool is_Between(const int IntegerInput, const int MinimumInput, const int MaximumInput);
// Return True if IntegerInput is within the range defined by MinimumInput and MaximumOut

char *convert_Integer_to_String(const int IntegerInput);
// Return an string of the corresponding integer, IntegerInput. Range is from 1-10 (inclusive)

int main(void)
{
    const unsigned short MinimumInput = 1; 
    const unsigned short MaximumInput = 10;
    // The accepted range of user input are integers between 1-10 (inclusive)

    const unsigned int IntegerInput; 
    // Declare a variable for user input

    do 
    {
        printf("Enter an integer between 1 and 10: ");
        scanf(" %u", &IntegerInput);
    } while (is_Between(IntegerInput,MinimumInput,MaximumInput) == false);
    // Continue receiving user input until user input falls within range (MinimumInput-MaximumInput).

    char * StringOutput = convert_Integer_to_String(IntegerInput); 
    // Declare a string variable to be printed

    printf("The number, %d, is spelt: %s", IntegerInput, StringOutput);
    // Printing results

    free(StringOutput);
    // Freeing memory from pointer

    return 0;
}

bool is_Between(const int IntegerInput, const int MinimumInput, const int MaximumInput)
{
    if (IntegerInput >= MinimumInput && IntegerInput <= MaximumInput)
    {
        return true;
    }

    else
    {
        printf("The integer you have entered is not within the given range.\n");
        return false;
    }
}

char *convert_Integer_to_String(const int Integer)
{
    char *String;
    
    switch(Integer)
    {
        case 1:
            String = calloc(4,sizeof(char));

            String[0] = 'O';
            String[1] = 'n';
            String[2] = 'e';
            String[3] = '\0';

            break;

        case 2:
            String = calloc(4,sizeof(char));

            String[0] = 'T';
            String[1] = 'w';
            String[2] = 'o';
            String[3] = '\0';

            break;

        case 3:
            String = calloc(6,sizeof(char));

            String[0] = 'T';
            String[1] = 'h';
            String[2] = 'r';
            String[3] = 'e';
            String[4] = 'e';
            String[5] = '\0';

            break;

        case 4:
            String = calloc(5,sizeof(char));

            String[0] = 'F';
            String[1] = 'o';
            String[2] = 'u';
            String[3] = 'r';
            String[4] = '\0';

            break;

        case 5:
            String = calloc(5,sizeof(char));
            String[0] = 'F';
            String[1] = 'i';
            String[2] = 'v';
            String[3] = 'e';
            String[4] = '\0';

            break;

        case 6: 
            String = calloc(4,sizeof(char));

            String[0] = 'S';
            String[1] = 'i';
            String[2] = 'x';
            String[3] = '\0';

            break;

        case 7:
            String = calloc(6,sizeof(char));

            String[0] = 'S';
            String[1] = 'e';
            String[2] = 'v';
            String[3] = 'e';
            String[4] = 'n';
            String[5] = '\0';

            break;

        case 8:
            String = calloc(6,sizeof(char));

            String[0] = 'E';
            String[1] = 'i';
            String[2] = 'g';
            String[3] = 'h';
            String[4] = 't';
            String[5] = '\0';

            break;

        case 9:
            String = calloc(5,sizeof(char));

            String[0] = 'N';
            String[1] = 'i';
            String[2] = 'n';
            String[3] = 'e';
            String[4] = '\0';

            break;

        case 10:
            String = calloc(4,sizeof(char));

            String[0] = 'T';
            String[1] = 'e';
            String[2] = 'n';
            String[3] = '\0';

            break;
    }

    return String;
}
