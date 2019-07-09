#include <iostream>
class Base{
    public:
    virtual void foo(){
        std::cout << " in Base" <<std::endl;
    }
};
class A: virtual public Base
{
  public:
    virtual void foo()
    {
        std::cout << "in A" << std::endl;
    }
};

class B :virtual  public Base
{
  public:
    virtual void foo()
    {
        std::cout << "in B" << std::endl;
    }
};

class C :  public B,   public A
{
  public:
    void foo()
    {
        std::cout << "in C" << std::endl;
    }
};
int main()
{
    Base* c1 =  new C();
    // std::cout << sizeof(c1) <<std::endl;
    return 0;
}