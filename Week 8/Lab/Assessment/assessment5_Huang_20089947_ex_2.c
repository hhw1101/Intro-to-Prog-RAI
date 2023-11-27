/*
Jennifer Huang
20089947
Assessment 5 Exercise 2
27/11/2023
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *firstname = (char *)malloc(20*sizeof(char));
    char *surname = (char *)malloc(20*sizeof(char));
    printf("Enter your first name: ");
    scanf("%s", firstname);
    printf("Enter your surname: ");
    scanf("%s", surname);
    int length;
    for (int i = 0 ; i < 20;i++){
        if(*(firstname+i) == '\0'){
            length = i;
            break;
        }
    }
    
    printf("The length of the first name is %d.\n", length);
    
    // *(firstname+length + 1) = ' ';
    
    for (int i = 0; i < 20; i++){
        *(firstname + length + i) = *(surname+i);
    }
    printf("Your full name is: %s", firstname);
    free(firstname);
    free(surname);
    return 0;
}
