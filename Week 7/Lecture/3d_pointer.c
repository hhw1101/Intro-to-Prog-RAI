/* Carried over from Lecture 6

Layer 0     Layer 1
1   2       5   6
3   4       7   8

*/

#include <stdio.h>

int main()
{
    int C[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
    int ptrC = C;
    int ptrC0 = C[0];
    int ptrC00 = C[0][0];

    printf("%p\n", ptrC);
    printf("%p\n", ptrC0);
    printf("%p\n", ptrC00);
    printf("%d\n", *(*(*(C)))+1);
    printf("%d\n", *(*(*(C+1)+1)));
}