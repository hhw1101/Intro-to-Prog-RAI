#include <stdio.h>

int main(){

    // array to story string taken as input
    char color[5];
    char string[50];
    //take user input
    puts("Enter your favourite color: ");
    fgets(color, sizeof(color), stdin);

    // printing the input value
    sprintf(string, "Your favourite color is %s", color);
    puts(string);
    
    return 0;
    // there is a limit amount of characters that the string can take which is length - 1
    // fgets is also used to read from files, the parameters are as follows fgets(str_name, max_length, stream_or_file_name)

}