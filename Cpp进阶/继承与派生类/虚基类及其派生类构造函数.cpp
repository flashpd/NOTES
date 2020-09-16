/**
 * 虚基类及其派生类构造函数
 * - 建立对象时所指定的类称为 最远派生函数
 * 
 * - 虚基类的成员是由最远派生类的构造函数通过调用虚基类的
 *   构造函数进行初始化的
 * 
 * - 在整个继承结构中，直接或间接继承虚基类的所有派生类，
 *   都必须在构造函数的成员初始化表中为虚基类的构造函数列出参数
 *   如果未列出，则表示调用该虚基类的默认构造函数
 * 
 * - 在建立对象时，只有最远派生类的构造函数调用虚基类的构造函数，
 *   其他类对虚基类构造函数的调用被忽略
*/

#include <iostream>
using namespace std;

class Base0
{
public:
    Base0(int var) : var0(var) {}
    void fun0() { cout << "Member of Base0" << endl; }

public:
    int var0;
};

class Base1 : virtual public Base0
{
public:
    Base1(int var) : Base0(var) {}

public:
    int var1;
};

class Base2 : virtual public Base0
{
public:
    Base2(int var) : Base0(var) {}

public:
    int var2;
};

class Derived : public Base1, public Base2
{
public:
    Derived(int var) : Base0(var), Base1(var), Base2(var) {}
    void fun() { cout << "Member of Derived" << endl; }

public:
    int var;
};

int main()
{
    // Derived d; //这样声明是错误的
    Derived d(1);
    d.var0 = 2; //直接访问虚基类的数据成员
    d.fun0();   //直接访问虚基类的函数成员

    return 0;
}
