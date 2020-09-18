/**
 * 运算符重载为非成员函数的规则
 * - 函数的形参代表依自左至右次序排列的各操作数
 * - 重载为非成员函数时
 *   ·参数个数 = 原操作数个数(后置++、--除外)
 *   ·至少应该有一个自定义类型的参数
 * 
 * - 后置单目运算符 ++ 和 -- 的重载函数，形参列表中要增加一个int，
 *   但不必写形参名
 * 
 * - 如果在运算符的重载函数中需要操作某类对象的私有成员，
 *   可以将此函数声明为该类的友元
*/

/**
 * - 双目运算符B重载后，
 *   表达式oprd1 B oprd2
 *   等同于operator B(oprd1, oprd2)
 * 
 * - 前置单目运算符B重载后，
 *   表达式 B oprd
 *   等同于operator B(oprd)
 * 
 * - 后置单目运算符 ++ 和 -- 重载后，
 *   表达式 oprd B
 *   等同于 operator B(oprd, 0)
*/

#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c1, const Complex &c2);
    friend ostream &operator<<(ostream &out, const Complex &c);

private:
    double real; //复数实部
    double imag; //复数虚部
};

Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex operator-(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
ostream &operator<<(ostream &out, const Complex &c)
{
    out << "(" << c.real << "," << c.imag << ")";
    return out;
}

int main()
{
    Complex c1(5, 4), c2(2, 10), c3;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    c3 = c1 - c2;
    cout << "c3 = c1 - c2 = " << c3 << endl;

    c3 = c1 + c2;
    cout << "c3 = c1 + c2 = " << c3 << endl;

    return 0;
}
