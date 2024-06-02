#pragma once
#include<termios.h>

namespace gm
{
    extern char command;

    char getch();

    void key_event();
    
    void start_listener();

    //键盘命令函数
    void command_quit();
    void command_rotate();
    void command_left();
    void command_right();
    void command_down();
} // namespace game control
