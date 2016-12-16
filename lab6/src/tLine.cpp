#include "../headers/tLine.h"

uint64_t randomiwe(void);
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
int width = 400;
int height = 300;

tLine::tLine()
{
    setx1(randomiwe() % width);
    sety1(randomiwe() % height);
}

tLine::~tLine()
{
}

double tLine::getx1() const
{
    return x1;
}

double tLine::gety1() const
{
    return y1;
}

double tLine::getx0() const
{
    return x0;
}

double tLine::gety0() const
{
    return y0;
}

void tLine::setx1(double tmp)
{
    x1 = tmp;
}

void tLine::sety1(double tmp)
{
    y1 = tmp;
}

void tLine::setx0(double tmp, double tmp1)
{
    int sum = tmp + tmp1;
    x0 = sum / 2;
}    

void tLine::sety0(double tmp, double tmp1)
{
    int sum = tmp + tmp1;
    y0 = sum / 2;
}    

void tLine::setx0(double tmp)
{
    x0 = tmp;
}    

void tLine::sety0(double tmp)
{
    y0 = tmp;
}    

void tLine::move() 
{
    setx(getx() + getvecx());
    sety(gety() + getvecy());
    setx1(getx1() + getvecx());
    sety1(gety1() + getvecy());
    setx0(getx(), getx1());
    sety0(gety(), gety1());
    if (getx() > SCREEN_WIDTH || getx() < 0)
        setvecx(getvecx() * -1);
    if (getx1() > SCREEN_WIDTH || getx1() < 0)
        setvecx(getvecx() * -1);
    if (gety() > SCREEN_HEIGHT || gety() < 0)
        setvecy(getvecy() * -1);
    if (gety1() > SCREEN_HEIGHT || gety1() < 0)
        setvecy(getvecy() * -1);
}

void tLine::rotate()
{
    double x0 = getx0();
    double y0 = gety0();
    double aR = 1 * M_PI / 180;
    setx((getx() - x0) * cos(aR) - (gety() - y0) * sin(aR) + x0); 
    sety((getx() - x0) * sin(aR) + (gety() - y0) * cos(aR) + y0); 
    setx1((getx1() - x0) * cos(aR) - (gety1() - y0) * sin(aR) + x0); 
    sety1((getx1() - x0) * sin(aR) + (gety1() - y0) * cos(aR) + y0); 
}
