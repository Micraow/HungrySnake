#include <list>
using namespace std;
/// @brief direction 枚举类型（up,left,down,right) 逆时针-1 顺时针+1
enum direction
{
    up,
    left,
    down,
    right
};
/// @brief 描述一条蛇的后面那个状态,初始状态下蛇是这个样子的(x-1,y)(x,y)->
class snake
{
private:
    int x, y, z, length;
    direction direct = right;
    // int speed;
    int init[2] = {x - 1, y};
    /// @brief 存储身体所在的座标点，不含头,0索引位置即头后面那个
    list<int *> body;
    int head[2] = {x, y};

public:
    /// @brief 蛇的构建函数
    /// @param x 以屏幕中央为原点的x
    /// @param y 以屏幕中央为原点的y
    /// @param length 蛇长 含头
    /// @param speed 行进速度，初始2
    snake(int x, int y, int length);
    /// @brief 行进
    int *march();
    /// @brief 左转
    void turnLeft();
    /// @brief 右转
    void turnRight();
    /// @brief 获得蛇的长度
    /// @return int 蛇身长，包括头
    int getLength();
    /// @brief 获得当前朝向
    /// @return direction 枚举类型（up,left,down,right)
    direction getDirection();
    /// @brief 让蛇的速度加快
    /// @param step
    /// @return 加速后速度
    /**
    int speedUp(int step);
    /// @brief 获取当前蛇头的位置
    /// @return int[2] {x,y}
    **/
    int *getPos()
    {

        return head;
    }
    list<int *> getBody();
    /// @brief 判断是否碰撞到身体
    /// @return bool true / false
    bool bump();
};

snake::snake(int x, int y, int length)
{
    this->x = x;
    this->y = y;
    this->length = length;
    // this->speed=speed;
    body.push_front(init);
};

class ticket
{
private:
public:
    /// @brief 表示要多久蛇才能走一次单位0.1s
    float tickets;
    snake *target;
    ticket(snake target);
    void start();
    ~ticket();
    int getTime();
};

ticket::ticket(snake target)
{
    this->target = &target;
}

ticket::~ticket()
{
    delete this->target;
}