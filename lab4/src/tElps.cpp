#include "../headers/tElps.h"

uint64_t randomiwe(void);

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

tEllipse::tEllipse()
{
    //radx = randomiwe() % 500;
    //rady = randomiwe() % 400;
    radx = 100;
    rady = 50;

    int hh = rady * rady;
    int ww = radx * radx;
    int hhww = hh * ww;
    int x0 = radx;
    int dx = 0;
    setPoints(getx() + radx, gety());
    setPoints(getx() - radx, gety());
    for (int y = 1; y <= rady; y++) {
        int x1 = x0 - (dx - 1);  
        for ( ; x1 > 0; x1--)
            if (x1*x1*hh + y*y*ww <= hhww)
                break;
        dx = x0 - x1;
        x0 = x1;

        for (int x = -x0; x <= x0; x++) {
            if (((x >= -x0) && (x <= -x0 + 1)) || ((x <= x0) && (x >= x0 - 1))) {
                setPoints(getx() + x, gety() - y);
                setPoints(getx() + x, gety() + y);
            }
        }
    }
}

void tEllipse::move()
{
    setx(getx() + getvecx());
    sety(gety() + getvecy());
    for (int i = 0; i < points.size(); i++) {
        points[i]->setx(points[i]->getx() + getvecx());
        points[i]->sety(points[i]->gety() + getvecy());
    }
    if (getx() + radx > SCREEN_WIDTH || getx() < radx)
        setvecx(getvecx() * -1);
    if (gety() + rady > SCREEN_HEIGHT || gety() < rady)
        setvecy(getvecy() * -1);
}

void tEllipse::setPoints(int x, int y)
{
    points.push_back(new tPoint(x, y, getColor()));
}

std::vector<tPoint*> tEllipse::getPoints() const
{
    return points;
}

void tEllipse::rotate()
{
    double x0 = getx();
    double y0 = gety();
    double aR = 1 * M_PI / 180;
    for (int i = 0; i < points.size(); i++) {
        double x = points[i]->getx();
        double y = points[i]->gety();
        points[i]->setx((x - x0) * cos(aR) - (y - y0) * sin(aR) + x0); 
        points[i]->sety((x - x0) * sin(aR) + (y - y0) * cos(aR) + y0); 
    }
}
