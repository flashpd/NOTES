#include "Point.h"

class Rectangle : private Point
{
public: //新增公有函数成员
    void initRectangle(float x, float y, float w, float h)
    {
        initPoint(x, y);
        this->w;
        this->h;
    }

    void move(float offX, float offY) { Point::move(offX, offY); }
    float getX() const { return Point ::getX(); }
    float getY() const { return Point ::getY(); }
    float getH() const { return h; }
    float getW() const { return w; }

private: //新增私有数据成员
    float w, h;
};