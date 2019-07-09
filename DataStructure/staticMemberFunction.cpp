#include <iostream>
class A
{
    public:
    static void print()
    {
    std::cout << " static member function " << std::endl;
}
};


int main()
{
    /*
    A static member function can be called even if no objects of the class exist and
     the static functions are accessed using only the class name and the scope resolution operator ::.
     [NameClass::static_member_funciton]
*/
   A::print();

    return 0;
}