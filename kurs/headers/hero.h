//описываем ГГ
#ifndef HERO
#define HERO

#include "../headers/people.h"

class Hero : public People
{
    private:
        int mhp, xp;//максимум здоровья
    public:
        Hero(std::string name);
        Hero();
        ~Hero();
        int getMHP() const;
        void setMHP(int tmp);
        void setHP(int tmp);
		void setXP(int tmp);
        int getXP() const;
};

#endif
