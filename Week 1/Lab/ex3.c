/*#include <conio.h>
need to wait for mingw download*/
#include <stdio.h>
#include <conio.h>

int main(){
    char grade;
    int getch_grade;
    // printf("Enter you grade: ");
    // scanf("%c", &grade);

    // printf("You grade is: %c", grade);
    // Prints the character entered

    // printf("Enter you grade: ");
    // getch_grade = getch(); // Gives a ASCII value so doesn"t work with char

    // printf("Your grade is: %c", getch_grade);
    // Prints the ASCII value of the entered grade

    printf("Enter you grade: ");
    grade = getche(); //getchar() sometimes but returns a single char and does not require enter

    printf("\nYour grade is: %c", grade);
    // Prints the grade, however enter button not needed and the grade is stored as a single char.
    
    return 0;
}