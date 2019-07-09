#include "Scheduler.h"

Scheduler::Scheduler() {
    std::make_heap(tasks.begin(), tasks.end());
}


void Scheduler::add(SharedPtr<ITask> task) {
    Time *time = new Time;
    time->set_time(task.get()->getNextRunPeriod() + time->now());

    Task_Time t = std::make_pair(time, task);
    tasks.push_back(t);
    std::push_heap(tasks.begin(), tasks.end());
}


Scheduler::~Scheduler() {
    unsigned i;
    for (i = 0; i < tasks.size(); i++)
        delete (tasks[i].first);
}

bool operator<(const Task_Time &lhs, const Task_Time &rhs) {
    return lhs.first->get_time() > rhs.first->get_time();
}

void Scheduler::run() {
    Time t0;
    while (tasks.size() > 0) {
        Task_Time current_task = tasks.front();
        long delta = current_task.first->get_time() - t0.now();
        if (delta > 0) {
            std::cout << "Scheduler: i need to sleep for " << delta / 1000 << std::endl;
            usleep((useconds_t) delta);
        }
        std::pop_heap(tasks.begin(), tasks.end());
        tasks.pop_back();
        current_task.second.get()->run();
        // here i send the task to add function and destroy the time no matter what
        // ! because in add, new one will be created
        if (current_task.second.get()->getNextRunPeriod() > 0)
            add(current_task.second);

        remove(current_task);
    }
}

void Scheduler::remove(Task_Time &t) {
    delete t.first;
}
