# Pointers

## Basics

slide 10 onwards
Only the address of same data type of variables can be assigned to pointer of the same data type.
If uninitialised pointer cannot be used.
Some compilers(mostly online) will assign the pointer NULL, however most assign some random varaible. 

~~~
void f()
{
    int *ptr;
    *ptr = 5;
    //ptr doesn't contain an address and therefore the 5 is lost.
}
~~~

__void *var__ decalres a vector however the type of variable is yet to be determined. To use the variable it needs to be typecasted.

pointers if typecasted again if the initial value uses more bytes, and we override with a smaller data type then memory is lost to accomodate for the new data type. 

## Pointer Operations

%u is unsigned type whereas %p prints the hexadecimal pointer location