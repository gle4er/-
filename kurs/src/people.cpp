#include "../headers/people.h"

People::People(int hp, int dmg, int sp)
{
    setHP(hp);
    setSP(sp);
    setDMG(dmg);
}

People::People()
{
}

People::~People()
{
}

void People::setHP(int tmp)
{
    hp = tmp;
}

void People::setDMG(int tmp)
{
    dmg = tmp;
}

void People::setSP(int tmp)
{
    sp = tmp;
}

void People::setName(std::string tmp)
{
    name = tmp;
}

int People::getHP() const
{
    return hp;
}

int People::getDMG() const
{
    return dmg;
}

int People::getSP() const
{
    return sp;
}

std::string People::getName() const
{
    return name;
}
