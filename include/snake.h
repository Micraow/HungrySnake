#include<list>
using namespace std;
/// @brief direction 枚举类型（up,left,down,right) 逆时针-1 顺时针+1
enum direction
{
    up,
    left,
    down,
    right
};
/// @brief 描述一条蛇的后面那个状态
class snake
{
private:
    int x, y, z, length;
    direction direct=right;
    int speed;
    /// @brief 存储身体所在的座标点，不含头,0索引位置即头后面那个
    list<int*> body;
    int tmp[2]={x,y};


public:
    /// @brief 蛇的构建函数
    /// @param x 以屏幕中央为原点的x
    /// @param y 以屏幕中央为原点的y
    /// @param length 蛇长 含头
    /// @param speed 行进速度，初始2
    snake(int x, int y ,int length, int speed);
    /// @brief 行进
    void march();
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
    int speedUp(int step);
    /// @brief 获取当前蛇头的位置
    /// @return int[2] {x,y}
    int* getPos(){
        int pos[]={x,y};
        return pos;
    }

    
};

snake::snake(int x, int y ,int length , int speed ){
        this->x=x;
        this->y=y;
        this->length=length;
        this->speed=speed;
    };