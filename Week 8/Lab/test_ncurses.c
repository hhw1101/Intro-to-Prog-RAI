#include <ncurses.h>

int main(){
    //Initialize Ncurses
    initscr();

    //Print text and refresh
    printw("Hello, NCurses!");
    refresh();

    getch();
    endwin();
    return 0;
    
}