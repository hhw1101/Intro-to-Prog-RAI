#include <stdio.h>
#include <ctype.h> // for the strlen() function
#include <stdbool.h>

bool checkUppercase(char string[])
{
    // for (int i = 0; i < strlen(string); i++){
    //     if (string[i].isupper()){
    //         return true;
    //     }
    // }
    return false;
}
bool checkLowercase()
{
    return false;
}
bool checkDigit()
{
    return false;
}
bool checkSpecial()
{
    return false;
}
bool checkLength()
{
    return false;
}

int main()
{
    char strpwd[40];
    char strusn[15];
    puts("Enter a Username:");
    scanf("%s", strusn);
    puts("Enter a Password:");
    scanf("%s", strpwd);
    if (
        checkUppercase(strpwd) &&
        checkLowercase(strpwd) &&
        checkDigit(strpwd) &&
        checkSpecial(strpwd) &&
        checkLength(strpwd))
    {
        printf("Hello, %s, your password is strong.");
    }
    else
    {
        printf("Hello, %s, your password is weak.");
    }
}