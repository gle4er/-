#include <iostream>
#include "tPoint.h"
#include <unistd.h>

uint64_t randomiwe(void);

tPoint::tPoint()
{
    setx(randomiwe() % 320);
    sety(randomiwe() % 240);
    setColor(randomiwe());
    setvecx(randomiwe() % 6, randomiwe() % 1);
    setvecy(randomiwe() % 6, randomiwe() % 1);
}

tPoint::tPoint(int w, int h)
{
    setx(randomiwe() % w);
    sety(randomiwe() % h);
    setColor(randomiwe());
    setvecx(randomiwe() % 6, randomiwe() % 1);
    setvecy(randomiwe() % 6, randomiwe() % 1);
}

tPoint::~tPoint()
{
}

int tPoint::getx() const
{
    return x;
}

int tPoint::gety() const 
{
    return y;
}

int tPoint::getvecx() const 
{
    return vecx;
}

int tPoint::getvecy() const 
{
    return vecy;
}

uint8_t* tPoint::getColor()
{
    return color;
}

void tPoint::setx(int tmp) 
{
    x = tmp;
}

void tPoint::sety(int tmp)
{
    y = tmp;
}

void tPoint::setvecx(int tmp)
{
    vecx = tmp;
}

void tPoint::setvecx(int tmp, int tmp2)
{
    int sgn = (tmp2 == 1) ? -1 : 1;
    vecx = tmp;
}

void tPoint::setvecy(int tmp)
{
    vecx = tmp;
}

void tPoint::setvecy(int tmp, int tmp2)
{
    int sgn = (tmp2 == 1) ? -1 : 1;
    vecy = sgn * tmp;
}

void tPoint::setColor(uint64_t tmp)
{
    for (int i = 0; i < 4; i++) {
        color[i] = tmp % 0xFF;
        tmp = tmp / 1000;
    }
}
