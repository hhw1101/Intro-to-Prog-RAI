#include <stdio.h>

int main(){
    float len, width, area;

    puts("Enter the length:");
    scanf("%2f", &len);

    puts("Enter the width:");
    scanf("%2f", &width);

    area = width * len;

    printf("The area of a rectangle with length, %2f, and width, %2f, is %2f.", len, width, area);


}