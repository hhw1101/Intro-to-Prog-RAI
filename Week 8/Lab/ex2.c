#include <ncurses/ncurses.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int WIDTH = 15;
    const int HEIGHT = 10;
    srand(time(NULL));
    int x = rand() % (WIDTH - 1) + 1;
    int y = rand() % (HEIGHT - 1) + 1;
    char move;
    char character = 'R';
    initscr();

    for (int i = 0; i < HEIGHT; i++)
    {
        for (size_t j = 0; j < WIDTH; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    addch(ACS_ULCORNER);
                }
                else if (j == WIDTH - 1)
                {
                    addch(ACS_URCORNER);
                }
                else
                {
                    addch(ACS_HLINE);
                }
            }
            else if (i == HEIGHT - 1)
            {
                if (j == 0)
                {
                    addch(ACS_LLCORNER);
                }
                else if (j == WIDTH - 1)
                {
                    addch(ACS_LRCORNER);
                }
                else
                {
                    addch(ACS_HLINE);
                }
            }
            else if (i == y && j == x)
            {
                addch(character);
            }
            else
            {
                if (j == 0 || j == WIDTH - 1)
                {
                    addch(ACS_VLINE);
                }
                else
                {
                    addch(' ');
                }
            }
        }
        addch('\n');
    }
    while (1)
    {
        move = getch();
        if (move == KEY_LEFT)
        {
            y -= 1;
        }
        else if (move == KEY_RIGHT)
        {
            y += 1;
        }
        else if (move == KEY_UP)
        {
            x -= 1;
        }
        else if (move == KEY_DOWN)
        {
            x += 1;
        }
        // if ESC is pressed, end the program
        else if (move == 113 || move == 81)
        {
            break;
        }
        mvprintw(y, x, &character);
        refresh();
    }
    // refresh();
    endwin();
}