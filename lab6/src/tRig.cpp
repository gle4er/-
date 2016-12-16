#include "../headers/tRig.h"

uint64_t randomiwe(void);

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

int lim = 300;

tRiangle::tRiangle()
{
    setx2(randomiwe() % lim);
    sety2(randomiwe() % lim);
    setx0((getx() + getx1() + getx2()) / 3);
    sety0((gety() + gety1() + gety2()) / 3);
}

tRiangle::~tRiangle()
{
}

double tRiangle::getx2() const
{
    return x2;
}

double tRiangle::gety2() const
{
    return y2;
}

void tRiangle::setx2(double tmp)
{
    x2 = tmp;
}

void tRiangle::sety2(double tmp)
{
    y2 = tmp;
}

void tRiangle::move() 
{
    setx(getx() + getvecx());
    sety(gety() + getvecy());
    setx1(getx1() + getvecx());
    sety1(gety1() + getvecy());
    setx2(getx2() + getvecx());
    sety2(gety2() + getvecy());
    setx0(getx0() + getvecx());
    sety0(gety0() + getvecy());
    if (getx() > SCREEN_WIDTH || getx() < 0)
        setvecx(getvecx() * -1);
    if (getx1() > SCREEN_WIDTH || getx1() < 0)
        setvecx(getvecx() * -1);
    if (getx2() > SCREEN_HEIGHT || getx2() < 0)
        setvecx(getvecx() * -1);
    if (gety() > SCREEN_HEIGHT || gety() < 0)
        setvecy(getvecy() * -1);
    if (gety1() > SCREEN_HEIGHT || gety1() < 0)
        setvecy(getvecy() * -1);
    if (gety2() > SCREEN_HEIGHT || gety2() < 0)
        setvecy(getvecy() * -1);
}

void tRiangle::rotate()
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
}
