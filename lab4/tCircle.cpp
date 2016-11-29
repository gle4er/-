#include <iostream>
#include "tPoint.h"
#include "tCircle.h"
#include <unistd.h>
#include <cmath>

uint64_t randomiwe(void);
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

tCircle::tCircle()
{
    setx(randomiwe() % SCREEN_WIDTH);
    sety(randomiwe() % SCREEN_HEIGHT);
    setr(randomiwe() % 200);
    setColor(randomiwe());
    setvecx(randomiwe() % 6 + 1, randomiwe() % 2 + 1);
    setvecy(randomiwe() % 6 + 1, randomiwe() % 2 + 1);
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
