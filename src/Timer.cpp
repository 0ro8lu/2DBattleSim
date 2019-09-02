#include "Timer.h"

std::chrono::system_clock::time_point Timer::_epoch = std::chrono::high_resolution_clock::now();

double Timer::getCurrentTime(){
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _epoch).count() / 1000.0;
}