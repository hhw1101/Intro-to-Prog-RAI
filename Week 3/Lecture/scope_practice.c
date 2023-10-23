#include <stdio.h>

int global = 4;

int update_variables(/*int local*/)
{
    return global = 24;//  local = 3;
    // local is undefined here and cannot be changed
    // a way to change local would be to add a function parameter
}

int main()
{
    int local = 2;

    printf("This is the local variable %d, and this is the global variable %d.\n", local, global);
    global = update_variables(local);
    // global, local = update_variables() makes both local and global the same if local is not returned in function above
    printf("This is the local variable %d, and this is the global variable %d.\n", local, global);
    
    return 0;
}