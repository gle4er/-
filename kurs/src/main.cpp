#include "../headers/kurs.h"
#include "../headers/class.h"

void showStats(Hero *hero)
{
    using namespace std;
    cout<<endl;
    cout<<hero->getName()<<": "<<hero->getHP()<<"\\"<<hero->getMHP()<<" hp, "
        <<hero->getSP()<<" sp, "<<hero->getXP()<<" xp, "
        <<hero->getDMG()<<" dmg"<<endl;
    cout<<endl;
    sleep(2);
}

void intRand()
{
    extern uint64_t s[2];
    srand(time(NULL));
    s[0] = rand() % sizeof(uint64_t) + 1;
    s[1] = rand() % sizeof(uint64_t) + 1;
}

int main ()
{
    intRand();
    std::cout<<"Добро пожаловать в симуляцию мира."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Введите имя персонажу: ";
    std::string name;
    std::getline(std::cin, name);
    Hero *hero = new Hero(name);
    std::cout<<"Приятно познакомится, "<<hero->getName()<<std::endl;
    std::cout<<"А я программа, которая будет создавать случайные "<<
        "события. Так что, не зевай и предельно внимательно"<<std::endl<<
        "смотри как умирает или встаёт с колен твой герой."<<std::endl;
    sleep(2);
    std::cout<<std::endl;
    while (1) {
        showStats(hero);
        if ((hero->getHP()) <= 0 || (hero->getMHP()) <= 0) {
            std::cout<<hero->getName()<<" погиб... Эх, а ведь он был так прекрасен (нет)"<<std::endl;
            delete(hero);
            return 0;
        }
        if (hero->getXP() >= 100)
            break;
        makeAdventure(hero);
    }
    if (hero->getXP() > 30) {
        std::cout<<std::endl<<hero->getName()<<" что-то слишком поумнел для этой игры. Поэтому, игра прерывается..."<<std::endl;
        delete(hero);
    }
    return 0;
}
