#include <iostream>
#include "../headers/tPoint.h"
#include "../headers/tElps.h"
#include <unistd.h>
#include <cmath>

uint64_t randomiwe(void);

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

void setpnt(int x, int y, int deltax, int deltay)
{
    setPoints(x + deltax, y + deltay);
    setPoints(x - deltax, y + deltay);
    setPoints(x + deltax, y - deltay);
    setPoints(x - deltax, y - deltay);
}

tEllipse::tEllipse()
{
    setColor(randomiwe());
    setx(randomiwe() % SCREEN_WIDTH);
    sety(randomiwe() % SCREEN_HEIGHT);
    radx = randomiwe() % 500;
    rady = randomiwe() % 400;
    int radx2 = radx * radx;
    int rady2 = rady * rady;
    double quarter = round(radx2 / sqrt(radx2 + rady2));
    for (int x = 0; x <= quarter; x++) {
        int y = rady * sqrt(1 - x * x / radx2);
        setpnt(getx(), gety(), x, floor(y));
        setpnt(getx(), gety(), x, floor(y) + 1);
    }
    quarter = round(rady2 / sqrt(radx2 + rady2));
    for (int y = 0; y <= quarter; y++) {
        int x = radx * sqrt(1 - y * y / rady2);
        setpnt(getx(), gety(), floor(x), y);
        setpnt(getx(), gety(), floor(x) + 1, y);
    }
}

void tEllipse::move()
{
    setx(getx() + getvecx());
    sety(gety() + getvecy());
    if (getx() > SCREEN_WIDTH || getx() < 0)
        setvecx(getvecx() * -1);
    if (gety() > SCREEN_HEIGHT || gety() < 0)
        setvecy(getvecy() * -1);
}

void tEllipse::setPoints(int x, int y)
{
    points.insert(tPoint(x, y, getColor()));
}

std::vector<tPoint*> tEllipse::getPoints() const
{
    return std::vector<tPoint*> points;
}
