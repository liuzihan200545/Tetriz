#include "utils.h"
#include <chrono>
using namespace std::chrono;

int ut::fps()
{
    static auto start = steady_clock::now();
    static auto end = start;
    static int frame_count = 0;
    static int fps = 0;

    end = std::chrono::steady_clock::now();
    frame_count ++;
    if(end - start > 1s){
        fps = frame_count;
        frame_count = 0;
        start = end;
    }
    return fps;
}