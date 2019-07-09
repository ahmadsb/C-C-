
#ifndef SCHEDULER_TIME_H
#define SCHEDULER_TIME_H

#include <sys/time.h>
#include <iostream>

class Time {

public:
    Time();
    size_t now();
    size_t get_time();
    void set_time(size_t time);
    Time &operator+=(size_t time);
    bool operator<(Time const &a);

private:
    static const int convert_hours_to_min = 60;
    static const int convert_min_to_seconds = 60;
    static const int convert_second_to_mille = 1000;
    static const int convert_mille_to_micro= 1000;
    unsigned long m_time;
};


#endif 
