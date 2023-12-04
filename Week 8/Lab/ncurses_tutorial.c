#include <ncurses/ncurses.h>

void moving_and_sleeping() 
{ 
    int row = 10; 
    int col = 0; 
 
    curs_set(0); 
 
    for(char c = 65; c <= 90; c++) 
    { 
        move(row++, col++); 
        addch(c); 
        refresh(); 
        napms(100); 
    } 
 
    row = 10; 
    col = 3; 
 
    for(char c = 97; c <= 122; c++) 
    { 
        mvaddch(row++, col++, c); 
        refresh(); 
        napms(100); 
    } 
 
    curs_set(1); 
 
    addch('\n'); 
} 

void print_char_table(){ 
   // print name tab symbol tab 
    printw("\n\nSymbol\tName\n"); 
    addch(ACS_ULCORNER);addch('\t');printw("ACS_ULCORNER\t"); 
    addch(ACS_LLCORNER);addch('\t');printw("tACS_LLCORNER\t"); 
    addch(ACS_URCORNER);addch('\t');printw("tACS_URCORNER\t"); 
    addch(ACS_LRCORNER);addch('\t');printw("tACS_LRCORNER\t"); 
    addch(ACS_RTEE);addch('\t');printw("tACS_RTEE\t"); 
    addch(ACS_LTEE);addch('\t');printw("tACS_LTEE\t"); 
    addch(ACS_BTEE);addch('\t');printw("tACS_BTEE\t"); 
    addch(ACS_TTEE);addch('\t');printw("tACS_TTEE\t"); 
    addch(ACS_HLINE);addch('\t');printw("tACS_HLINE\t"); 
    addch(ACS_VLINE);addch('\t');printw("tACS_VLINE\t"); 
    addch(ACS_PLUS);addch('\t');printw("ACS_PLUS\t"); 
    addch(ACS_S1);addch('\t');printw("ACS_S1\t\t"); 
    addch(ACS_S9);addch('\t');printw("ACS_S9\t\t"); 
    addch(ACS_DIAMOND);addch('\t');printw("ACS_DIAMOND\n"); 
    addch(ACS_CKBOARD);addch('\t');printw("ACS_CKBOARD\t"); 
    addch(ACS_DEGREE);addch('\t');printw("ACS_DEGREE\t"); 
    addch(ACS_PLMINUS);addch('\t');printw("ACS_PLMINUS\t"); 
    addch(ACS_BULLET);addch('\t');printw("ACS_BULLET\t"); 
    addch(ACS_LARROW);addch('\t');printw("ACS_LARROW\t"); 
    addch(ACS_RARROW);addch('\t');printw("ACS_RARROW\t"); 
    addch(ACS_DARROW);addch('\t');printw("ACS_DARROW\t"); 
    addch(ACS_UARROW);addch('\t');printw("ACS_UARROW\t"); 
    addch(ACS_BOARD);addch('\t');printw("ACS_BOARD\t"); 
    addch(ACS_LANTERN);addch('\t');printw("ACS_LANTERN\t"); 
    addch(ACS_BLOCK);addch('\t');printw("ACS_BLOCK\t"); 
    addch(ACS_S3);addch('\t');printw("ACS_S3\t\t"); 
    addch(ACS_S7);addch('\t');printw("ACS_S7\t\t"); 
    addch(ACS_LEQUAL);addch('\t');printw("ACS_LEQUAL\t"); 
    addch(ACS_GEQUAL);addch('\t');printw("ACS_GEQUAL\t"); 
    addch(ACS_PI);addch('\t');printw("ACS_PI\t\t"); 
    addch(ACS_NEQUAL);addch('\t');printw("ACS_NEQUAL\t"); 
    addch(ACS_STERLING);addch('\t');printw("ACS_STERLING\t"); 
} 
  
void colouring() 
{ 
    if(has_colors()) 
    { 
        if(start_color() == OK) 
        { 
            init_pair(1, COLOR_YELLOW, COLOR_RED); 
            init_pair(2, COLOR_MAGENTA, COLOR_CYAN); 
            init_pair(3, COLOR_GREEN, COLOR_BLACK); 
 
            attrset(COLOR_PAIR(1)); 
            addstr("Yellow and red\n\n"); 
            attroff(COLOR_PAIR(1)); 
 
            attrset(COLOR_PAIR(2)); 
            addstr("Magenta and cyan\n\n"); 
            attroff(COLOR_PAIR(2)); 
 
            attrset(COLOR_PAIR(3)); 
            addstr("Green and black\n\n"); 
            attroff(COLOR_PAIR(3)); 
            refresh(); 
        } 
        else 
        { 
 
            addstr("Cannot start colours\n"); 
            refresh(); 
        } 
    } 
    else 
    { 
        addstr("Not colour capable\n"); 
        refresh(); 
    } 
}

int main(){
    //Initialize Ncurses
    initscr();

    // //Print text and refresh
    // printw("Hello, NCurses!");
    // addstr("\n------Ncurses tutorial----------\n"); 
    // addstr("Use of addch function for printing character: "); 
    // addch('a'); 
    // printw("\nUse of printw for printing numbers: %d, %f\n", 11,11.5 );
    // refresh();

    // // moving_and_sleeping();
    // // print_char_table();
    // colouring();
    // getch();


    int ch; 
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
 
        // refresh(); 
    }
    endwin();
    return 0;
    
}