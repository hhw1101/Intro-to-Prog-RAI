#include <stdio.h>
#include <conio.h>

int main(){
    // Defining variables
    char name[15];
    int age;
    float GPA;
    char grade;

    // taking inputs
    puts("Enter Student's name:");
    gets(name);

    puts("Enter Student's age:");
    scanf("%i", &age);

    puts("Enter Student's GPA:");
    scanf("%f",&GPA);

    puts("Enter Student's grade:");
    grade = getche();

    printf("\n%s is %i. %s currently has a GPA of %.2f and a grade of %c", name, age, name, GPA, grade );
}