#include "draw.h"
#include "terminal.h"
#include "utils.h"
#include "tetromino.h"

/**
 *  	0	1	2	3	4	5	6	7	8	9	A	B	C	D	E	F
U+250x	─	━	│	┃	┄	┅	┆	┇	┈	┉	┊	┋	┌	┍	┎	┏
U+251x	┐	┑	┒	┓	└	┕	┖	┗	┘	┙	┚	┛	├	┝	┞	┟
U+252x	┠	┡	┢	┣	┤	┥	┦	┧	┨	┩	┪	┫	┬	┭	┮	┯
U+253x	┰	┱	┲	┳	┴	┵	┶	┷	┸	┹	┺	┻	┼	┽	┾	┿
U+254x	╀	╁	╂	╃	╄	╅	╆	╇	╈	╉	╊	╋	╌	╍	╎	╏
U+255x	═	║	╒	╓	╔	╕	╖	╗	╘	╙	╚	╛	╜	╝	╞	╟
U+256x	╠	╡	╢	╣	╤	╥	╦	╧	╨	╩	╪	╫	╬	╭	╮	╯
U+257x	╰	╱	╲	╳	╴	╵	╶	╷	╸	╹	╺	╻	╼	╽	╾	╿
**/

inline int block2col(int b){
    return 2*b-1;
}

namespace dw
{
    

    void window(int top, int left, int width, int height, std::string title)
    {
        for(int r = 0;r<height;r++){
            tc::move_to(top+r,block2col(left));
            for(int c = 0;c<width;c++){
                if(r == 0){
                    if(c == 0){
                        std::cout<<" ┌";
                    }
                    else if(c == width - 1){
                        std::cout<<"┐ ";
                    }
                    else{
                        std::cout<<"──";
                    }
                }
                else if(r == height-1){
                    if(c == 0){
                        std::cout<<" └";
                    }
                    else if(c == width - 1){
                        std::cout<<"┘ ";
                    }
                    else{
                        std::cout<<"──";
                    }
                }
                else{
                    if(c == 0){
                        std::cout<<" │";
                    }
                    else if(c == width - 1){
                        std::cout<<"│ ";
                    }
                    else{
                        std::cout<<"  ";
                    }
                }
            }
        }
        tc::move_to(top,block2col(left)+(width*2-title.length())/2);
        std::cout<<title<<std::endl;
    }

    void tetromino(gm::Tetromino &t, int top, int left)
    {
        tc::move_to(top,ut::b_to_c(left));
        for(int i = 0;i<t.size();i++){
            tc::move_to(top+i,ut::b_to_c(left));

            for(int j = 0;j<t.size();j++){
                if(t[i][j]>0){
                    tc::set_back_color((int)gm::tetro_color[t[i][j]]);
                    std::cout<<"  ";
                }
                else{
                    tc::reset_color();
                    std::cout<<"  ";
                }
            }
        }
    }

} // namespace dw
    