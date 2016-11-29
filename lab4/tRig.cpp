#include <iostream>
#include "tPoint.h"
#include "tLine.h"
#include "tRig.h"
#include <cmath>
#include <unistd.h>

uint64_t randomiwe(void);

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

int lim = 300;

tRiangle::tRiangle()
{
    setx(randomiwe() % lim);
    sety(randomiwe() % lim);
    setx1(randomiwe() % lim);
    sety1(randomiwe() % lim);
    setx2(randomiwe() % lim);
    sety2(randomiwe() % lim);
    setColor(randomiwe());
    setvecx(randomiwe() % 6 + 1, randomiwe() % 2 + 1);
    setvecy(randomiwe() % 6 + 1, randomiwe() % 2 + 1);
}

tRiangle::~tRiangle()
{
}

int tRiangle::getx2() const
{
    return x2;
}

int tRiangle::gety2() const
{
    return y2;
}

void tRiangle::setx2(int tmp)
{
    x2 = tmp;
}

void tRiangle::sety2(int tmp)
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
