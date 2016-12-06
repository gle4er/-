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
