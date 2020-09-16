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

int main()
{
    Point *ptr = new Point[2]; //创建对象数组
    ptr[0].move(5, 10);        //通过指针访问数组元素的成员
    ptr[1].move(15, 20);       //通过指针访问数组元素的成员
    cout << "Delete..." << endl;

    delete[] ptr;

    //动态创建多维数组
    int(*cp)[9][8] = new int[7][9][8];
    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {
                *(*(*(cp + i) + j) + k) = (i * 100 + j * 10 + k);
            }
        }
    }

    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {
                cout << cp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}