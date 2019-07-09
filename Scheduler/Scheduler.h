//
// Created by ahmad on 17/12/2018.
//
#include <iostream>
#include <vector>
#include <algorithm>

#include <utility> // std::pair, std::make_pair      // std::pair, std::make_pair
#include "Time.h"
#include "SharedPtr.h"
#include "Task.h"

#include <unistd.h>


#ifndef SCHEDULER_SCHEDULER_H
#define SCHEDULER_SCHEDULER_H
typedef std::pair<Time*, SharedPtr<ITask> > Task_Time;
bool operator<  (const Task_Time& lhs, const Task_Time& rhs);

class Scheduler {
public:
    Scheduler();

    ~Scheduler();

    void add(SharedPtr<ITask> task);


    void run();

private:
    void remove(Task_Time &t);
    //prevent copying
    Scheduler(Scheduler const &);

    Scheduler &operator=(Scheduler const &);

    std::vector<Task_Time> tasks;

};


#endif //SCHEDULER_SCHEDULER_H
