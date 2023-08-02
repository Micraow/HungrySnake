#include <ncurses.h>

using namespace std;

int main()
{   
    /** 每次输出后记得refresh,并设置等待**/
    initscr();            /* Start curses mode        */
    raw();                /* Line buffering disabled  */
    noecho();             /* Don't echo() while we do getch */


}