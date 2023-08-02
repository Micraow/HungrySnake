#include "snake.h"
#include <algorithm>
using namespace std;


direction snake::getDirection()
{
    return direct;
}

void snake::march()
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
    delete last;
    body.pop_back();
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
inline list<int *> snake::getBody()
{
    return body;
}

inline bool snake::bump()
{
    bool bump = (find(body.begin(), body.end(), head) != body.end());
    return bump;
}

