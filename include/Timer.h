#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
public:
    static double getCurrentTime();

private:
    static std::chrono::system_clock::time_point _epoch;
};

#endif // TIMER_H