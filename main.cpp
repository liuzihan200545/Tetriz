#include"terminal.h"
#include"control.h"
#include"utils.h"
#include"draw.h"
#include"define.h"
#include"game.h"

void init(){
    tc::clean_screen();
    gm::start_listener();
    gm::init();
}

void loop(){
    while (gm::running)
    {
        tc::hide_cursor();
        dw::window(1,1,9,6,std::string("Hold"));
        dw::window(1,10,12,22,std::string("Tetriz"));
        dw::window(7,1,9,16,std::string("Status"));
        dw::window(19,22,8,4,std::string("Info"));
        dw::window(1,22,8,18,std::string("Next"));

        tc::move_to(10,4);
        std::cout << "FPS:" << ut::fps() << std::endl;

        tc::move_to(gm::row,ut::b_to_c(gm::col));
        //tc::set_back_color(15);
        //std::cout<<"  "<<std::flush;

        dw::tetromino(gm::cur,gm::row,gm::col);
        std::cout<<std::flush;
        tc::reset_color();
        std::this_thread::sleep_for(10ms);


        
    }
}

void exit(){
    tc::clean_screen();
    tc::show_cursor();
    tc::reset_color();
}

int main(){
    init();
    loop();
    exit();
    return 0;
}