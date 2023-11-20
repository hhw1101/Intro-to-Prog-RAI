#include <stdio.h>

int main(){
    char ch = 'Z';
    char *cptr = &ch;
    printf("cptr is %p\n", cptr);
    printf("The character at cptr is %c\n", *cptr);

    //Pointer arithmetic - check what cptre + 1 is
    cptr = cptr + 1;
    printf("cptr is %p\n", cptr);

    // printf("The character ar cptr is %c\n", *cptr);
    //Do not print *cptr, because it points to memory space not allocated to your program
    // Size of char is 1 byte

    //Looking into the size of the int data type
    int num = 30;
    int *ptrNum = &num;
    printf("Numptr is %p\n", ptrNum);
    printf("The integer at Numptr is %d\n", *ptrNum);

    ptrNum +=1;
    printf("Numptr is %p\n",ptrNum);
    // Size of integer is 4 byte

    //Looking into th esize of the double data type
    double dnum = 3;
    double *ptrdNum = &dnum;
    printf("Numptr is %p\n", ptrdNum);
    printf("The double at Numptr is %f\n", *ptrdNum);

    ptrdNum +=1;
    printf("Numptr is %p\n",ptrdNum);

    // Size of double is 8 byte

    //Prediciton adding 2 to the pointer will give the size * 2 more of the current pointer
    printf("\nNumptr is %p\n", ptrdNum);
    printf("After adding 2 to the pointer\n");
    ptrdNum +=2;
    printf("Numptr is %p\n",ptrdNum);

    printf("\nNumptr is %p\n", ptrNum);
    printf("After adding 2 to the pointer\n");
    ptrNum +=2;
    printf("Numptr is %p\n",ptrNum);
    
    printf("\nNumptr is %p\n", cptr);
    printf("After adding 2 to the pointer\n");
    cptr +=2;
    printf("Numptr is %p\n",cptr);
    //Conclusion the same as prediction

    return 0;


}