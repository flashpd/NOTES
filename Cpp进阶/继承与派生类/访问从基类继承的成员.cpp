/**
 * 当派生类与基类中有相同成员时：
 * - 若未特别限定，则通过派生类对象使用的是派生类中的同名函数
 * - 如要通过派生类对象访问基类中被隐藏的同名函数 ，应使用基类名和作用域操作符(::)来限定
*/



#include <iostream>
using namespace std;

class Base1 //基类Base1
{
public:
    int var;
    void func() { cout << "Member of Base1" << endl; }
};

class Base2 //基类Base2
{
public:
    int var;
    void func() { cout << "Member of Base2" << endl; }
};

class Derived : public Base1, public Base2
{
public:
    int var; //同名数据成员
    void func() { cout << "Member of Derived" << endl; }
};

int main()
{
    Derived d;
    Derived *p = &d;
    // Derived *p = new Derived;
    d.var = 1; //对象名.成员名标识
    d.func();  //访问D1类成员

    d.Base1::var = 2; //作用域分辨符标识
    d.Base1::func();  //访问Base1基类成员

    p->Base2::var = 3; //作用域分辨率符标识
    p->Base2::func();  //访问Base2基类成员

    return 0;
}
