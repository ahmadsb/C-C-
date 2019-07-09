
#ifndef PRICE_H
#define PRICE_H
#include<iostream>

class Price{
    friend inline bool operator==(const Price& pthis , const Price& rhs);
    friend inline bool operator!=(const Price& pthis , const Price& rhs);
    friend inline bool operator>(const Price& pthis , const Price& rhs);
    friend inline bool operator<(const Price& pthis , const Price& rhs);
    friend inline bool operator>=(const Price& pthis , const Price& rhs);
    friend inline bool operator<=(const Price& pthis , const Price& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Price& p);  
public:
    // explicit Price(int dollar = 0);
    /* 
       if no put key word = explicit in ctor
       in main : Price p = 3; works becuase:
       3 convert to Price(3)
       Price p = Prcie(3) copy ctor
       //explicit wroks when the ctor gets one parameters
       //but if there is defualt value in param. explicit should be 
        e.g  explicit Price(int dollar , int cents );
    */
    explicit Price(int dollar = 0);
    Price(int dollar , int cents );

    inline Price& operator++();//++p
    inline Price& operator--();//--p
    // put const for functio : because case : i++ = 7; don't works assigment
    inline const Price operator++(int num);//p++
    inline const Price operator--(int num);//p--

    //unary -
    inline Price operator-();

    inline Price operator+(const Price& rhs);
    inline Price operator-(const Price& rhs);
    inline Price operator*(const Price& rhs);
    inline Price operator/(const Price& rhs);
    inline Price operator%(const Price& rhs);

    inline Price& operator+=(const Price& rhs);
    inline Price& operator-=(const Price& rhs);
    inline Price& operator*=(const Price& rhs);
    inline Price& operator/=(const Price& rhs);
    inline Price& operator%=(const Price& rhs);

    // copy ctor
    /*
    const Price& returns -->
    e.g p1 = p2 = p3; compiler works from right to left
    p3 returns const Price& and assingment to p2
    p2 return const Price& and assingment to p1
    here p1 not const Price&  
    but with trick (p1=p2) = p3; here not work so , use in return Price& not const
    but if there no pointer in ctor no need to implement copy ctor
    */
    inline Price& operator=(const Price& rhs);

    // assignment= (int)
    inline Price& operator=(int num);

    //Support casting to double
    inline operator double();
private:
    int m_price;
    // possible to accsess to variable static const in file.cpp
    // if it is here in scope of private
    // access to it by Price::DOLLAR_CENT
    static const int DOLLAR_CENT = 100;


};
// ==== operators returns Price& =====
inline Price& Price::operator+=(const Price& rhs){
    m_price += rhs.m_price;
    return *this;
}
inline Price& Price::operator-=(const Price& rhs){
    m_price -= rhs.m_price;
    return *this;
}
inline Price& Price::operator*=(const Price& rhs){
     m_price *= rhs.m_price;
    return *this;
}
inline Price& Price::operator/=(const Price& rhs){
     m_price /= rhs.m_price;
    return *this;
}
inline Price& Price::operator%=(const Price& rhs){
     m_price %= rhs.m_price;
    return *this;
}
// ============
inline bool operator==(const Price& pthis ,const Price& rhs){
    if(pthis.m_price == rhs.m_price)
        return true;
    return false;
}
inline bool operator!=(const Price& pthis, const Price& rhs){
    return !(pthis == rhs);
}
inline bool operator>(const Price& pthis, const Price& rhs){
    if(pthis.m_price > rhs.m_price)
        return true;
    return false;
}
inline bool operator<(const Price& pthis, const Price& rhs){
    if (pthis == rhs || pthis > rhs)
        return true;
    return false;
}
inline bool operator>=(const Price& pthis, const Price& rhs){
    return !(pthis < rhs);
}
inline bool operator<=(const Price& pthis, const Price& rhs){
    return !(pthis > rhs);
}
// ========

inline Price& Price::operator=(const Price& rhs){
    m_price = rhs.m_price;
    return *this;
}
inline Price& Price::operator++(){//++price
    m_price+=DOLLAR_CENT;
    return *this;
}
inline Price& Price::operator--(){ //--price
    m_price-=DOLLAR_CENT;
    return *this;
}
inline const Price Price::operator++(int num){
    Price res(m_price);
    ++(*this);
    return res;
}
inline const Price Price::operator--(int num){
    Price res(m_price);
    --(*this);
    return  res;
 }

// ===============================
inline Price Price::operator+(const Price& rhs){
   Price temp = Price(this->m_price);
   temp += rhs;
   return temp;
}
inline Price Price::operator-(const Price& rhs){
     Price temp = Price(this->m_price);
   temp -= rhs;
   return temp;
}
inline Price Price::operator*(const Price& rhs){
   Price temp = Price(this->m_price);
   temp *= rhs;
   return temp;
}
inline Price Price::operator/(const Price& rhs){
    Price temp = Price(this->m_price);
    temp /= rhs;
   return temp;
}
inline Price Price::operator%(const Price& rhs){
    Price temp = Price(this->m_price);
    temp %= rhs;
    return temp;
}
inline Price Price::operator-(){
    return Price( -(m_price)/DOLLAR_CENT,(m_price% DOLLAR_CENT) );
}

inline Price& Price::operator=( int num){
    Price temp = Price(num/DOLLAR_CENT, num%DOLLAR_CENT);
    *this += temp;
    return *this;
}

inline Price::operator double(){
    double res = (double)m_price/DOLLAR_CENT;
    return res;
}

#endif