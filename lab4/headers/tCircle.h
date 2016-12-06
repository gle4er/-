#ifndef CIRCLE
#define CIRCLE
#include "../headers/tPoint.h"

class tCircle : public tPoint
{
    private:
        int r;
    public:
        tCircle();
        ~tCircle();
        int getr() const;
        void setr(int tmp);
        void move();
};

#endif
