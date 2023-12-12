#include <ncurses/ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

/* Windows*/
//  #include <ncurses/ncurses.h>
//  #include <windows.h>

#define HEIGHT 40
#define WIDTH 2 * HEIGHT

void menuprint()
{
    mvprintw(2, 10, "Welcome to find the Diamonds!");
    mvprintw(5, 10, "Start Game");       // option 1
    mvprintw(7, 10, "View Leaderboard"); // option 2
    mvprintw(9, 10, "How to Play");      // option 3
    mvprintw(11, 10, "Exit Game");       // option 4
}

void howToPlay()
{
    mvprintw(2, 20, "Welcome to Find the DIAMONDS!");
    mvprintw(4, 5, "The aim of the game is to capture as many diamonds ");
    addch(ACS_DIAMOND);
    addstr(" as possible.");
    mvprintw(5, 18, "And to avoid the explosive stars ");
    attron(COLOR_PAIR(1));
    addch(ACS_PLUS);
    attroff(COLOR_PAIR(1));
    addch('.');
    mvprintw(7, 28, "Movement");
    mvprintw(9, 20, "To move, use the arrow keys.");

    mvprintw(11, 28, "Game Play");
    mvprintw(13, 10, "You gain points by collecting diamonds ");
    addch(ACS_DIAMOND);
    addstr(" which score 10 points per diamond.");
    mvprintw(14, 10, "As you get a higher score the difficulty increases:");
    mvprintw(15, 15, " - either by spawning more explosive stars per diamond captured");
    mvprintw(16, 15, " - or you movement speed increases");

    mvprintw(20, 18, "Press any key to exit the program");
    getch();
}

void showLeaderboard()
{
    int spacer = 4, counter = 0;
    char row[20];
    FILE *leaderboard;
    mvprintw(2, 10, "LEARDERBOARD");
    leaderboard = fopen("leaderboard.txt", "r");
    if (leaderboard == NULL)
    {
        mvprintw(4, 10, "No scores yet");
    }
    else
    {
        while (!feof(leaderboard))
        {
            fgets(row, 20, leaderboard);
            mvprintw(spacer + 2 * counter, 10, "%s", row);
            counter++;
        }
        fclose(leaderboard);
    }
    mvprintw(spacer + 2 * (counter + 1), 18, "Press any key to exit the program");
    getch();
}

