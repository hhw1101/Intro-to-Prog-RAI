#include <stdio.h>

int main()
{
    int a[] = {2, 4, 8, 10, 12, 14, 16, 18};
    int *p1 = &a[0];
    printf("%d ", *(p1++));
    printf("%d ", *(p1));

    int *p2 = &a[2];
    printf("%d ", *(p2));
    printf("%d ", *(--p2));
    printf("%d ", *(p2--));
    printf("%d ", *(p2));

    return 0;
}
