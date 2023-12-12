/*
PsuedoCode:
1. Take input
2. Check if >=60 
3. Output

Flow
Input --> input >= 60 -(yes)-> output "PASS"
                      -(no)->  output "Fail"
*/

#include <stdio.h>

int main(){
    int percentage;

    puts("Enter student grade:");
    scanf("%d", &percentage);
    
    if (percentage >=60){
        printf("PASS!");
    }else{
        printf("FAIL");
    }

    return 0;
}
