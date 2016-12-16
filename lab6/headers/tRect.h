#ifndef RECTANGLE
#define RECTANGLE

#include "../headers/tLine.h"

class tRectangle : public tLine
{
    protected:
        double x2, y2, x3, y3;
        int width, height;
    public:
        tRectangle();
        ~tRectangle();
        void setWidth(int tmp);
        void setHeight(int tmp);
        void setx2(double tmp);
        void sety2(double tmp);
        void setx3(double tmp);
        void sety3(double tmp);
        int getWidth() const;
        int getHeight() const;
        double getx2() const;
        double gety2() const;
        double getx3() const;
        double gety3() const;
        void move();
        void rotate();
};

#endif
