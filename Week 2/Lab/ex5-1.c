#include <stdio.h>

int main()
{
    int a = 5;
    int b = 3;
    int c = 4;
    int d = 2;
    int e = 7;
    float i, ii;

    i = (a + b) * c / d - e;
    ii = a++ + ++b * c / d - e--;

    printf("The first expression equates to %.2f.\n", i);
    printf("The second expression equates to %.2f.\n", ii);
    // steps of ii
    int a_post = a++;
    int b_pre = ++b;
    int e_post = e--;

    printf("new variables a : %d.\n", a_post);
    printf("new variables b : %d.\n", b_pre);
    printf("new variables e : %d.\n", e_post);
    // I can"t do math

}