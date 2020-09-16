#include "Point.h"

class Rectangle : public Point
{
public: //新增公有函数成员
    void initRectangle(float x, float y, float w, float h)
    {
        initPoint(x, y);
        this->w;
        this->h;
    }

    float getH() const { return h; }
    float getW() const { return w; }

private: //新增私有数据成员
    float w, h;
};