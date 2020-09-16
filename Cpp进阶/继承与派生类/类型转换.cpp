/**
 * 类型转换
 * 
 * 公有派生类对象可以被当作基类的对象使用，反之则不可
 * - 派生类的对象可以隐含转换为基类对象
 * - 派生类的对象可以初始化基类的引用
 * - 派生类的指针可以隐含转换为基类的指针
 * 
 * 通过基类对象名、指针只能使用从基类继承的成员
*/
//不要重新定义继承而来的非虚函数
#include <iostream>
using namespace std;

class Base1 //基类Base1定义
{
public:
    void display() const
    {
        cout << "Base1::display()" << endl;
    }
};

class Base2 : public Base1  //公有派生类Base2定义
{
public:
    void display() const
    {
        cout << "Base2::display()" << endl;
    }
};

class Derived : public Base2    //公有派生类Derived定义
{
public:
    void display() const
    {
        cout << "Derived::display()" << endl;
    }
};

void fun(Base1 *ptr)    //参数为指向基类对象的指针
{  
    ptr->display(); //对象指针->成员名
}

int main()
{
    Base1 base1;    //声明Base1类对象
    Base2 base2;    //声明Base2类对象
    Derived derived;    //声明derived类对象

    fun(&base1);    //用Base1对象的指针调用fun函数
    fun(&base2);    //用Base2对象的指针调用fun函数
    fun(&derived);  //用Derived对象的指针调用fun函数

    return 0;
}



/* 
运行结果
Base1::display()
Base1::display()
Base1::display()
*/