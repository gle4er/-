#include <iostream>
#include "../headers/tPoint.h"
#include "../headers/tLine.h"
#include "../headers/tRect.h"
#include <unistd.h>
#include <cmath>

uint64_t randomiwe(void);

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

tRectangle::tRectangle()
{
    setWidth(200);
    setHeight(100);
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

void tRectangle::setx2(int tmp)
{
    x2 = tmp;
}

void tRectangle::sety2(int tmp)
{
    y2 = tmp;
}

void tRectangle::setx3(int tmp)
{
    x3 = tmp;
}

void tRectangle::sety3(int tmp)
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

int tRectangle::getx2() const
{
    return x2;
}

int tRectangle::gety2() const
{
    return y2;
}

int tRectangle::getx3() const
{
    return x3;
}

int tRectangle::gety3() const
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
    sety(gety() + getvecy());
    sety1(gety1() + getvecy());
    sety2(gety2() + getvecy());
    sety3(gety3() + getvecy());
    if (getx() > (SCREEN_WIDTH - getWidth()) || getx() < 0)
        setvecx(getvecx() * -1);
    if (gety() > (SCREEN_HEIGHT - getHeight()) || gety() < 0)
        setvecy(getvecy() * -1);
}
