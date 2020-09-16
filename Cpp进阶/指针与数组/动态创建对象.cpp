#include <iostream>
using namespace std;

class Point
{
public:
    Point() : x(0), y(0)
    {
        cout << "Default Constructor called." << endl;
    }
    Point(int x, int y) : x(x), y(y)
    {
        cout << "Constructor called." << endl;
    }
    int getX() const { return x; }
    int getY() const { return y; }
    ~Point()
    {
        cout << "Destructor called." << endl;
    }
    
private:
    int x;
    int y;
};

int main()
{
    Point *ptr1 = new Point; //默认调用构造函数
    delete ptr1;             //删除对象，自动调用析构函数

    ptr1 = new Point(1, 2);
    delete ptr1;

    return 0;
}