#ifndef TRIANGLE
#define TRIANGLE

#include "../headers/tLine.h"

class tRiangle : public tLine
{
    protected:
       int x2, y2;
    public:
       tRiangle();
       ~tRiangle();
       int getx2() const;
       int gety2() const;
       void setx2(int tmp);
       void sety2(int tmp);
       void move();
       void rotate();
};

#endif
