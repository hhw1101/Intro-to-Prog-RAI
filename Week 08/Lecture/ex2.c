#include <stdio.h>
int main(void){
    FILE *fp;
    int num = 93;
    float data = 23.52;

    fp = fopen("C:/Users/jenni/Desktop/Coding/UCL/Programming for RAI/Week 8/Lecture/ex1.txt", "w");
    if(fp = NULL){
        printf("Error opening file\n");
        return 1;
    }
    fprintf(fp, "%d %f", num, data);
    fclose(fp);
    return 0;
}