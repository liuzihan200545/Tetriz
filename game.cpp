#include"game.h"
#include"tetromino.h"

namespace gm
{
    bool running;
    int row,col;
    
    Tetromino cur;

    void init()
    {
        row = 2;
        col = 15;
        running = true;
        cur = O;
    }

    void quit()
    {
        running = false;
    }

    void rotate()
    {
        cur = rotate(cur);
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
