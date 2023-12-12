#include <stdio.h>
#include <string.h>

int main()
{
    // char str1[100];
    // char str2[100];
    // printf("Enter the first string: ");
    // scanf("%s", str1);
    // printf("Enter the second string: ");
    // scanf("%s", str2);

    // if (str1 == str2) //strcmp(str1,str2)
    // {
    //     strcat(str1, str2);
    //     printf("%s", str1);
    // }
    // else if (str1 > str2)
    // {
    //     printf("%s %s", str1, str2);
    // }
    // else
    // {
    //     printf("%s %s", str2, str1);
    // }

    char strsen[1000];
    printf("Enter a sentence: ");
    scanf("%s", strsen);
    int count = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (strsen[i] == ' ' && strsen[i + 1] != ' ')
        {
            count++;
        }
    }
    printf("There are %d words", count);
}