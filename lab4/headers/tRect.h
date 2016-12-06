#ifndef RECTANGLE
#define RECTANGLE

#include "../headers/tLine.h"

class tRectangle : public tLine
{
    protected:
        int x2, y2, x3, y3;
        int width, height;
    public:
        tRectangle();
        ~tRectangle();
        void setWidth(int tmp);
        void setHeight(int tmp);
        void setx2(int tmp);
        void sety2(int tmp);
        void setx3(int tmp);
        void sety3(int tmp);
        int getWidth() const;
        int getHeight() const;
        int getx2() const;
        int gety2() const;
        int getx3() const;
        int gety3() const;
        void move();
};

#endif
