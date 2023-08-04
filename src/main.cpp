#include "render.h"

/**借助snake.cpp里提供的蛇的对象，使用ncurses库完成一款贪吃蛇的游戏**/

using namespace std;

int main()
{
    /** 每次输出后记得refresh,并设置等待**/
    init();
    /**欢迎**/
    greeting();
    while (getachar() != 13)
    {
        greeting();
    }
    clean();
    Myrefresh();
    WINDOW *win = startFrame();
    Myrefresh();
    playground playarea = playground(win);
    snake P1 = snake(0, 0, 2);
    playarea.initSnake(P1);
    getchar();
}
