#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct
{
    int x;
    int y;
} Item;

typedef struct
{
    int x;
    int y;
} Obstruction;

void draw_rect(int x1, int y1, int width, int height)
{
    start_color();
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(2));

    // Draw the top and bottom sides of the rectangle
    for (int x = 0; x < width; x++)
    {
        mvaddch(y1, x + x1, ACS_HLINE);              // Top side
        mvaddch(y1 + height - 1, x + x1, ACS_HLINE); // Bottom side
    }

    // Draw the left and right sides of the rectangle
    for (int y = 0; y < height; y++)
    {
        mvaddch(y + y1, x1, ACS_VLINE);             // Left side
        mvaddch(y + y1, x1 + width - 1, ACS_VLINE); // Right side
    }

    // Draw the corners
    mvaddch(y1, x1, ACS_ULCORNER);                          // Upper-left corner
    mvaddch(y1, x1 + width - 1, ACS_URCORNER);              // Upper-right corner
    mvaddch(y1 + height - 1, x1, ACS_LLCORNER);             // Lower-left corner
    mvaddch(y1 + height - 1, x1 + width - 1, ACS_LRCORNER); // Lower-right corner

    attroff(COLOR_PAIR(2));
    refresh();
}

void obstcoords(int xmax, int ymax, int numberObs, Obstruction obstruction[])
{
    for (int i = 0; i < numberObs; i++)
    {
        obstruction[i].x = rand() % (xmax - 5) + 3;
        obstruction[i].y = rand() % (ymax - 5) + 3;
    }
}

void itemcoords(int xmax, int ymax, Item *item)
{
    int r_x = rand() % (xmax - 5) + 3;
    int r_y = rand() % (ymax - 5) + 3;
    item->x = r_x;
    item->y = r_y;
}

void drawObs(Obstruction obstruction[], int numberObs)
{
    for (int i = 0; i < numberObs; i++)
    {
        mvaddch(obstruction[i].y, obstruction[i].x, ACS_BLOCK);
    }
}

void drawItem(Item *item)
{
    mvaddch(item->y, item->x, ACS_PI);
}

int check_collisionOBS(int x, int y, int index, Obstruction obstruction[])
{
    if (x == obstruction[index].x && y == obstruction[index].y)
    {
        return true;
    }
    return false;
}
int check_collisionITEM(int x, int y, Item *item)
{
    if (x == item->x && y == item->y)
    {
        return true;
    }
    return false;
}

void score_card(int x1, int y1, int score, int level, int lives)
{
    // Use fixed position coordinates for the scoreboard
    int scorePosX = 10;     // X coordinate for scoreboard
    int scorePosY = y1 - 5; // Y coordinate just below the game area

    mvprintw(scorePosY, scorePosX, "   Score: %d     Lives: %d      Level: %d        press q to quit", score, lives, level);
}

void main_menu()
{
    mvprintw(2, 50, "RESCUE MISSION GAME");
    mvprintw(4, 50, "Single Game Mode");
    mvprintw(6, 50, "VS Enemy Game Mode");
    mvprintw(8, 50, "How to play?");
}

void statistics(int x, int y, int score, int level, int lives)
{
    mvprintw(y, x, "Score: %d", score);
    mvprintw(y, x + 15, "Lives: %d", lives);
    mvprintw(y, x + 30, "Level: %d", level);
    mvprintw(y, x + 45, "Press 'q' to quit");
}

