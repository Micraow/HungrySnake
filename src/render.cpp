#include "render.h"
#include <ncurses.h>

void init()
{
    initscr(); /* Start curses mode        */
    raw();     /* Line buffering disabled  */
    noecho();  /* Don't echo() while we do getch */
    /**让窗口能自动调整大小**/
    resize_term(0, 0);
    /**设置窗口大小**/
    resize_term(LINES, COLS);
    start_color();

    curs_set(0);

    /**设置刷新时间**/
    nodelay(stdscr, TRUE);
}

int getachar()
{
    return getchar();
}

void withbackground(int num, char *string, bool bold)
{
    if (bold == false)
    {
        attron(COLOR_PAIR(num));
        printw(string);
        attroff(COLOR_PAIR(num));
    }
    else
    {
        attron(COLOR_PAIR(num) | A_BOLD);
        printw(string);
        attroff(COLOR_PAIR(num) | A_BOLD);
    }
}

void greeting()
{
    /**在屏幕中间显示一行“HungrySnake",正下方显示按钮样式的"Enter"**/
    move(LINES / 2 - 1, COLS / 2 - 10);
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,COLOR_WHITE);
    withbackground(1,"HungrySnake",false);
    move(LINES/2,COLS/2-8);
    withbackground(2,"<Enter>",true);
    refresh();
}
