
#ifndef PRICE_H
#define PRICE_H
#include<iostream>
#include<math.h>
// static int numberDigits(int size)  {
//     return pow(10, size);
// }

// trick provide culc. size in cop. time by recursia
template<size_t SIZE>
class Divider{
    public: 
        enum{
                value = 10 * Divider<SIZE - 1>::value
        };
};

template<>
class Divider<0>
{
    public:
            enum{
                value = 1
            };
};


// defualt template 
/*
    if I want to assignment defualt type to class T
    shuold be put the class T='int' in final line
    e.g => template< unsigned int size,class T = int >
    note: size does in time comp. not time run so possible to use it 
          to init stat const T SIZE = size // it is right 
        but if ctor(..., int size); here does work becaus this in time
*/
template<unsigned int size, class T = int  >
class Price{
        
    template< unsigned int S, class F >
    friend inline bool operator==(const Price<S,F>& pthis , const Price<S,F>& rhs);

    template< unsigned int S, class F >
    friend inline bool operator!=(const Price<S,F>& pthis , const Price<S,F>& rhs);
    
    template< unsigned int S, class F >
    friend inline bool operator>(const Price<S,F>& pthis , const Price<S,F>& rhs);

    template< unsigned int S, class F >
    friend inline bool operator<(const Price<S,F>& pthis , const Price<S,F>& rhs);

    template< unsigned int S, class F >
    friend inline bool operator>=(const Price<S,F>&& pthis , const Price<S,F>&& rhs);

    template< unsigned int S, class F >
    friend inline bool operator<=(const Price<S,F>& pthis , const Price<S,F>& rhs);

    template< unsigned int S, class F>
    friend std::ostream& operator<<(std::ostream& os, const Price<S,F>& p);  
public:
    static const std::size_t DOLLAR_CENT = Divider<size>::value;
    explicit Price(T dollar = 0);
    Price(T dollar , T cents );
    inline Price<size, T>& operator++();//++p
    inline Price<size, T>& operator--();//--p
    // put const for functio : because case : i++ = 7; don't works assigment
    inline const Price<size, T> operator++(int num);//p++
    inline const Price<size, T> operator--(int num);//p--

    //unary -
    inline Price<size, T> operator-();

    inline Price<size, T> operator+(const Price<size, T>& rhs);
    inline Price<size, T> operator-(const Price<size, T>& rhs);
    inline Price<size, T> operator*(const Price<size, T>& rhs);
    inline Price<size, T> operator/(const Price<size, T>& rhs);
    inline Price<size, T> operator%(const Price<size, T>& rhs);

    inline Price<size, T>& operator+=(const Price<size, T>& rhs);
    inline Price<size, T>& operator-=(const Price<size, T>& rhs);
    inline Price<size, T>& operator*=(const Price<size, T>& rhs);
    inline Price<size, T>& operator/=(const Price<size, T>& rhs);
    inline Price<size, T>& operator%=(const Price<size, T>& rhs);

    // assignment= (int)
    inline Price<size, T>& operator=(T num);

    //Support casting to double
    inline operator double();
    inline T getDollarCentes()const;

private:
    // phase 5 to prevent the code redundancy in function Becuase the tempalte create classes 
    // with others types so, we have more from funciton 
    // const int DOLLAR_CENT = numberDigits(size);
    T m_price;
    // possible to accsess to variable static const in file.cpp
    // if it is here in scope of private
    // access to it by Price::DOLLAR_CENT
    


};
typedef Price<2,int> priceTwoInt;
typedef Price<3,short> priceTwoShort;


template<unsigned int size, class T  >
inline T Price<size, T>::getDollarCentes() const{
    return DOLLAR_CENT;
}


template<unsigned int size, class T >
inline Price<size, T>::Price(T dollar ):m_price (dollar*getDollarCentes()){}

template<unsigned int size, class T   >
inline Price<size, T>::Price(T dollar , T cents ):m_price(dollar* getDollarCentes() + cents){
    if(dollar < 0)
        m_price = (dollar*getDollarCentes() - cents);
}

template<unsigned int size, class T >
std::ostream& operator<<(std::ostream& os, const Price<size , T>& p){  
    T  cent =p.m_price % p.getDollarCentes();
    // if(cent >=0 && cent <= p.getDollarCentes() ){
    //     std::string temp= "";
    //     for(int i =0 ; i< p.getDollarCentes(); i++)
    //         temp+="0";
    //     os<< p.m_price/p.getDollarCentes() <<"."<<temp<< abs(p.m_price % p.getDollarCentes());
    // }
    // else
        os<< p.m_price/p.getDollarCentes() <<"."<< abs(p.m_price % p.getDollarCentes());
    return os;  
}  
// ==== operators returns Price& =====
template<unsigned int size, class T   >
inline Price<size, T>& Price<size, T>::operator+=(const Price<size, T>& rhs){
    m_price += rhs.m_price;
    return *this;
}

