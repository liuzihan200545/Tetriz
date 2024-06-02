#include"game.h"

namespace gm
{
    bool running;
    int row,col;

    void init()
    {
        row = 2;
        col = 15;
        running = true;
    }

    void quit()
    {
        running = false;
    }

    void rotate()
    {
        row--;
    }

    void left()
    {
        col-=2;
    }

    void right()
    {
        col+=2;
    }

    void down()
    {
        row++;
    }

} // namespace gm
