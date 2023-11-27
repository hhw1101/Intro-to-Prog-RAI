#include <ncurses/ncurses.h>
#include <stdio.h>

int main(){
    int grade;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    printw("Enter your grade: \n");
    grade = getch();
    printw("\nYour grade is %c", grade);
    getch();

    return 0;
}
