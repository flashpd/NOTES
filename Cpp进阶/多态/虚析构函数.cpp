#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base();
};
Base::~Base()
{
    cout << "Base destructor" << endl;
}

class Derived : public Base
{
public:
    Derived();
    virtual ~Derived();

private:
    int *p;
};
Derived::Derived()
{
    p = new int(0);
}
Derived::~Derived()
{
    cout << "Derived destructor" << endl;
    delete p;
}

void fun(Base *b)
{
    //如果第7行18行不加virtual，则静态绑定，只会调用~Base() 会造成内存泄漏
    delete b; 
}

int main()
{
    //这个地方指针b，指针类型是Base，指向Derived对象
    Base *b = new Derived();    
    fun(b);
    return 0;
}