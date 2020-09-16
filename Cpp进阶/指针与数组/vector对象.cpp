/**
 * 为什么需要vector？
 * 1 封装任何类型的动态数组，自动创建和删除
 * 2 数组下标越界检查
 * 
 * 自己通过new申请到的动态数组没这个方便（包括不能访问下标等
*/

#include <iostream>
#include <vector>
using namespace std;

double average(const vector<double> &arr)
{
    double sum = 0;
    for (unsigned i = 0; i < arr.size(); ++i)
    {
        sum += arr[i];
    }

    return sum / arr.size();
}

int main()
{
    unsigned n;
    cout << "n = ";
    cin >> n;

    vector<double> arr(n); //创建数组对象
    cout << "Please input " << n << " real numbers:" << endl;

    for (unsigned i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Average = " << average(arr) << endl;

    vector<int> v = {1, 2, 3};
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << endl;
    }

    for (auto e : v)
    {
        cout << e << endl;
    }

        return 0;
}