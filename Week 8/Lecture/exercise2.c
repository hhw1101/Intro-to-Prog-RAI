#include <stdio.h>
#include <string.h>

int main(){
    FILE *fp;
    fp = fopen("C:/Users/jenni/Desktop/Coding/UCL/Programming for RAI/Week 8/Lecture/bookdetails.txt", "w");
    char str[40];
    fprintf(fp, "Book: C Programming Absolute Beginners's Guide\n");
    fprintf(fp, "Author: Greg Perry\n");
    fprintf(fp, "Book: Head First C: A Brain-Friendly Guide\n");
    fprintf(fp, "Author: David Griffiths\n");
    fclose(fp);
    return 0;
}