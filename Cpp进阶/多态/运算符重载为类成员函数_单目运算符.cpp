/**
 * 前置单目运算符重载规则
 * - 如果要重载 U 为类成员函数，使之能够实现表达式U oprd，其中oprd为A类对象，
 *   则oprd为A类对象，则U应被重载为A类的成员函数，无形参
 * 
 * - 经重载后
 *   表达式 U oprd相当于 oprd.operator U()
 * 
 * 后置单目运算符 ++ 和 -- 重载规则
 * - 如果要重载 ++ 或 -- 为类成员函数，使之能够实现表达式 
 *   oprd++ 或 oprd-- 其中oprd为A类对象，则 ++ 或 -- 应
 *   被重载为A类的成员函数，且具有一个int类型形参
 * 
 * - 经重载后，表达式 oprd++ 相当于 oprd.operator ++(0)
*/

#include <iostream>
using namespace std;

class Clock
{
public:
    Clock(int hour = 0, int minute = 0, int second = 0);
    void showTime() const;

    //前置单目运算符重载
    Clock &operator++();
    //后置单目运算符重载
    Clock operator++(int);

private:
    int hour, minute, second;
};

Clock::Clock(int hour, int minute, int second)
{
    if (0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0 <= second && second < 60)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    else
    {
        cout << "Time error!" << endl;
    }
}

void Clock::showTime() const
{
    cout << hour << ":" << minute << ":" << second << endl;
}

Clock &Clock::operator++()
{
    second++;
    if (second >= 60)
    {
        second -= 60;
        minute++;
        if (minute >= 60)
        {
            minute -= 60;
            hour = (hour + 1) % 24;
        }
    }
    return *this;   //前置+1操作执行完后要继续参与运行，所以要返回指针
}

Clock Clock::operator++(int)
{
    //注意形参表中的整型参数
    Clock old = *this;
    ++(*this);  //调用前置 “++”
    return old; //这个地方返回的是没有+1前旧值，但是实际上已经进了+1操作
}

int main()
{
    Clock myClock(23, 59, 59);
    cout << "First time output: ";
    myClock.showTime();
    cout << "Show myClock++: ";
    (myClock++).showTime();
    cout << "Show ++myClock: ";
    (++myClock).showTime();

    return 0;
}
