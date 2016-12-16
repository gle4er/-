#include <iostream>
#include "../headers/tCircle.h"

uint64_t randomiwe(void);
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

tCircle::tCircle()
{
    setr(randomiwe() % 200);
}

tCircle::~tCircle()
{
}

int tCircle::getr() const
{
    return r;
}

void tCircle::setr(int tmp)
{
    r = tmp;
}

void tCircle::move()
{
    setx(getx() + getvecx());
    sety(gety() + getvecy());
    if (getx() + getr() > SCREEN_WIDTH || getx() - getr() < 0)
        setvecx(getvecx() * -1);
    if (gety() + getr() > SCREEN_HEIGHT || gety() - getr() < 0)
        setvecy(getvecy() * -1);
}
