#ifndef POINT
#define POINT
#include <iostream>
#include <unistd.h>
#include <cmath>

class tPoint 
{
    protected:
        int vecx, vecy;
        double x, y;
        uint8_t color[4];
    public:
        tPoint();
        tPoint(int x, int y, uint8_t *color);
        tPoint(int w, int h);
        ~tPoint();
        void movePoint(int SCREEN_WIDTH, int SCREEN_HEIGHT); 
        void move(); 
        double getx() const; 
        double gety() const; 
        int getvecx() const;
        int getvecy() const;
        uint8_t *getColor();
        void setx(double tmp); 
        void sety(double tmp);
        void setvecx(int tmp);
        void setvecx(int tmp, int tmp2);
        void setvecy(int tmp);
        void setvecy(int tmp, int tmp2);
        void setColor(uint64_t tmp);
        void setColor(uint8_t *tmp);
};
#endif