template<unsigned int size, class T>
inline Price<size, T>& Price<size, T>::operator-=(const Price<size, T>& rhs){
    m_price -= rhs.m_price;
    return *this;
}

template<unsigned int size, class T>
inline Price<size, T>& Price<size, T>::operator*=(const Price<size, T>& rhs){
     m_price *= rhs.m_price;
    return *this;
}

template<unsigned int size, class T>
inline Price<size, T>& Price<size, T>::operator/=(const Price<size, T>& rhs){
     m_price /= rhs.m_price;
    return *this;
}

template<unsigned int size, class T>
inline Price<size, T>& Price<size, T>::operator%=(const Price<size, T>& rhs){
     m_price %= rhs.m_price;
    return *this;
}
// ============
template<unsigned int size, class T>
inline bool operator==(const Price<size, T>& pthis ,const Price<size, T>& rhs){
    if(pthis.m_price == rhs.m_price)
        return true;
    return false;
}

template<unsigned int size, class T>
inline bool operator!=(const Price<size, T>& pthis, const Price<size, T>& rhs){
    return !(pthis == rhs);
}

template<unsigned int size, class T>
inline bool operator>(const Price<size, T>& pthis, const Price<size, T>& rhs){
    if(pthis.m_price > rhs.m_price)
        return true;
    return false;
}

template<unsigned int size, class T>
inline bool operator<(const Price<size, T>& pthis, const Price<size, T>& rhs){
    if (pthis == rhs || pthis > rhs)
        return true;
    return false;
}

template<unsigned int size, class T>
inline bool operator>=(const Price<size, T>& pthis, const Price<size, T>& rhs){
    return !(pthis < rhs);
}

template<unsigned int size, class T>
inline bool operator<=(const Price<size, T>& pthis, const Price<size, T>& rhs){
    return !(pthis > rhs);
}
//==========

template<unsigned int size, class T>
inline Price<size, T>& Price<size, T>::operator++(){//++price
    m_price+=getDollarCentes();
    return *this;
}

template<unsigned int size, class T>
inline Price<size, T>& Price<size, T>::operator--(){ //--price
    m_price-=getDollarCentes();
    return *this;
}

template<unsigned int size, class T>
inline const Price<size, T> Price<size, T>::operator++(int num){
    Price<size, T> res(m_price);
    ++(*this);
    return res;
}

template<unsigned int size, class T>
inline const Price<size, T> Price<size, T>::operator--(int num){
    Price<size,T> res(m_price);
    --(*this);
    return  res;
 }

// ===============================
template<unsigned int size, class T>
inline Price<size, T> Price<size, T>::operator+(const Price<size, T>& rhs){
   Price<size, T> temp (m_price/getDollarCentes());
   temp.m_price += rhs.m_price;
   return temp;
}

template<unsigned int size, class T>
inline Price<size, T> Price<size, T>::operator-(const Price<size, T>& rhs){
    Price<size, T> temp (m_price/getDollarCentes());
    temp.m_price -= rhs.m_price;
    return temp;
}

template<unsigned int size, class T>
inline Price<size, T> Price<size, T>::operator*(const Price<size, T>& rhs){

   Price<size, T> temp (m_price/getDollarCentes());
   temp.m_price *= rhs.m_price;
   temp.m_price/= getDollarCentes();

   return temp;
}

template<unsigned int size, class T>
inline Price<size, T> Price<size, T>::operator/(const Price<size, T>& rhs){
    Price<size, T> temp (m_price/getDollarCentes());
    temp.m_price /= rhs.m_price;
    temp.m_price *= getDollarCentes();
    return temp;
}

template<unsigned int size, class T>
inline Price<size, T> Price<size, T>::operator%(const Price<size, T>& rhs){
    Price<size, T> temp(m_price/getDollarCentes());
    temp.m_price %= rhs.m_price;
    return temp;
}

template<unsigned int size, class T>
inline Price<size, T> Price<size, T>::operator-(){
    return Price<size, T>( -(m_price)/getDollarCentes(),(m_price% getDollarCentes()) );
}

template<unsigned int size, class T>
inline Price<size, T>& Price<size, T>::operator=( T num){
    m_price = num * getDollarCentes();
    return *this;
}
template<unsigned int size, class T>
inline Price<size, T>::operator double(){
    double res = (double)m_price/getDollarCentes();
    return res;
}

#endif