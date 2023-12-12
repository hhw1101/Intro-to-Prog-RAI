#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // This randomises rand, otherwise rand will give the same value each game.
    int num = rand() % 100 + 1;
    int guess = 0, turns = 1;
    printf("Welcome to the Guess the Number game!\nI"ve selected a random number between 1 and 100.\nCan you guess what it is?\n");

    while (guess != num)
    {
        puts("Enter your guess:");
        scanf("%d", &guess);
        if (guess > num)
        {
            printf("\nToo high!\nTry Again!\n");
        }
        else if (guess < num)
        {
            printf("\nToo low!\nTry Again!\n");
        }
        else
        {
            printf("Congratulations you guessed my number, %d in %d turns.", num, turns);
        }
        turns++;
    }
    return 0;
}