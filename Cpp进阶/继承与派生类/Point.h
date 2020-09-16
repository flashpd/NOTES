
class Point //基类Point
{
public: //公有成员函数
    void initPoint(float x = 0, float y = 0)
    {
        this->x = x;
        this->y = y;
    }

    void move(float offX, float offY)
    {
        x += offX;
        y += offY;
    }
    float getX() const { return x; }
    float getY() const { return y; }

private:    //私有数据 成员
    float x, y;
};