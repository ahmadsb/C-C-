

#include "Task.h"

Task::Task(const char* name, useconds_t time, int cycle, const char* msg): m_name(name), m_time_iter(time), m_cycles(cycle), m_msg(msg){
    std::cout << "creating: " << m_name << " task" << std::endl;
}

Task::~Task() {
    std::cout << "destroying: " << m_name << " task" << std::endl;
}

void Task::run() {
    std::cout << m_name << ": " << "is running for " << m_time_iter << " m_seconds, the task is "
    << m_msg << " and has " << m_cycles-- << " more left" << std::endl;
    usleep(m_time_iter * 1000);
}

unsigned long Task::getNextRunPeriod() {
    if (m_cycles == 0)
        return 0;
    return m_time_iter * 1000 ;
}
