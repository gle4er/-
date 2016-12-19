#include "../headers/hero.h"

Hero::Hero(std::string name)
{
    setMHP(randomiwe() % 20);
    setHP(getMHP());
    setDMG(randomiwe() % 10);
    setSP(randomiwe() % 20);
    setXP(0);
    setName(name);
}

Hero::Hero() : People() {}

Hero::~Hero()
{
    std::cout<<"Взглянем на статистику"<<std::endl;
    std::cout<<"Набрано опыта: "<<getXP()<<std::endl;
    std::cout<<"Скорость (ловкость): "<<getSP()<<std::endl;
    std::cout<<"Урон, что мог нанести "<<getName()<<": "<<getDMG()<<std::endl;
    std::cout<<"Максимум здоровья "<<getName()<<": "<<getMHP()<<std::endl;
}

int Hero::getMHP() const
{
    return mhp;
}

void Hero::setMHP(int tmp)
{
    mhp = tmp;
    if (getMHP() < getHP())
        hp = mhp;
}

void Hero::setHP(int tmp)
{
    if ((getHP() + tmp) > getMHP())
        hp = getMHP();
    else
        hp = getHP() + tmp;
}

int Hero::getXP() const
{
    return xp;
}

void Hero::setXP(int tmp)
{
    xp = tmp;
}
