#include <iostream>

#include "person.h"
#include "logger.h"
#include "singleton.h"



#include <iostream>
#include <pthread.h>
#include <unistd.h>

using std::cout;
using std::endl;
void* callGetInstance(void* p)
{
    Singleton<Logger> *s =(Singleton<Logger> *) Singleton<Logger>::getInstance();
    Logger l2 = s->get();
    Logger::print();
    return s;
}

int main() {

   

  cout << "Hello, World!" << endl;
   static const size_t THREADS_NUM = 10;

   unsigned int i = 0;
   pthread_t idP;

   for(; i < THREADS_NUM; ++i)
   {
       pthread_create(&idP, NULL, callGetInstance, NULL);//? once 
   }

   



   return 0;
}