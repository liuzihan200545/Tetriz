#include<iostream>
#include"terminal.h"
#include<thread>
#include<chrono>
#include"utils.h"
#include"draw.h"
using namespace std::chrono;

void init(){
    tc::clean_screen();
    tc::hide_cursor();
    dw::window(1,1,9,6,std::string("Hold"));
    dw::window(1,10,12,22,std::string("Tetriz"));
    dw::window(7,1,9,16,std::string("Status"));
    dw::window(19,22,8,4,std::string("Info"));
    dw::window(1,22,8,18,std::string("Next"));
}

void loop(){
    int i = 1;
    while (true)
    {
        tc::move_to(8,4);
        std::cout << "FPS:" << ut::fps() << std::endl;
        tc::move_to(9,10);
        tc::set_back_color(15);
        std::cout<<"  "<<std::flush;
        std::this_thread::sleep_for(100ms);
        tc::reset_color();
        //tc::clean_screen();
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