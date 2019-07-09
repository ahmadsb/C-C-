#ifndef NUMRIC_LIMIT_H
#define NUMRIC_LIMIT_H
#include "priceTemplate.h"
namespace std{
    template <>// for spicalized 
    template<unsigned int SIZE, class T>
    class std::numeric_limits< Price<SIZE,T> >{// spcae for c98
        public:
            static Price<SIZE,T> max(){
                return Price<SIZE,T>(0,std::numeric_limits<T>::max()));
            }
            static Price<SIZE,T> min(){
                return Price<SIZE,T>(0,std::numeric_limits<T>::min()));
            }

    };
}
#endif