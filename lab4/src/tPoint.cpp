#include "../headers/tPoint.h"

uint64_t randomiwe(void);

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

tPoint::tPoint()
{
    setx(randomiwe() % SCREEN_WIDTH);
    sety(randomiwe() % SCREEN_HEIGHT);
    setColor(randomiwe());
    setvecx(randomiwe() % 6 + 1, randomiwe() % 2 + 1);
    setvecy(randomiwe() % 6 + 1, randomiwe() % 2 + 1);
}

tPoint::tPoint(int x, int y, uint8_t *color)
{
    setx(x);
    sety(y);
    setColor(color);
}

tPoint::tPoint(int w, int h)
{
    setx(randomiwe() % w);
    sety(randomiwe() % h);
    setColor(randomiwe());
    setvecx(randomiwe() % 6, randomiwe() % 2);
    setvecy(randomiwe() % 6, randomiwe() % 2);
}

tPoint::~tPoint()
{
}

void tPoint::move() 
{
    setx(getx() + getvecx());
    sety(gety() + getvecy());
    if (getx() > SCREEN_WIDTH || getx() < 0)
        setvecx(getvecx() * -1);
    if (gety() > SCREEN_HEIGHT || gety() < 0)
        setvecy(getvecy() * -1);
}

double tPoint::getx() const
{
    return x;
}

double tPoint::gety() const 
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

void tPoint::setx(double tmp) 
{
    x = tmp;
}

void tPoint::sety(double tmp)
{
    y = tmp;
}

void tPoint::setvecx(int tmp)
{
    vecx = tmp;
}

void tPoint::setvecx(int tmp, int tmp2)
{
    int sgn = pow(-1, tmp2);
    vecx = tmp * sgn;
}

void tPoint::setvecy(int tmp)
{
    vecy = tmp;
}

void tPoint::setvecy(int tmp, int tmp2)
{
    int sgn = pow(-1, tmp2);
    vecy = sgn * tmp;
}

void tPoint::setColor(uint64_t tmp)
{
    for (int i = 0; i < 4; i++) {
        color[i] = tmp % 0xFF;
        tmp = tmp / 1000;
    }
}

void tPoint::setColor(uint8_t *tmp)
{
    for (int i = 0; i < 4; i++) 
        color[i] = tmp[i];
}
