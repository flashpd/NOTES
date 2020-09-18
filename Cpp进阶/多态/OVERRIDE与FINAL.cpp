/**
 * override
 * - 多态行为的基础：基类声明虚函数，派生类声明一个函数覆盖该虚函数
 * - 覆盖要求：函数签名（signature）完全一直
 * - 函数签名包括：函数名 参数列表 const
 * 
 * 
 * - C++11引入显示函数覆盖，在编译期而非运行期捕获此类错误。
 * - 在虚函数显式重载中运用，编译器会检查基类是否存在一虚拟函数，
 *   与派生类中带有声明override的虚拟函数，有相同的函数签名，
 *   若不存在，则会回报错误
 * 
 * 使用final可以用来表示基类不希望被继承，不希望衍生出派生类
 * 
 * struct Base1 final {};
 * struct Derived1 : Base1 {};  //编译错误：Base1为final，不允许被继承
 * 
 * struct Base2
 * {
 *      virtual void f() final;
 * };
 * 
 * struct Derived2 : Base2
 * {
 *      void f();   //编译错误：Base2::f 为final，不允许被覆盖
 * };
*/

#include <iostream>
using namespace std;

class Base
{
public:
    virtual void f1(int) const;
    virtual ~Base() {}
};
void Base::f1(int) const
{
    cout << "Base f1" << endl;
    return;
}

class Derived : public Base
{
public:
    void f1(int) const override;
    ~Derived() {}
};
void Derived::f1(int) const
{
    cout << "derived f1" << endl;
    return;
}
/* 不带override的错误示范
class Derived : public Base
{
public:
    void f1(int);
    ~Derived() {}
};
void Derived::f1(int)
{
    cout << "derived f1" << endl;
    return;
}
*/
int main()
{
    Base *b;
    b = new Base;
    b->f1(1);

    b = new Derived;
    b->f1(1);

    return 0;
}

/*
错误示范运行结果：（结果不符合预期）
Base f1
Base f1
*/