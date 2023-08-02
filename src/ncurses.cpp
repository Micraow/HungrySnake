#include <ncurses.h>
using namespace std;

int main(int argc, char const *argv[])
{
    initscr();
    cbreak();
    noecho();

    return 0;
}