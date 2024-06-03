#pragma once
#include"tetromino.h"

namespace gm
{
    extern bool running;

    extern int row,col;

    extern Tetromino cur;

    void quit();

    void init();

    void rotate();

    void left();

    void right();

    void down();




} // namespace game
