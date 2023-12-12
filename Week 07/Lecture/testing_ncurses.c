#include <ncurses/ncurses.h>

int main()
{
    int ch;
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    printw("Type any character to see it in bold\n");
    while (1)
    {
        ch = getch();
        if (ch == KEY_LEFT)
            printw("Left arrow is pressed\n");
        else if (ch == KEY_RIGHT)
            printw("Right arrow is pressed\n");
        else if (ch == KEY_UP)
            printw("Up arrow is pressed\n");
        else if (ch == KEY_DOWN)
            printw("Down arrow is pressed\n");
        // if ESC is pressed, end the program
        else if (ch == 27)
            break;
    }
    // getch();
    endwin();
    return 0;
}