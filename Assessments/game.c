#include <ncurses/ncurses.h>

int main()
{

    initscr();
    // Drawing screen

    const int WIDTH = 60;
    const int HEIGHT = 40;
    char board[50][40];
    int player[2][3] = {{1, 1}, {0, 1, 3}};

    for (size_t i = 0; i < HEIGHT; i++)
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
    getch();
    endwin();
    return 0;
}