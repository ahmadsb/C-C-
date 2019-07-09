#include <iostream>
#include <stdexcept>
#include "NumericLimit.h"
#include "priceTemplate.h"
std::string ones[]={"","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
std::string teens[]={"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
std::string tens[]= {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void longConstructorPositive();
void checkLongLong();
void checkShort();
void checkInt();
void longOperatorPlusPositive();
void longConstructorNegative();
void longOperatorMinusPositive();

void checkLong() {
    std::cout <<"********** long Constructor Positive ********** \n";
    longConstructorPositive();
    std::cout <<"********** long Constructor negative ********** \n";
    longConstructorNegative();

    std::cout <<"********** Plus Positive ********** \n";
    longOperatorPlusPositive();
//    longOperatorPlusNegative();

    std::cout <<"********** Minus Positive ********** \n";
    longOperatorMinusPositive();
//    longOperatorMinusNegative();
//
//    longOperatorModuloPositive();
//    longOperatorModuloNegative();
//
//    longOperatorMultiplePositive();
//    longOperatorMultipleNegative();
//
//    longOperatorDividePositive();
//    longOperatorDividNegative();
//
//    longOperatorEqualPositive();
//    longOperatorEqualNegative();
//
//    longOperatorPluseEqualPositive();
//    longOperatorPluseEqualNegative();
//
//    longOperatorMinusEqualPositive();
//    longOperatorMinusEqualNegative();
//
//
//    longOperatorMultEqualPositive();
//    longOperatorMultEqualNegative();
//
//    longOperatorDivEqualPositive();
//    longOperatorDivEqualNegative();
//
//
//    longOperatorModEqualPositive();
//    longOperatorModEqualNegative();
//
//    longUniMinusOperatorPositive();
//    longUniMinusOperatorNegative();
//
//
//    longOperatorPostPlusPlusPositive();
//    longOperatorPostPlusPlusNegative();
//
//
//    longOperatorPrePlusPlusPositive();
//    longOperatorPrePlusPlusNegative();
//
//
//    longOperatorPostMinusMinusPositive();
//    longOperatorPostMinusMinusNegative();
//
//    longOperatorPreMinusMinusPositive();
//    longOperatorPreMinusMinusNegative();
//
//
//    longOperatorCastLongPositive();
//    longOperatorCastLongNegative();
}

void longOperatorMinusPositive() {
    Price<5,long> p0;
    Price<5,long> p1(20);
    Price<5,long> p2(5, 10);
    Price<5,long> p3(5, 10);
    std::cout << "p0 = "<< p0 ;
    std::cout << "p1 = "<< p1 ;
    std::cout << "p2 = "<< p2 ;
    std::cout << "p3 = "<< p3 ;

    std::cout << "p1 - p2 - p3 should be -0.20 and => answer = "<< p1-p2-p3 ;
//    std::cout << "p1 + p2 + p3 should be 0.20 and => answer = "<< p1+p2+p3 ;
    std::cout << "\n\tDone!\n";
}

void longConstructorNegative() {
    try {
        Price<6,long> p3(-5, -5);
        std::cout << "Failed!\n";

    } catch(std::invalid_argument& e) {
        std::cout <<"Cents is -5, error " <<  e.what() << std::endl;
        std::cout<< "Passed"<< std::endl;
    }
    std::cout << "\n\tDone!\n";
}

void longOperatorPlusPositive() {
    Price<5,long> p0;
    Price<5,long> p1(-10);
    Price<5,long> p2(5, 10);
    Price<5,long> p3(5, 10);
    Price<5,long> p4(0, 12345);
    std::cout << "p0 = "<< p0 ;
    std::cout << "p1 = "<< p1 ;
    std::cout << "p2 = "<< p2 ;
    std::cout << "p3 = "<< p3 ;
    std::cout << "p4 = "<< p4 ;

    std::cout << "p0 + p2 + p3 should be 10.20 and => answer = "<< p0+p2+p3 ;
    std::cout << "p1 + p2 + p3 should be 0.20 and => answer = "<< p1+p2+p3 ;
    std::cout << "p4 + p2  should be 5.12355 and => answer = "<< p4+p2;
//    std::cout << "p4 + p2  should be 5.12355 and => answer = "<< p1+p2;
    std::cout << "\n\tDone!\n";
}

void longConstructorPositive() {
    Price<5,long> p;
    std::cout << "m_price = 0 and => p = "<< p ;

    Price<2,long> p0(5, 56);
    std::cout << "m_price = 5.56  and => p = "<< p0 ;


    Price<5,long> p1(5, 10);
    std::cout << "m_price = 5.10 and => p = "<< p1 ;


    Price<4,long> p2(-5, 10);
    std::cout << "m_price = -5.10 and => p = "<< p2 ;
    // std::cout<<"my string price is"<<p2.asString();
    std::cout << "\n\tDone!\n";
}
std::string nameForNumber (long number) {
    if (number < 10) {
        return ones[number];
    } else if (number < 20) {
        return teens [number - 10];
    } else if (number < 100) {
        return tens[number / 10] + ((number % 10 != 0) ? " " + nameForNumber(number % 10) : "");
    } else if (number < 1000) {
        return nameForNumber(number / 100) + " hundred" + ((number % 100 != 0) ? " " + nameForNumber(number % 100) : "");
    } else if (number < 1000000) {
        return nameForNumber(number / 1000) + " thousand" + ((number % 1000 != 0) ? " " + nameForNumber(number % 1000) : "");
    } else if (number < 1000000000) {
        return nameForNumber(number / 1000000) + " million" + ((number % 1000000 != 0) ? " " + nameForNumber(number % 1000000) : "");
    } else if (number < 1000000000000) {
        return nameForNumber(number / 1000000000) + " billion" + ((number % 1000000000 != 0) ? " " + nameForNumber(number % 1000000000) : "");
    }
    return "error";
}

std::string convertNumber (long number,long cents)
{
    return nameForNumber(number)+" and "+nameForNumber(cents) + " cents";
}
std::string makeMoney(Price<2,long> price)
{
    // std::string numstr = price.asString();
    // std::size_t len = numstr.length();
    // std::size_t afterpoint = price.getPrecision();
}

int main() {
   checkLong();
   checkInt();
   checkLongLong();
   checkShort();


    // std::cout << "\n" << nameForNumber(1234) << std::endl;
//    intConstructorPositive();
//    intConstructorNegative();
//
//    shortConstructorPositive();
//    shortConstructorNegative();
//
//
//    longLongConstructorPositive();
//    longLongConstructorNegative();



//
//    FixedPoint<long long, 8> p(1458000001, 123451678);
//    FixedPoint<int, 8> p0(5);
//
//    std::cout << (p0)<< std::endl;
//
//    std::cout << (p)<< std::endl;
//
//    ++p;
//    std::cout << (p)<< std::endl;
//
//
//    FixedPoint<long, 2> p1(100000000);
//
//    FixedPoint<long, 3> p2(10000000, 10);
//    std::cout << (p2)<< std::endl;
//
//
//    p2 = -p2;
//    std::cout << (p2)<< std::endl;


}

void checkInt() {

}

void checkShort() {

}

void checkLongLong() {

}