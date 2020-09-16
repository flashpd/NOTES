/**
 * 默认情况下
 * 基类的构造函数不被继承
 * 派生类需要定义自己的构造函数
 * 
 * C++11规定
 * 可用using语句继承基类构造函数
 * 但是只能初始化从基类继承的成员
 * 语法形式：
 *   using B::B
 * 
 * 若不继承基类的构造函数
 * - 派生类新增成员：派生类定义构造函数初始化
 * - 继承来的成员：自动调用基类构造函数进行初始化
 * - 派生类的构造函数需要给基类的构造函数传递参数
 * 
 * 单继承时构造函数的定义语法：见79行
 * 派生类名::派生类名(基类所需要的形参, 本类成员所需的形参) : 基类名(参数表), 本类成员初始化列表
 * {
 *      //其他初始化
 * }
*/

/*
派生类与基类的构造函数
当基类有默认构造函数时
- 派生类构造函数可以不向基类构造函数传递参数
- 构造派生类的对象的时候，基类的默认构造函数将被调用

如果执行基类中带参数的构造函数
- 派生类构造函数应为基类构造函数提供参数
*/

/*
构造函数的执行顺序
1.调用基类构造函数
- 顺序按照它们被继承时声明的顺序(从左向右)

2.对初始化列表中的成员定义的顺序
- 顺序按照它们在类中定义的顺序
- 对象成员初始化时自动调用其所属类的构造函数
  由初始化列表提供参

3.执行派生类的构造函数体中的内容
*/

#include <iostream>
using namespace std;

class B
{
public:
    B();
    B(int i);
    ~B();
    void print() const;

private:
    int b;
};

B::B()
{
    b = 0;
    cout << "B's default constructor called." << endl;
}

B::B(int i)
{
    b = i;
    cout << "B's constructor called." << endl;
}

B::~B()
{
    cout << "B's destructor called." << endl;
}

void B::print() const
{
    cout << b << endl;
}

class C : public B
{
public:
    C();
    C(int i, int j);    //注意这里，单继承时构造函数
    ~C();
    void print() const;

private:
    int c;
};

C::C()
{
    c = 0;
    cout << "C's default constructor called." << endl;
}

C::C(int i, int j) : B(i), c(j)
{
    cout << "C's constructor called." << endl;
}

C::~C()
{
    cout << "C's destructor called." << endl;
}

void C::print() const
{
    // B::print();
    cout << c << endl;
}

int main()
{
    C obj(5, 6);
    obj.print();

    return 0;
}
