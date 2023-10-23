#include <stdio.h>

void increment(){
    static int counter =0;
    // static variable with local scope

    counter++;
    printf("Counter: %d\n", counter);
}

int main(){
    increment();
    increment();
    increment();
    return 0;
}