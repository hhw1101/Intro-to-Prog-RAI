#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Defining Constants
#define HEIGHT 40
#define WIDTH 120

void initializematrix(int *m);
void draw(int *board);
int orientation(int *board, int direction, int *x, int *y, float *speed, int level);
void obstacle(int *board, int n);

int main()
{ // Seeding Srand
    srand(time(NULL));
    // Defining variables
    // 2D matrix for board with player, food and danger zones
    int board[HEIGHT][WIDTH];
    // Generating random starting position
    int x = rand() % (WIDTH - 2) + 1;
    int y = rand() % (HEIGHT - 2) + 1;
    // Player position is kept in first list
    // Player stats is kept in second list {score, level, lives}
    int player[2][3] = {{x, y}, {0, 1, 3}};
    int foodx, foody;
    char food = ACS_DIAMOND;
    char danger = ACS_PLUS;
    // player input
    int move = KEY_UP;
    int directione = 0;
    // 0 is left, 1 is right, 2 is up, 3 is down


    float speed[] = {1, 1.0625, 1.125, 1.25, 1.5};

    // Initialising ncurses
    initscr();
    raw();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    start_color();

    // Defining color pairs
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    printw("Hello");
    // Generating a matrix for the board
    initializematrix((int *)board);

    while (player[1][2] > 0 && move != 81 && move != 113 && move != 27)
    {
        draw((int *)board);
        // obstacle((int *)board, 3);
        orientation((int *)board, move, &x, &y, speed, player[1][1]);
        clear();
        draw((int *)board);
        move = getch();
    }
    endwin();
    return 0;
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

int orientation(int *board, int direction, int *x, int *y, float *speed, int level)
{
    switch (direction)
    {
    case 0404:
        if (*x > 1)
        {
            *x -= speed[level / 2 + 1];
            *((board + *y * WIDTH) + *x) = ACS_RTEE;

            if (*x - 1 >= 1)
            {
                *((board + *y * WIDTH) + *x - 1) = ACS_LARROW;
            }
        }
        else
        {
            // lose life
            *x = WIDTH / 2;
            *y = HEIGHT / 2;
            return -1;
        }

        break;

    case 0405:
        if (*x < WIDTH - 2)
        {
            *x += speed[level / 2 + 1];
            *((board + *y * WIDTH) + *x) = ACS_LTEE;
            if (*x + 1 < WIDTH - 1)
            {
                *((board + *y * WIDTH) + *x + 1) = ACS_RARROW;
            }
        }
        else
        {
            // lose life

            *x = WIDTH / 2;
            *y = HEIGHT / 2;
            return -1;
        }
        break;

    case 0403:
        if (*y > 1)
        {
            *y -= speed[level / 2 + 1];
            *((board + *y * WIDTH) + *x) = ACS_BTEE;
            if (*y - 1 > 1)
            {
                *((board + (*y - 1) * WIDTH) + *x) = ACS_UARROW;
            }
        }
        else
        {
            // lose life
            *x = WIDTH / 2;
            *y = HEIGHT / 2;
            return -1;
        }
        break;

    case 0402:
        if (*y < WIDTH - 2)
        {
            *y += speed[level / 2 + 1];
            *((board + *y * WIDTH) + *x) = ACS_TTEE;
            if (*y + 1 < WIDTH - 1)
            {
                *((board + (*y + 1) * WIDTH) + *x) = ACS_DARROW;
            }
        }
        else
        {
            // lose life
            *x = WIDTH / 2;
            *y = HEIGHT / 2;
            return -1;
        }
        break;
    }
    return 0;
}

void obstacle(int *board, int n)
{
    int x;
    int y;
    srand(time(NULL));
    for (size_t i = 0; i < n; i++)
    {
        do
        {
            int x = rand() % (WIDTH - 2) + 1;
            int y = rand() % (HEIGHT - 2) + 1;
        } while (*((board + y * WIDTH) + x) != ' ');
        attrset(COLOR_PAIR(1));
        mvaddch(y, x, ACS_PLUS);
        *((board + y * WIDTH) + x) = ACS_PLUS;
        attroff(COLOR_PAIR(1));
    }
}