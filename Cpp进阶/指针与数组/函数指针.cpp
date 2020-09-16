#include <iostream>
using namespace std;

//使用函数指针实现函数回调
int compute(int a, int b, int (*func)(int, int))
{
    return func(a, b);
}
int max(int a, int b)
{
    return ((a > b) ? a : b);
}

int min(int a, int b)
{
    return ((a < b) ? a : b);
}

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int a, b, res;
    cout << "请输入整数a: ";
    cin >> a;
    cout << "请输入整数b: ";
    cin >> b;

    res = compute(a, b, &max);
    cout << "Max of " << a << " and " << b << " is " << res << endl;

    return 0;
}