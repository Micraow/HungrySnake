#include "snake.h"
#include <algorithm>
#include <ctime>
using namespace std;

direction snake::getDirection()
{
    return direct;
}

int *snake::march()
{
    body.push_front(head);

    switch (direct)
    {
    case up:
        y++;
        break;
    case down:
        y--;
        break;
    case left:
        x--;
        break;
    case right:
        x++;
        break;

    default:
        break;
    }
    /**
     * 搞错了，忘了头不在body里
    int* newbody=NULL;
    newbody=new int[2];
    *newbody={x,y};
    body.push_front(newbody);
    **/
    head[0] = x;
    head[1] = y;
    int *last = body.back();
    int needClean = *last;
    delete last;
    body.pop_back();
    return &needClean;
}
/**
int snake::speedUp(int step)
{
    speed = speed + step;
    return speed;
}
**/

inline int snake::getLength()
{
    return length;
}

inline void snake::turnLeft()
{
    direct = (direction)(direct - 1);
}

inline void snake::turnRight()
{
    direct = (direction)(direct + 1);
}
list<int *> snake::getBody()  //WHY:加了inline就编译不过了？
{
    return body;
}

inline bool snake::bump()
{
    bool bump = (find(body.begin(), body.end(), head) != body.end());
    return bump;
}
void ticket::start()
{
    int lastTime = 0;
    while (1)
    {
        int now = getTime();
        if (now - lastTime > tickets)
        {
            target->march();
            lastTime = now;
        }
    }
}

/// @brief 返回一个时间，单位0.1s
int ticket::getTime()
{
    return clock() / (CLOCKS_PER_SEC / 10);
}