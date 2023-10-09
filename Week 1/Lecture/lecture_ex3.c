#include <stdio.h>
#include <string.h>

int main(){
    int age;
    char license[4];

    puts("Enter your age: ");
    scanf("%d", &age);

    puts("Do you have a license?");
    scanf("%s", license);

    if (age>=18 && !(strcmp(license, "yes"))){
        printf("You can drive");
    } else{
        printf("You can't drive");
    }
}