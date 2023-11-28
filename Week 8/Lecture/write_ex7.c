#include <stdio.h>
#include <string.h>

int main(){
    FILE *fp;
    fp = fopen("C:/Users/jenni/Desktop/Coding/UCL/Programming for RAI/Week 8/Lecture/ex7.txt", "a");
    char str[40];
    strcpy(str, "Writing a string to a txt file");
    fprintf(fp, "%s", str);
    fclose(fp);
    return 0;
}