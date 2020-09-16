#include "employee.h"
#include <iostream>
using namespace std;

int main()
{
    Employee emp[2], *empOne = 0;
    empOne = new Employee("Zhang San", "Haidian", "Beijing", "100084");
    emp[0] = *empOne;
    empOne = new Employee("Li Si", "Xuanwu", "Beijing", "100031");
    emp[1] = *empOne;

    for (int i = 0; i < 2; ++i)
    {
        cout << "Number" << i << ": " << endl;
        emp[i].display();
    }

    return 0;
}