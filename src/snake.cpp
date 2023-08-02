#include "snake.h"
using namespace std;

direction snake::getDirection()
{
    return direct;
}

void snake::march()
{
    switch (direct)
    {
    case up:
        y = y + speed;
        break;
    case down:
        y = y - speed;
        break;
    case left:
        x = x - speed;
        break;
    case right:
        x = x + speed;
        break;

    default:
        break;
    }
}

int snake::speedUp(int step)
{
    speed = speed + step;
    return speed;
}

int snake::getLength()
{
    return length;
}

void snake::turnLeft()
{
    direct = (direction)(direct - 1);
}

void snake::turnRight()
{
    direct = (direction)(direct + 1);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