int main()
{
    int ch;
    int x = 10, y = 10;
    int x_max = 100, y_max = 20;
    int x_arr, y_arr;
    int level = 1;
    int baseSpeed = 250;
    int speedIncrease = 5;
    int speed = baseSpeed + (level - 1) * speedIncrease;
    bool collided = false;
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0); // Hide the cursor

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    int key_press = 0;
    int initValue = 4;
    int choice;
    while (key_press != 32)
    {
        main_menu();
        mvaddch(initValue, 45, ACS_RARROW);
        key_press = getch();
        if (key_press == KEY_DOWN)
        {
            mvprintw(initValue, 45, " ");
            initValue += 2;
        }
        else if (key_press == KEY_UP)
        {
            mvprintw(initValue, 45, " ");
            initValue -= 2;
        }
        if (initValue < 4)
        {
            initValue = 4;
        }
        else if (initValue > 8)
        {
            initValue = 8;
        }
        refresh();
    }
    clear();
    int score = 0;
    int lives = 3;
    // score_card(x1, y1 + 5, score, lives);

    timeout(speed);
    int directX = 0, directY = 0;
    int prevX, prevY; // Variables to store the previous position of the diamond
    int x2 = x, y2 = y;
    int prevX2, prevY2; // Variables to store the previous position of the arrow
    int counter = 1;
    chtype arrow;
    int obstrCount = 2;
    Item item;
    itemcoords(x_max, y_max, &item);
    Obstruction obstruction[50];
    obstcoords(x_max, y_max, obstrCount, obstruction);
    int directionX = 0, directionY = 0;

    while (lives > 0)
    {
        draw_rect(0, 0, x_max, y_max);
        drawItem(&item);
        if (score == 0)
        {
            obstrCount = ((score + 10) / 10) * 2;
        }

        drawObs(obstruction, obstrCount);
        statistics(5, y_max + 2, score, level, lives);
        ch = getch();
        int new_x = x, new_y = y;
        if (ch == 'q')
        {
            goto end;
        }
        switch (ch)
        {
        case KEY_LEFT:
            new_x = x - 1;
            arrow = ACS_LARROW; // Arrow pointing left
            directionX = -1;
            directionY = 0;
            break;
        case KEY_RIGHT:
            new_x = x + 1;
            arrow = ACS_RARROW; // Arrow pointing right
            directionX = 1;
            directionY = 0;
            break;
        case KEY_UP:
            new_y = y - 1;
            arrow = ACS_UARROW; // Arrow pointing up
            directionY = -1;
            directionX = 0;
            break;
        case KEY_DOWN:
            new_y = y + 1;
            arrow = ACS_DARROW; // Arrow pointing down
            directionY = 1;
            directionX = 0;
            break;
        }

        new_x += directionX;
        new_y += directionY;
        timeout(speed);

        if (check_collisionITEM(x, y, &item))
        {
            score = score + 10;
            if ((score - 10) % 30 == 0 && (score - 10) != 0)
            {
                level = level + 1;
                speed = speed - 50;
            }
            refresh();
            clear();
            itemcoords(x_max, y_max, &item);

            if (score >= 100)
            {
                // If points are 10 or more, empty the obstacles list
                obstrCount = 0;
                level = level + 1;
                obstcoords(x_max, y_max, obstrCount, obstruction);
            }
            else
            {
                // Otherwise, increase the number of obstacles
                obstrCount = score / 10 * 2;
                obstcoords(x_max, y_max, obstrCount, obstruction);
            }
        }

        for (int i = 0; i < obstrCount; i++)
        {
            if (check_collisionOBS(x, y, i, obstruction))
            {
                clear();
                obstcoords(x_max, y_max, obstrCount, obstruction);
                lives = lives - 1;
                clear();
                x = 1;
                y = 1;
                char message[] = "You lost a life!";
                clear();
                mvprintw(LINES / 2, (COLS - strlen(message)) / 2, "%s", message);
                refresh();

                clear();

                break;
            }
        }
        if (new_x > 0 && new_x < x_max && new_y > 0 && new_y < y_max)
        {
            collided = false;
            // Clear previous lantern and arrow
            move(y, x);
            addch(' ');
            move(y_arr, x_arr); // Increase spacing
            addch(' ');

            // Update to new position
            x = new_x;
            y = new_y;
        }
        else if (!collided)
        {
            // Player has touched the wall, lose a life
            collided = true;
            lives = lives - 1;
            clear();
            x = 1;
            y = 1;
            char message[] = "You lost a life!";
            clear();
            mvprintw(LINES / 2, (COLS - strlen(message)) / 2, "%s", message);
            refresh();
            sleep(2); // Display for 2 seconds
            clear();
        }
        if (lives == 0)
        {
            clear();
            mvprintw(LINES / 2, (COLS - strlen("You have been defeated!")) / 2, "You have been defeated!");
            refresh();
            sleep(2);
            goto endscreen; // Exit the loop if lives are exhausted
        }
        // Draw lantern and arrow at new position

        y_arr = y + directionY;
        x_arr = x + directionX * 2;
        move(y, x);
        addch(ACS_LANTERN);
        move(y_arr, x_arr); // Increase spacing
        addch(arrow);
        refresh();
    }
endscreen:
    clear()
    echo();
    curs_set(TRUE);
    char playerName[100];
    mvprintw(10, 10, "Enter your name for the leaderboard: ");
    nodelay(stdscr, FALSE);
    getnstr(playerName, 99);
    FILE *leaderboard = fopen("leaderboard.txt", "a");
    fprintf(leaderboard, "%s %d \n", playerName, score); // Write name and score
    fclose(leaderboard);                                 // Close the file
    FILE *leaderboard2 = fopen("leaderboard.txt", "r");
    noecho();
    curs_set(FALSE);
    clear();
    mvprintw(2, 50, "GAME OVER");
    mvprintw(4, 50, "You have scored %d points congrats, %s!", score, playerName);
    mvprintw(6, 50, "The current scoreboard is: ");

    char line[256];
    int lineCount = 0;
    while (fgets(line, sizeof(line), leaderboard2))
    {
        mvprintw(8 + lineCount, 50, "%s", line);
        lineCount++;
    }
    fclose(leaderboard2); // Close the leaderboard2 file

    refresh();
    nodelay(stdscr, FALSE);
    getch();

end:
    endwin();
    return 0;
}