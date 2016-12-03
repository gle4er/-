#include <iostream>
#include "../headers/tPoint.h"
#include "../headers/tLine.h"
#include "../headers/tRig.h"
#include "../headers/tElps.h"
#include <unistd.h>
#include <cmath>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

void tEllipse::move()
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
