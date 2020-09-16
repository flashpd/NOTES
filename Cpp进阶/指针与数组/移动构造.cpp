/**
 * 移动构造：当临时对象在被复制后 就不再被利用了。
 * 完全可以吧临时对象的资源直接移动 这样就避免了多余的复制操作
 * 
 * 如果临时对象即将消亡且自身的资源需要再利用 这个时候就会触发移动构造
 * 
 * 版本1：使用深层复制构造函数
 * 返回时构造临时对象 动态的分配将临时返回到主调函数 然后删除临时对象
 * 
 * 版本2：使用移动构造函数
 * 将要返回的局部对象转移到主调函数 省去了构造和删除临时对象的工程
*/

//版本1
#include <iostream>
using namespace std;

class IntNum
{
public:
    IntNum(int x = 0): xptr(new int(x)) //构造函数
    {
        cout << "Calling constructor..." << endl;
    }
    IntNum(const IntNum &n): xptr(new int(*n.xptr)) //复制构造函数
    {
        cout << "calling copy constructor..." << endl;
    }
    //&&表示右值引用
    IntNum(IntNum &&n): xptr(n.xptr)    //移动构造函数
    {
        n.xptr = nullptr;
        cout << "Calling copy constructor..." << endl;
    }

    ~IntNum()   //析构函数
    {   
        delete xptr;
        cout << "Destructing..." << endl;
    }

    int getInt()
    {
        return *xptr;
    }

private:
    int *xptr;
};

IntNum getNum()
{
    IntNum a;
    return a;
}

int main()
{
    cout << getNum().getInt() << endl;

    return 0;
}