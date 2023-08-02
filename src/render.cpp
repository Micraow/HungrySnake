#include "render.h"
#include<ncurses.h>
void greeting(){
    /**在屏幕中间显示一行“HungrySnake",正下方显示按钮样式的"Enter"**/
    mvprintw(LINES/2-1,COLS/2-10,"HungrySnake");
    mvprintw(LINES/2,COLS/2-10,"Enter");
    refresh();
}

void init(){
    initscr();            /* Start curses mode        */
    raw();                /* Line buffering disabled  */
    noecho();             /* Don't echo() while we do getch */
    /**让窗口能自动调整大小**/
    resize_term(0,0);
    /**设置窗口大小**/
    resize_term(LINES,COLS);
    start_color();
    /**设置背景颜色**/

    curs_set(0);

    /**设置刷新时间**/
    nodelay(stdscr, TRUE);
}

int getachar(){
    return getchar();
}