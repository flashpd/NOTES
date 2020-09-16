#include <cassert>
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

    ~Point()
    {
        cout << "Destructor called." << endl;
    }

    int getX() const { return x; }
    int getY() const { return y; }

    void move(int newX, int newY)
    {
        x = newX;
        y = newY;
    }

private:
    int x;
    int y;
};

class ArrayOfPoints
{
public:
    ArrayOfPoints(int size) : size(size)
    {
        points = new Point[size];
    }

    // 深拷贝的关键
    //没有这个函数 将变成浅拷贝会出现错误
    ArrayOfPoints(const ArrayOfPoints &pointsArray);    

    ~ArrayOfPoints()
    {
        cout << "Deleting..." << endl;
        delete[] points;
    }
    /*
    这里返回“引用”可以用来操作封装数组对象内部的数组元素
    如果返回的是“值”则只是返回了一个“副本” 通过副本是无法操作原来数组中的元素的
    */
    Point &element(int index) //取数组元素的函数
    {
        assert(index >= 0 && index < size);
        return points[index];
    }

private:
    Point *points; //指向动态数组首地址
    int size;      //数组大小
};

ArrayOfPoints::ArrayOfPoints(const ArrayOfPoints &v)
{
    size = v.size;
    points = new Point[size];
    for (int i = 0; i < size; ++i)
    {
        points[i] = v.points[i];
    }
}

int main()
{
    int count;

    cout << "Please enter the count of points: ";
    cin >> count;
    ArrayOfPoints pointsArray1(count); //创建数组对象

    pointsArray1.element(0).move(5, 0);   //访问数组元素的成员
    pointsArray1.element(1).move(15, 20); //访问数组元素的成员

    ArrayOfPoints pointsArray2(pointsArray1); //创建副本

    cout << "Copy of pointsArray1:" << endl;
    cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ", "
         << pointsArray2.element(0).getY() << endl;

    cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ", "
         << pointsArray2.element(1).getY() << endl;

    pointsArray1.element(0).move(25, 30); //访问数组元素的成员
    pointsArray1.element(1).move(35, 40); //访问数组元素的成员

    cout << "After the moving of pointsArray1:" << endl;
    cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ", "
         << pointsArray2.element(0).getY() << endl;

    cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ", "
         << pointsArray2.element(1).getY() << endl;
}