void initializematrix(int *m)
{ // This generates the matrix for the board.
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
{ // Prints the matrix
    for (size_t i = 0; i < HEIGHT; i++)
    {
        for (size_t j = 0; j < WIDTH; j++)
        {
            addch(*((board + i * WIDTH) + j));
        }
        addch('\n');
    }
}
void information(int lvl, int score, int lives)
{
    mvprintw(HEIGHT + 1, 5, "Level: %d", lvl);
    mvprintw(HEIGHT + 1, 25, "Score: %d", score);
    mvprintw(HEIGHT + 1, 45, "Lives: %d", lives);
    mvprintw(HEIGHT + 1, WIDTH - 25, "Press q to quit");
}

int collisionScore(int x, int y, int *board, int score)
{
    if (*((board + y * WIDTH) + x) == ACS_DIAMOND)
    {
        score += 10;
    }
    return score;
}

int collisionDanger(int x, int y, int *board, int lives)
{
    if (*((board + y * WIDTH) + x) == ACS_PLUS)
    {
        lives--;
    }
    return lives;
}

void dangerGenerator(int *board, int lvl)
{
    int counter = lvl / 2 + 1;
    int x, y;
    for (size_t i = 0; i < counter; i++)
    {
        x = rand() % (WIDTH - 2) + 1;
        y = rand() % (HEIGHT - 2) + 1;
        if (*((board + y * WIDTH) + x) == ' ')
        {
            *((board + y * WIDTH) + x) = ACS_PLUS;
        }
        else
        {
            i--;
        }
    }
}

void diamondGenerator(int *board)
{
    int x, y;
    for (size_t i = 0; i < 1; i++)
    {
        x = rand() % (WIDTH - 2) + 1;
        y = rand() % (HEIGHT - 2) + 1;
        if (*((board + y * WIDTH) + x) == ' ')
        {
            *((board + y * WIDTH) + x) = ACS_DIAMOND;
        }
        else
        {
            i--;
        }
    }
}

void drawPlayer(int x, int y, int *board, int xdir, int ydir)
{
    if (xdir == 1)
    {
        *((board + y * WIDTH) + x) = ACS_LTEE;
        if (x + 1 >= 1)
        {
            *((board + y * WIDTH) + x + 1) = ACS_RARROW;
        }
    }
    else if (xdir == -1)
    {
        *((board + y * WIDTH) + x) = ACS_RTEE;
        if (x - 1 >= 1)
        {
            *((board + y * WIDTH) + x - 1) = ACS_LARROW;
        }
    }
    else if (ydir == 1)
    {
        *((board + y * WIDTH) + x) = ACS_TTEE;
        if (y + 1 >= 1)
        {
            *((board + (y + 1) * WIDTH) + x) = ACS_DARROW;
        }
    }
    else
    {
        *((board + y * WIDTH) + x) = ACS_BTEE;
        if (y - 1 >= 1)
        {
            *((board + (y - 1) * WIDTH) + x) = ACS_UARROW;
        }
    }
}

void clearPlayer(int x, int y, int *board, int xdir, int ydir)
{
    if (xdir == 1)
    {
        *((board + y * WIDTH) + x) = ' ';
        if (x + 1 >= 1)
        {
            *((board + y * WIDTH) + x + 1) = ' ';
        }
    }
    else if (xdir == -1)
    {
        *((board + y * WIDTH) + x) = ' ';
        if (x - 1 >= 1)
        {
            *((board + y * WIDTH) + x - 1) = ' ';
        }
    }
    else if (ydir == 1)
    {
        *((board + y * WIDTH) + x) = ' ';
        if (y + 1 >= 1)
        {
            *((board + (y + 1) * WIDTH) + x) = ' ';
        }
    }
    else
    {
        *((board + y * WIDTH) + x) = ' ';
        if (y - 1 >= 1)
        {
            *((board + (y - 1) * WIDTH) + x) = ' ';
        }
    }
}

void addLeaderboard(int score)
{
    clear();
    char name[20];
    FILE *leaderboard;
    leaderboard = fopen("leaderboard.txt", "a");
    mvprintw(HEIGHT / 3, WIDTH / 2, "Enter you name:");
    scanw("%s", name);
    fprintf(leaderboard, "%s %d \n", name, score);
    fclose(leaderboard);
}

/* Game Plan
Levels
Level 1 base 1 danger marker per food
Level 2 2 danger markers per food
level 3 speed up 1.06
level 4 3 danger markers per food
level 5 speed up 1.13
level 6 4 danger markers per food
level 7 speed up 1.25
level 8 5 danger markers per food
level 9 speed up 1.5
level 10 shrink board - not implememnted

The board that is used is contained in a matrix
To check for if a space is available only need to check if the square is occupied by the diamond.
Speed can be increased via the movement and direction of the character ( a T shape followed by an arrow).
Danger markers are generated randomly and will always be a unique location, as I can check against the matrix for positions.

*/

void game()
{
    int playerx = WIDTH / 2, playery = HEIGHT / 2;
    int directionx = 0, directiony = -1;
    int board[HEIGHT][WIDTH];
    int key;
    int Xmax = WIDTH - 2;
    int Ymax = HEIGHT - 2;
    int level = 1;
    int score = 0;
    int lives = 3;
    int prevscore = score;
    bool caught = TRUE;
    float speed[] = {1, 10625, 1.125, 1.25, 1.5, 2};
    char name[20];
    initializematrix((int *)board);
    srand(time(NULL));

    while (lives > 0 && key != 113 && key != 81)
    {
        clear();
        drawPlayer(playerx, playery, (int *)board, directionx, directiony);
        draw((int *)board);
        information(level, score, lives);
        clearPlayer(playerx, playery, (int *)board, directionx, directiony);
        if (prevscore != score)
        {
            caught = TRUE;
            prevscore = score;
        }
        while (caught)
        {
            diamondGenerator((int *)board);
            dangerGenerator((int *)board, level);
            caught = FALSE;
        }

        key = getch();
        switch (key)
        { // Logic for direction
        case KEY_LEFT:
            if (playerx > 1)
            {
                playerx -= speed[level / 2];
                score = collisionScore(playerx, playery, (int *)board, score);
                lives = collisionDanger(playerx, playery, (int *)board, lives);
                board[playery][playerx] = ACS_RTEE;
                directionx = -1;
                directiony = 0;
                if (playerx - 1 > 1)
                {
                    board[playery][playerx - 1] = ACS_LARROW;
                }
            }
            else
            {
                // lose life due to collision with wall
                playerx = WIDTH / 2;
                playery = HEIGHT / 2;
                lives -= 1;
            }

            break;

        case KEY_RIGHT:
            if (playerx < WIDTH - 2)
            {
                playerx += speed[level / 2];
                score = collisionScore(playerx, playery, (int *)board, score);
                lives = collisionDanger(playerx, playery, (int *)board, lives);
                board[playery][playerx] = ACS_LTEE;
                directionx = 1;
                directiony = 0;
                if (playerx + 1 < WIDTH - 2)
                {
                    board[playery][playerx + 1] = ACS_RARROW;
                }
            }
            else
            {
                // lose life due to collision with wall
                playerx = WIDTH / 2;
                playery = HEIGHT / 2;
                lives -= 1;
            }
            break;

        case KEY_UP:
            if (playery > 1)
            {
                playery -= speed[level / 2];
                score = collisionScore(playerx, playery, (int *)board, score);
                lives = collisionDanger(playerx, playery, (int *)board, lives);
                board[playery][playerx] = ACS_BTEE;
                directionx = 0;
                directiony = -1;
                if (playery - 1 > 1)
                {
                    board[playery - 1][playerx] = ACS_UARROW;
                }
            }
            else
            {
                // lose life due to collision with wall
                playerx = WIDTH / 2;
                playery = HEIGHT / 2;
                lives -= 1;
            }
            break;

        case KEY_DOWN:
            if (playery < HEIGHT - 2)
            {
                playery += speed[level / 2];
                score = collisionScore(playerx, playery, (int *)board, score);
                lives = collisionDanger(playerx, playery, (int *)board, lives);
                board[playery][playerx] = ACS_TTEE;
                directionx = 0;
                directiony = 1;
                if (playery + 1 < HEIGHT - 2)
                {
                    board[playery + 1][playerx] = ACS_DARROW;
                }
            }
            else
            {
                // lose life due to collision with wall
                playerx = WIDTH / 2;
                playery = HEIGHT / 2;
                lives -= 1;
            }
            break;
        case 'q':
            endwin();
        case 'Q':
            endwin();
        default:
            break;
        }
        playerx += directionx;
        playery += directiony;
        if (playerx > WIDTH - 1 || playerx < 1)
        {
            playerx = WIDTH / 2;
            playery = HEIGHT / 2;
            lives -= 1;
        }
        else if (playery > HEIGHT - 1 || playery < 1)
        {
            playerx = WIDTH / 2;
            playery = HEIGHT / 2;
            lives -= 1;
        }

        clearPlayer(playerx, playery, (int *)board, directionx, directiony);
        score = collisionScore(playerx, playery, (int *)board, score);
        lives = collisionDanger(playerx, playery, (int *)board, lives);

        timeout(speed[level / 2] * 100);
        refresh();

        clear();
    }
    if (key != 'q' && key != 'Q')
    {
        mvprintw(HEIGHT / 3, WIDTH / 2, "You have lost");
        addLeaderboard(score);
        showLeaderboard();
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
        menuprint();
        mvaddch(optiony, 35, ACS_LARROW);
        menu_press = getch();
        if (menu_press == KEY_DOWN)
        {
            mvprintw(optiony, 35, " ");
            optiony += 2;
        }
        else if (menu_press == KEY_UP)
        {
            mvprintw(optiony, 35, " ");
            optiony -= 2;
        }
        else if (menu_press == 10)
        {
            selected = (optiony - 5) / 2 + 1;
        }

        if (optiony < 5)
        {
            optiony = 5;
        }
        else if (optiony > 11)
        {
            optiony = 11;
        }

        refresh();
    }
    clear();

    if (selected == 4)
    {
        endwin();
    }
    else if (selected == 3)
    {
        howToPlay();
        endwin();
    }
    else if (selected == 2)
    {
        showLeaderboard();
        endwin();
    }
    else
    {
        game();
        endwin();
    }
    endwin();
    return 0;
}