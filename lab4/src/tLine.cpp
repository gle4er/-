#include <iostream>
#include "tPoint.h"
#include "tLine.h"
#include <unistd.h>
#include <cmath>

uint64_t randomiwe(void);
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
int width = 400;
int height = 300;

tLine::tLine()
{
    setx(randomiwe() % width);
    sety(randomiwe() % height);
    setx1(randomiwe() % width);
    sety1(randomiwe() % height);
    setColor(randomiwe());
    setvecx(randomiwe() % 6 + 1, randomiwe() % 2 + 1);
    setvecy(randomiwe() % 6 + 1, randomiwe() % 2 + 1);
}

tLine::~tLine()
{
}

int tLine::getx1() const
{
    return x1;
}

int tLine::gety1() const
{
    return y1;
}

void tLine::setx1(int tmp)
{
    x1 = tmp;
}

void tLine::sety1(int tmp)
{
    y1 = tmp;
}

void tLine::move() 
{
    setx(getx() + getvecx());
    sety(gety() + getvecy());
    setx1(getx1() + getvecx());
    sety1(gety1() + getvecy());
    if (getx() > SCREEN_WIDTH || getx() < 0)
        setvecx(getvecx() * -1);
    if (getx1() > SCREEN_WIDTH || getx1() < 0)
        setvecx(getvecx() * -1);
    if (gety() > SCREEN_HEIGHT || gety() < 0)
        setvecy(getvecy() * -1);
    if (gety1() > SCREEN_HEIGHT || gety1() < 0)
        setvecy(getvecy() * -1);
}
