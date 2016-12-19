#ifndef ENEMY
#define ENEMY

#include "../headers/people.h"

class Enemy : public People
{
    public:
        Enemy(int hp, int dmg, int sp);
};

#endif
