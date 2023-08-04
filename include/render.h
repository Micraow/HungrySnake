#include <ncurses.h>
#include "snake.h"

#define MAXX 40
#define MAXY 40
// 以下是头的形状
#define UP 'M'
#define DOWN 'U'
#define LEFT 'E'
#define RIGHT 'D'
// 身体的形状
#define BODY 'O'

void greeting();
void init();
int getachar();
void withbackground(int num, char *string, bool bold);
void clean();
void Myrefresh();
WINDOW *startFrame();
void drawSnake();
int getcenterx(WINDOW *Playwin);
int getcentery(WINDOW *Playwin);
class playground
{
private:
    WINDOW *win;
    int halfX;
    int halfY;

public:
    playground(WINDOW *Playwin);
    ~playground();
    void initSnake(snake Snake);
    void drawHead(snake Snake);
    void drawBody(snake Snake);
    void cleanChanged(); // 清除蛇身离开的区域
    int XtoCol(int X);
    int YtoLine(int Y);
};

playground::playground(WINDOW *Playwin)
{
    this->win = Playwin;
    this->halfX = getcenterx(this->win);
    this->halfY = getcentery(this->win);
}

playground::~playground()
{
    delwin(this->win);
}
