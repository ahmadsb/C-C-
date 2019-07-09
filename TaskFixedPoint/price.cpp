#include"price.h"
#include<math.h>
Price::Price(int dollar ):m_price(dollar){}
Price::Price(int dollar , int cents ):m_price(dollar*DOLLAR_CENT + cents){
    if(dollar < 0)
        m_price = (dollar*DOLLAR_CENT - cents);
}
std::ostream& operator<<(std::ostream& os, const Price& p){  
    // os<<p.m_price/100.0;
    os<< p.m_price/Price::DOLLAR_CENT <<"."<< abs(p.m_price % Price::DOLLAR_CENT);
    return os;  
}  
