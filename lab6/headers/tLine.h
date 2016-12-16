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
        virtual double getx1() const;
        virtual double gety1() const;
        virtual double getx0() const;
        virtual double gety0() const;
        virtual void setx1(double tmp);
        virtual void sety1(double tmp);
        virtual void setx0(double tmp, double tmp1);
        virtual void sety0(double tmp, double tmp1);
        virtual void setx0(double tmp);
        virtual void sety0(double tmp);
        void move();
        void rotate();
};

#endif
