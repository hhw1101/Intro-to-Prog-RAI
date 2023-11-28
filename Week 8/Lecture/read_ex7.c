#include<stdio.h>
#include<string.h>

int main(){
    FILE *fp;
    fp = fopen("C:/Users/jenni/Desktop/Coding/UCL/Programming for RAI/Week 8/Lecture/ex7.txt", "r");
    char c; 
    while(!feof(fp)){
        c = getc(fp);
        putchar(c);
    }
    fclose(fp);
    return 0;
/*
    // Alternate method
    while(1){
        fscanf(fp, "%c", &character);
        printf("%c", character);
        if (feof(fp)){
            printf("\nEnd of file reached.\n");
            break;
        }
    }
*/
}