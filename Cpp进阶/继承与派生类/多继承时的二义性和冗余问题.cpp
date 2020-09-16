/*
可能会面临二义性的问题
class A
{
public:
    void f();
};
class B
{
public:
    void f();
    void g();
};

class C:public A, public B
{
public:
    void g();
    void h();
};
如果定义：C c1;
则 c1.f()具有二义性
而 c1.g()无二义性(同名隐藏)

解决方法一：用类名来限定
c1.A::f() 或 c1.B::f()

解决方法二：同名隐藏
在C中声明一个同名成员函数f()，f()
再根据需要调用A::f() 或 B::f()

*/

#include <iostream>
using namespace std;

class Base0
{
public:
    int var0;
    void fun0() { cout << "Member of Base0" << endl; }
};

class Base1 : public Base0
{
public: //新增外部接口
    int var1;
    void print() { cout << "var1: " << var0 << endl; }
};

class Base2 : public Base0
{
public: //新增外部接口
    int var2;
    void print() { cout << "var2: " << var0 << endl; }
};

class Derived : public Base1, public Base2
{
public:
    int var;
    void fun() { cout << "Member of Derived" << endl; }
};

/*
有二义性：
d.var0
d.Base0::var0

无二义性：
d.Base1::var0
d.Base2::var0
*/
int main()
{
    Derived d;
    d.Base1::var0 = 2;
    d.Base1::fun0();
    d.Base2::var0 = 3;
    d.Base2::fun0();
    // d.Base0::var0 = 0;   //这句话是有二义性的

    d.Base1::print();
    d.Base2::print();

    return 0;
}