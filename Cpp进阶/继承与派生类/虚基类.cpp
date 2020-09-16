/**
 * 需要解决的问题
 * - 当派生类从多个基类派生，而这些基类又有共同基类，
 *   则在访问此共同基类中的成员时，
 *   将产生冗余，并有可能因冗余带来不一致性
 * 
 * 虚基类声明
 * - virtual说明基类继承方式
 * 例：class B1:virtual public B
 * 作用：
 * - 主要用来解决多继承时可能发生的对同一基类继承多次而产生的二义性问题
 * - 为最远的派生类提供唯一的基类成员，而不重复产生多次复制
 * 
 * 注意：
 * - 在第一级继承时就要将共同基类设计为虚基类
*/

#include <iostream>
using namespace std;

class Base0
{
public:
    int var0;
    void fun0() { cout << "Member of Base0" << endl; }
    void print() { cout << "var0: " << var0 << endl; }
};

class Base1 : virtual public Base0
{
public:
    int var1;
    void print() { cout << "var1: " << var0 << endl; }
};

class Base2 : virtual public Base0
{
public:
    int var2;
    void print() { cout << "var2: " << var0 << endl; }
};

class Derived : public Base1, public Base2
{
public:
    int var;
    void fun() { cout << "Member of Derived" << endl; }
};

int main()
{
    Derived d;
    d.var0 = 2; //直接访问虚基类的数据成员
    d.fun0();   //直接访问虚基类的函数成员

    //通过下面这个实验可以看出，只有一个var0，即基类Base0的var0
    //Base1和Base2中var0皆指向Base0的var0
    d.Base0::print();
    d.Base1::print();
    d.Base2::print();

    d.Base1::var0 = 3;
    d.Base2::var0 = 4;

    d.Base0::print();
    d.Base1::print();
    d.Base2::print();

    return 0;
}
