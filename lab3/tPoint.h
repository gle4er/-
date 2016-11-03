#include <iostream>

class tPoint 
{
    private:
        int x, y, color;
    public:
        int getx() const 
        {
            return x;
        }
        int gety() const 
        {
            return y;
        }
        void setx(int tmp) 
        {
            x = tmp;
        }
        void sety(int tmp)
        {
            y = tmp;
        }
        int getColor() const
        {
            return color;
        }
        int setColor(int tmp) const
        {
            color = tmp;
        }
};
