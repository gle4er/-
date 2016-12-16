#ifndef TRIANGLE
#define TRIANGLE

#include "../headers/tLine.h"

class tRiangle : public tLine
{
    protected:
       double x2, y2;
    public:
       tRiangle();
       ~tRiangle();
       double getx2() const;
       double gety2() const;
       void setx2(double tmp);
       void sety2(double tmp);
       void move();
       void rotate();
};

#endif
