#include <ncurses/ncurses.h>

int main()
{
    initscr();

    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    addch(ACS_ULCORNER);
                }
                else if (j == 29)
                {
                    addch(ACS_URCORNER);
                }
                else
                {
                    addch(ACS_HLINE);
                }
            }
            else if (i == 39)
            {
                if (j == 0)
                {
                    addch(ACS_LLCORNER);
                }
                else if (j == 29)
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
                if (j == 0 || j == 29)
                {
                    addch(ACS_VLINE);
                }
                else
                {
                    addch(ACS_BLOCK);
                }
            }
        }
        addch('\n');
    }
    getch();
    endwin();
    return 0;
}