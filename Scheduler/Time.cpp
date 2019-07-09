#include "Time.h"

Time::Time() : m_time(0) {}


size_t Time::get_time() {
    return m_time;
}

void Time::set_time(size_t time) {
    m_time = time;
}

size_t Time::now() {
    struct timeval s_tv;
    gettimeofday(&s_tv, NULL);
    long int ms = s_tv.tv_sec * 1000 + s_tv.tv_usec / 1000;
    return ms * 1000;
}

Time &Time::operator+=(unsigned long time) {
    m_time += time;
    return *this;
}

bool Time::operator<(Time const &other) {
    return m_time < other.m_time;
}

