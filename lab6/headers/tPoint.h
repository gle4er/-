#ifndef POINT
#define POINT
#include <iostream>
#include <unistd.h>
#include <cmath>
#include <vector>

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
        virtual int getr() const; 
        virtual double getx() const; 
        virtual double gety() const; 
        virtual double getx1() const; 
        virtual double gety1() const; 
        virtual double getx2() const; 
        virtual double gety2() const; 
        virtual double getx3() const; 
        virtual double gety3() const; 
        virtual int getvecx() const;
        virtual int getvecy() const;
        uint8_t *getColor();
        virtual void setr(int tmp); 
        virtual void setx(double tmp); 
        virtual void sety(double tmp);
        virtual void setx1(double tmp); 
        virtual void sety1(double tmp);
        virtual void setx2(double tmp); 
        virtual void sety2(double tmp);
        virtual void setx3(double tmp); 
        virtual void sety3(double tmp);
        virtual void setvecx(int tmp);
        virtual void setvecx(int tmp, int tmp2);
        virtual void setvecy(int tmp);
        virtual void setvecy(int tmp, int tmp2);
        virtual void setColor(uint64_t tmp);
        virtual void setColor(uint8_t *tmp);
        virtual std::vector<tPoint*> getPoints() const;
        virtual void rotate();
};
#endif
