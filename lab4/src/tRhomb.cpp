#include "../headers/tRh.h"

uint64_t randomiwe(void);

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

tRhombus::tRhombus()
{
    setWidth(randomiwe() % 200);
    setHeight(randomiwe() % 200);
    setx1(getx() + (getWidth() / 2));
    sety1(gety() + getHeight());
    setx2(getx() + getWidth());
    sety2(gety());
    setx3(getx1());
    sety3(gety() - getHeight());
}

void tRhombus::move() 
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
    if (gety() > (SCREEN_HEIGHT - getHeight()) || gety() < getHeight())
        setvecy(getvecy() * -1);
}

