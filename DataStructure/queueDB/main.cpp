#include<iostream>
#include"queue.h"

int main()
{
    queue<int> q(10);
    
    q.push(1);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.pop();
    std::cout << q.front() <<std::endl;
    return 0;
}