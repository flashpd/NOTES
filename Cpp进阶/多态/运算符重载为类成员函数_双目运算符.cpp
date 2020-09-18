/**
 * - C++几乎可以重载全部的运算符，而且只能够重载
 *   C++已经有的
 * 
 * - 不能重载的运算符："." ".*" "::" "?:"
 * - 重载之后运算符的优先级和结合性都不会改变
 * 
 * - 运算符重载是针对新类型数据的实际需要，对原有运算符进行适当的改造
 * 例如：
 * - 使复数类的对象可以用“+”运算符实现加法
 * - 是时钟类对象可以用“++”运算符实现时间增加1秒
 * 
 * - 重载为类的非静态成员函数
 * - 重载为非成员函数
 * 
 * 重载为类成员的运算符函数定义形式：
 * 函数类型 operator运算符(形参)
 * {
 * ...
 * }
 * 参数个数 = 原操作数个数-1 (后置++、--除外)
*/

/**
 * 双目运算符重载规则
 * - 如果要重载B为类成员函数，使之能够实现表达式oprd1 B oprd2，
 *   其中oprd1 为A类对象，则B应被重载为A类的成员函数，形参类型
 *   应该是oprd2所属的类型
 * 
 * - 经重载后，表达式oprd1 B oprd2 相当于 oprd1.operator B(oprd2)
*/

/*
例题
要求
- 将+、-运算重载为复数类的成员函数

规则
- 实部和虚部分别 相加减

操作数
- 两个操作数都是复数类的对象
*/
#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    //运算符+重载成员函数
    Complex operator+(const Complex &c2) const;
    //运算符-重载成员函数
    Complex operator-(const Complex &c2) const;

    void display() const; //输出复数

private:
    double real; //复数实部
    double imag; //复数虚部
};

Complex Complex::operator+(const Complex &c2) const
{
    //创建一个临时无名对象作为返回值
    return Complex(real + c2.real, imag + c2.imag);
}

Complex Complex::operator-(const Complex &c2) const
{
    //创建一个临时无名对象作为返回值
    return Complex(real - c2.real, imag - c2.imag);
}

void Complex::display() const
{
    cout << "(" << real << ", " << imag << ")" << endl;
}

int main()
{
    Complex c1(5, 4), c2(2, 10), c3;
    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();

    c3 = c1 - c2; //使用重载运算符完成复数减法
    cout << "c3 = c1 - c2 = ";
    c3.display();

    c3 = c1 + c2; //使用重载运算符完成复数减法
    cout << "c3 = c1 + c2 = ";
    c3.display();

    c1.display();
    c1.operator+(c2).display();

    return 0;
}
