#ifndef SCHEDULER_TASK_H
#define SCHEDULER_TASK_H

#include "ITask.h"
#include <iostream>
#include <unistd.h>
class Task : public ITask {
public:
    Task(const char* name, useconds_t time, int cycle, const char* msg);
    ~Task();
    void run();
    unsigned long getNextRunPeriod();

private:
    const char* m_name;
    useconds_t m_time_iter;
    int m_cycles;
    const char* m_msg;
};


#endif //SCHEDULER_TASK_H
