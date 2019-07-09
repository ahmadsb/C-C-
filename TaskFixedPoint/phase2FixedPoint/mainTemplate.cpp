#include<iostream>
#include<sstream>
#include <assert.h> 
#include"priceTemplate.h"
template<class T, unsigned int size>
void compare(Price<size, T> x, Price<size, T> y)
{
    
    if(x == y)
    {
        if (x > y)
		    std::cout << x << " is greater or equal  than " << y << '\n'; // case 1
	    else if (x < y)
		    std::cout << x << " is less or equal than " << y << '\n'; // case 2
	    else if (x=y)
		    std::cout << x << " is equal to " << y << '\n'; // case 3
    return;
    }
    if( x!= y){
        if (x > y)
		    std::cout << x << " is not equal or greater  than " << y << '\n'; // case 1
	    else if (x < y)
		    std::cout << x << " is not equal or less than " << y << '\n'; // case 2
    }
	

    return;
}


int main(){
    // code phase 4
    priceTwoInt pp(2,22);
    priceTwoShort ppp(3,322);
    std::cout<<pp<<std::endl;
    std::cout<<ppp<<std::endl;
    // final code phase 4
    const int value = 9;
    const int value2 = 3;
    const int value_assignment = 18;
    std::stringstream out;
    // don't work B. time run not time cop
    // int log;
    // std::cin>>log;
    // Price<log> p1(9,112);
    Price<3> p1(9,112);
    Price<2> p2(3,122);
    p1 = p2;// if I doen't copy ctor it is not work but if same size and type as work else not
    std::cout<<p1<<std::endl;
    std::cout<<p1<<std::endl;
    // root price is variable value
    std::string expected_print ="9.00";

    std::string expected_plusplus = "10.00";
    
    out.str("");
    out<<value_assignment;
    std::string expeted_assignment = out.str()+".00";

    std::string expected_minusminus = "8.00";
    std::string expected_unary = "-9.00";
    std::string expected_plus = "12.00";
    std::string expected_minus = "6.00";
    std::string expected_mult = "27.00";
    std::string expected_divid = "3.00";
    std::string expected_mod = "0.00";
    
    

    // out.str("");
    // out<< p1;
    // assert(out.str() == expected_print);
    // compare(p1,p2); 

    // p1++;
    // out.str("");
    // out<<p1;
    // assert(out.str() == expected_plusplus);

    // p1 = value_assignment;
    // out.str("");
    // out<<p1;
    // assert(out.str() == expeted_assignment);

   
    // p1 = value;
    // p1--;
    // out.str("");
    // out<<p1;
    // assert(out.str() == expected_minusminus);
    
    // p1 = value;
    // p1 = -p1;
    // out.str("");
    // out<<p1;
    // assert(out.str() == expected_unary);
    // //========
    // p1 = value;
    // out.str("");
    // out<<p1 + p2;
    // assert(out.str() == expected_plus);

    // p1 = value;
    // out.str("");
    // out<<p1 - p2;
    // assert(out.str() == expected_minus);

    // p1 = value;
    // out.str("");
    // out<<p1 * p2;
    // assert(out.str() == expected_mult);

    // p1 = value;
    // out.str("");
    // out<<p1 / p2;
    // assert(out.str() == expected_divid);

    // p1 = value;
    // out.str("");
    // out<<p1 % p2;
    // assert(out.str() == expected_mod);

    // std::cout<<"Done!!"<<std::endl;
    return 0;
}