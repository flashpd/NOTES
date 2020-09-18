/**
 * 纯虚函数
 * - 是一个在基类中声明的虚函数，它在该基类中没有定义
 *   具体的操作内容，要求各派生类根据实际需要定义自己的版本
 *   纯虚函数的声明格式为：
 * 
 *   virtual 函数类型 函数名(参数表) = 0;
 * 
 * 带有纯虚函数的类称为抽象类，抽象类不能实例化，但能规定对外接口的统一形式
 * 抽象类的作用：
 * - 将有关的数据和行为组织在一个继承层次结构中，保证派生类具有要求的行为
 * - 对于暂时无法实现的函数，可以声明为纯虚函数，留给派生类实现
 * 
 * 注意：
 * - 抽象类只能作为基类来使用
 * - 不能定义抽象类的对象
*/

#include <iostream>
using namespace std;

class Base1
{
public:
    virtual void display() const = 0; //纯虚函数
};

class Base2 : public Base1
{
public:
    virtual void display() const; //覆盖基类的虚函数
};

void Base2::display() const
{
    cout << "Base2::display()" << endl;
}

class Derived : public Base2
{
public:
    virtual void display() const; //覆盖基类的虚函数
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
    Base2 base2;
    Derived derived;
    fun(&base2);
    fun(&derived);

    return 0;
}