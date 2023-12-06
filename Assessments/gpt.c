
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEIGHT 20
#define WIDTH 2 * HEIGHT

void draw(int *board)
{
    for (size_t i = 0; i < HEIGHT; i++)
    {
        for (size_t j = 0; j < WIDTH; j++)
        {
            addch(*((board + i * WIDTH) + j));
        }
        addch('\n');
    }
}

void initializematrix(int *m)
{
    for (size_t i = 0; i < HEIGHT; i++)
    {
        for (size_t j = 0; j < WIDTH; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    *((m + i * WIDTH) + j) = ACS_ULCORNER;
                }
                else if (j == WIDTH - 1)
                {
                    *((m + i * WIDTH) + j) = ACS_URCORNER;
                }
                else
                {
                    *((m + i * WIDTH) + j) = ACS_HLINE;
                }
            }
            else if (i == HEIGHT - 1)
            {
                if (j == 0)
                {
                    *((m + i * WIDTH) + j) = ACS_LLCORNER;
                }
                else if (j == WIDTH - 1)
                {
                    *((m + i * WIDTH) + j) = ACS_LRCORNER;
                }
                else
                {
                    *((m + i * WIDTH) + j) = ACS_HLINE;
                }
            }
            else
            {
                if (j == 0 || j == WIDTH - 1)
                {
                    *((m + i * WIDTH) + j) = ACS_VLINE;
                }
                else
                {
                    *((m + i * WIDTH) + j) = ' ';
                }
            }
        }
    }
}

void game()
{
    int playerx = WIDTH / 2, playery = HEIGHT / 2;
    int directionx = 0, directiony = 0;
    int board[HEIGHT][WIDTH];
    int key;
    int Xmax = WIDTH - 2;
    int Ymax = HEIGHT - 2;
    int level = 1;
    int score = 0;
    int lives = 3;

    initializematrix((int *)board);
    srand(time(NULL));

    while (lives > 0 && key != 'q' && key != 'Q')
    {
        clear();
        draw((int *)board);
        mvprintw(HEIGHT + 1, 5, "Level: %d", level);
        mvprintw(HEIGHT + 1, 25, "Score: %d", score);
        mvprintw(HEIGHT + 1, 45, "Lives: %d", lives);
        mvprintw(HEIGHT + 1, WIDTH - 25, "Press q to quit");

        // Draw the player avatar
        mvwaddch(stdscr, playery, playerx, ACS_BLOCK);

        key = getch();
        switch (key)
        {
        case KEY_LEFT:
            // Handle left movement
            break;
        case KEY_RIGHT:
            // Handle right movement
            break;
        case KEY_UP:
            // Handle up movement
            break;
        case KEY_DOWN:
            // Handle down movement
            break;
        case 'q':
        case 'Q':
            // Quit the game
            break;
        default:
            break;
        }

        // Update the player's position and the game board here

        // usleep(200000);
    }
}

int main()
{
    // initialising ncurses
    initscr();
    noecho();
    raw();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

    // char *options[5] = {"Welcome to find the Diamonds", "Start Game", "View Leaderboard", "How to Play", "Press q to quit"};
    int menu_press = 0;
    int optiony = 5;
    int selected;

    // Opening Menu
    while (menu_press != 10)
    {
        // Print menu options
        // ...

        mvaddch(optiony, 35, ACS_LARROW);
        menu_press = getch();

        // Handle menu navigation
        // ...

        refresh();
    }
    clear();

    if (selected == 4)
    {
        endwin();
    }
    else if (selected == 3)
    {
        // Display "How to Play" instructions
        endwin();
    }
    else if (selected == 2)
    {
        // Display Leaderboard
        endwin();
    }
    else
    {
        // Start the game
        game();
        endwin();
    }

    return 0;
}
