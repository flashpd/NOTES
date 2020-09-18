/**
 * 初识虚函数（虚函数是属于对象的而不是属于类的，所以在运行时才能确定具体对象）
 * - 用virtual关键字说明的函数
 * - 虚函数是实现运行时多态性基础
 * - C++中的虚函数是动态绑定的函数
 * - 虚函数必须是非静态的成员函数，虚函数经过派生之后，
 *   就可以实现运行过程中的多态
 * 
 * 
 * 什么函数可以是虚函数
 * - 一般成员函数可以是虚函数
 * - 构造函数不能是虚函数（注意）
 * - 析构函数可以是虚函数
 * 
 * 
 * 一般虚函数成员
 * - 虚函数的声明
 *   ·virtual函数类型 函数名(形参表)
 * 
 * - 虚函数声明只能出现在类定义中的函数原型声明中，
 *   而不能在成员函数实现的时候
 * 
 * - 在派生类中可以对基类中的成员函数进行覆盖
 * 
 * - 虚函数一般不声明为内联函数，因为对虚函数的调用需要动态绑定，
 *   而对内联函数的处理是静态的
 * 
 * virtual关键字
 * - 派生类可以不显示的用virtual声明虚函数，这时系统就会用以下规则
 *   来判断派生类的一个函数成员是不是虚函数：
 *   ·该函数是否与基类的虚函数有相同的名称、参数个数及对应参数类型
 *   ·该函数是否与基类的虚函数有相同的返回值或满足类型兼容规则的指针、引用型的返回值
 * 
 * - 如果从名称、参数及返回值三个方面检查之后，派生类的函数满足上述条件
 *   就会自动确定为虚函数。这时，派生类的虚函数便覆盖了基类的虚函数
 * 
 * - 派生类中的虚函数还会隐藏基类中同名函数的所有其他重载形式
 * - 一般习惯于在派生类的函数中也使用virtual关键字，以增加程序的可读性
*/

/**
 * 这个地方如果不加virtual ，则运行会出现意外效果，即指向同一对象
*/

#include <iostream>
using namespace std;

class Base1
{
public:
    virtual void display() const; //虚函数
};

void Base1::display() const
{
    cout << "Base1::display()" << endl;
}

class Base2 : public Base1
{
public:
    virtual void display() const;
};

void Base2::display() const
{
    cout << "Base2::display()" << endl;
}

class Derived : public Base2
{
public:
    virtual void display() const;
};

void Derived::display() const
{
    cout << "Derived::display()" << endl;
}

void fun(Base1 *ptr)
{
    ptr->display();
}

int main()
{
    Base1 base1;
    Base2 base2;
    Derived derived;

    fun(&base1);
    fun(&base2);
    fun(&derived);

    return 0;
}