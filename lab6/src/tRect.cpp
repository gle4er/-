#include "../headers/tRect.h"

uint64_t randomiwe(void);

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

tRectangle::tRectangle()
{
    setWidth(randomiwe() % 500);
    setHeight(randomiwe() % 451);
    setx(randomiwe() % (SCREEN_WIDTH - getWidth()));
    sety(randomiwe() % (SCREEN_HEIGHT - getHeight()));
    setx1(getx() + getWidth());
    sety1(gety());
    setx2(getx1());
    sety2(gety1() + getHeight());
    setx3(getx());
    sety3(gety2());
}

tRectangle::~tRectangle()
{
}

void tRectangle::setx2(double tmp)
{
    x2 = tmp;
}

void tRectangle::sety2(double tmp)
{
    y2 = tmp;
}

void tRectangle::setx3(double tmp)
{
    x3 = tmp;
}

void tRectangle::sety3(double tmp)
{
    y3 = tmp;
}

void tRectangle::setWidth(int tmp)
{
    width = tmp;
}

void tRectangle::setHeight(int tmp)
{
    height = tmp;
}

double tRectangle::getx2() const
{
    return x2;
}

double tRectangle::gety2() const
{
    return y2;
}

double tRectangle::getx3() const
{
    return x3;
}

double tRectangle::gety3() const
{
    return y3;
}

int tRectangle::getWidth() const
{
    return width;
}

int tRectangle::getHeight() const
{
    return height;
}

void tRectangle::move() 
{
    setx(getx() + getvecx());
    setx1(getx1() + getvecx());
    setx2(getx2() + getvecx());
    setx3(getx3() + getvecx());
    setx0(getx(), getx1());
    sety(gety() + getvecy());
    sety1(gety1() + getvecy());
    sety2(gety2() + getvecy());
    sety3(gety3() + getvecy());
    sety0(gety(), gety3());
    if ((getx() > (SCREEN_WIDTH - getWidth()) || getx() < 0) || 
            (getx1() > SCREEN_WIDTH || getx1() < getWidth()) || 
            (getx2() > SCREEN_WIDTH || getx2() < getWidth()) ||
            (getx3() > (SCREEN_WIDTH - getWidth()) || getx3() < 0))
        setvecx(getvecx() * -1);
    if ((gety() > (SCREEN_HEIGHT - getHeight()) || gety() < 0) ||
        (gety1() > (SCREEN_HEIGHT - getHeight()) || gety1() < 0) ||
            (gety2() > SCREEN_HEIGHT || gety2() < getHeight()) ||
            (gety3() > SCREEN_HEIGHT || gety3() < getHeight()))
        setvecy(getvecy() * -1);
}

void tRectangle::rotate()
{
    double x0 = getx0();
    double y0 = gety0();
    double aR = 1 * M_PI / 180;
    setx((getx() - x0) * cos(aR) - (gety() - y0) * sin(aR) + x0); 
    sety((getx() - x0) * sin(aR) + (gety() - y0) * cos(aR) + y0); 
    setx1((getx1() - x0) * cos(aR) - (gety1() - y0) * sin(aR) + x0); 
    sety1((getx1() - x0) * sin(aR) + (gety1() - y0) * cos(aR) + y0); 
    setx2((getx2() - x0) * cos(aR) - (gety2() - y0) * sin(aR) + x0); 
    sety2((getx2() - x0) * sin(aR) + (gety2() - y0) * cos(aR) + y0); 
    setx3((getx3() - x0) * cos(aR) - (gety3() - y0) * sin(aR) + x0); 
    sety3((getx3() - x0) * sin(aR) + (gety3() - y0) * cos(aR) + y0); 
}
