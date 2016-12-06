#ifndef LINE
#define LINE
#include "../headers/tPoint.h"

class tLine : public tPoint
{
    protected:
        double x1, y1, x0, y0;
    public:
        tLine();
        ~tLine();
        double getx1() const;
        double gety1() const;
        double getx0() const;
        double gety0() const;
        void setx1(double tmp);
        void sety1(double tmp);
        void setx0(double tmp, double tmp1);
        void sety0(double tmp, double tmp1);
        void setx0(double tmp);
        void sety0(double tmp);
        void move();
        void rotate();
};

#endif
