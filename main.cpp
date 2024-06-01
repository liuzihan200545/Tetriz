#include<iostream>
#include"terminal.h"
#include<thread>
#include<chrono>
using namespace std::chrono;

int main(){
    tc::hide_cursor();
    int i = 1;
    while (true)
    {
        tc::move_to(i++,10);
        tc::set_back_color(15);
        std::cout<<"  "<<std::flush;
        std::this_thread::sleep_for(500ms);
        tc::reset_color();
        tc::clean_screen();
    }
    
    return 0;
}