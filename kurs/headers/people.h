//базовый класс
#ifndef PEOPLE
#define PEOPLE

#include <iostream>
#include <string>

uint64_t randomiwe(void);

class People
{
    protected:
        int hp, dmg, sp;
        std::string name;
    public:
        virtual ~People();
        People();
        People(int hp, int dmg, int sp);
        void setHP(int tmp);
        int getHP() const;
        void setDMG(int tmp);
        int getDMG() const;
        void setName(std::string tmp);
        std::string getName() const;
        int getSP() const;
        void setSP(int tmp);
};

#endif
