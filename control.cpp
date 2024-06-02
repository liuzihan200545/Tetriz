#include "control.h"
#include "define.h"
#include "game.h"

namespace gm
{
    std::map<char, std::function<void()>> command_func = {
        {KEY_Q, command_quit},
        {KEY_W, command_rotate},
        {KEY_S, command_down},
        {KEY_A, command_left},
        {KEY_D, command_right}
    };


    char command;

    char getch(){
        char c;
        struct termios old,cur;
        tcgetattr(0,&cur);
        old = cur;
        cfmakeraw(&cur);
        tcsetattr(0,0,&cur);
        c = getchar();
        tcsetattr(0,0,&old);
        return c;

    }

    void key_event(){
        while(running){
            command = getch();
            command_func[command]();
        }
    }

    void start_listener()
    {
        std::thread t(gm::key_event);
        t.detach();
    }

    void command_quit()
    {
        quit();
    }

    void command_rotate()
    {
        rotate();
    }

    void command_left()
    {
        left();
    }

    void command_right()
    {
        right();
    }

    void command_down()
    {
        down();
    }

} // namespace gm
