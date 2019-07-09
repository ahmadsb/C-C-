#include <iostream>
#include "Scheduler.h"
#include "SharedPtr.h"
#include <sys/time.h>



int main() {
    const char* task_name0 = "Programing in C";
    const char* task_name1 = "Programing in Python";
    const char* task_name2 = "Taking a brake";
    const char* task_name3 = "Push ups";

    const char* task_name0_msg = "working on shared pointer";
    const char* task_name1_msg = "working on telegram bot";
    const char* task_name2_msg = "watching TV";
    const char* task_name3_msg = "hard push ups";


    ITask* t1 = new Task(task_name0, 50, 4, task_name0_msg);
    SharedPtr<ITask> task1(t1);

    ITask* t2 = new Task(task_name1, 100, 7, task_name1_msg);
    SharedPtr<ITask> task2(t2);

    ITask* t3 = new Task(task_name2, 50, 1, task_name2_msg);
    SharedPtr<ITask> task3(t3);

    ITask* t4 = new Task(task_name3, 600, 2, task_name3_msg);
    SharedPtr<ITask> task4(t4);


    Scheduler s ;

    s.add(task1);
    s.add(task2);
    s.add(task3);
    s.add(task4);

    s.run();

    return 0;
}