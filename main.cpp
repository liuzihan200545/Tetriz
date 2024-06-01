#include<iostream>
#include"terminal.h"
#include<thread>
#include<chrono>
#include"utils.h"
using namespace std::chrono;

void init(){
    tc::hide_cursor();
}

void loop(){
    int i = 1;
    while (true)
    {
        tc::move_to(1,1);
        std::cout << "FPS:" << ut::fps() << std::endl;
        tc::move_to(i++%30,10);
        tc::set_back_color(15);
        std::cout<<"  "<<std::flush;
        std::this_thread::sleep_for(100ms);
        tc::reset_color();
        tc::clean_screen();
    }
}

void exit(){
    tc::show_cursor();
    tc::reset_color();
}

int main(){
    init();
    loop();
    exit();
    return 0;
}