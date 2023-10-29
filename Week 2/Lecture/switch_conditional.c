#include <stdio.h>

int main(){
    char c;
    puts("Enter grade:");
    scanf("%c", &c);
    switch(c)
    {
        case "A":
            printf("90-100");
            break;
        case "B":
            printf("80-89");
            break;
        case "C":
            printf("70-79");
            break;
        case "D":
            printf("60-69");
            break;
        case "F":
            printf("0-59");
            break;
        default:
            printf("Error");
    }
    
    return 0;
}