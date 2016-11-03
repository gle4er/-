#include <iostream>
#include "tPoint.h"
#include <unistd.h>

int tPoint::getx() const
{
    return x;
}

int tPoint::gety() const 
{
    return y;
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

void tPoint::setColor(uint64_t tmp)
{
    for (int i = 0; i < 4; i++) {
        color[i] = tmp % 0xFF;
        tmp = tmp / 1000;
    }
}
