#ifndef ELLIPSE
#define ELLIPSE

#include "../headers/tPoint.h"
#include <vector>

class tEllipse : public tPoint
{
    protected:
        std::vector<tPoint*> points;
        int radx, rady;
    public:
        tEllipse();
        void setPoints(int x, int y);
        std::vector<tPoint*> getPoints() const;
        void rotate();
        void move();
};

#endif
