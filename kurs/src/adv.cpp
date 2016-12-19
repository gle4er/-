#include  "../headers/kurs.h"
#include "../headers/class.h"

float koeff(Hero *hero);
void fight(Hero *hero);
void food(Hero *hero);
void run(Hero *hero);

float koeff(Hero *hero, int mob)
{
    return randomiwe() % mob + hero->getMHP() / 4 - hero->getXP() / 5;
}

void run(Hero *hero)
{
    int stat = randomiwe() % 3;
    switch (stat) {
        case 0:
            std::cout<<"Форест сбежал, но устал. -1 к скорости"<<std::endl;
            hero->setSP(hero->getSP() - 1);
            break;
        case 1:
            std::cout<<"Форест сбежал и бежит со всех мочей"<<std::endl;
            break;
        case 2:
            std::cout<<"Тут герой понял, что похудел. +1 к скорости"<<std::endl;
			hero->setSP(hero->getSP() + 1);
            break;
    }
    hero->setXP(hero->getXP() + 1);
}

void makeAdventure(Hero *hero)
{
    int event = randomiwe() % 2;
    switch (event) {
        case 0:
            fight(hero);
            break;
        case 1:
            food(hero);
            break;
    }
}

void fight(Hero *hero)
{
    int event = randomiwe() % 3;
    int stat = randomiwe() % 2;
    switch (event) {
        case 0: {
            std::cout<<"Встречен ботаник, который хотел разобрать "<<
                hero->getName()<<" на органы"<<std::endl;
            Enemy *botan = new Enemy(2 * koeff(hero, 1), 1 * koeff(hero, 1),
                    3 * koeff(hero, 1));
            if (stat && hero->getSP() > botan->getSP()) {
                run(hero);
                break;
            }
            while (hero->getHP() > 0 && botan->getHP() > 0) {
                int luck = randomiwe() % 2;
                if (luck)
                    botan->setHP(botan->getHP() - hero->getDMG());
                luck = randomiwe() % 2;
                if (luck)
                    hero->setHP(-botan->getDMG());
            }
            if (hero->getHP() > 0)
                hero->setXP(hero->getXP() + 2);
            break;
        }
        case 1: {
            std::cout<<"А вот и хульган подошёл"<<std::endl;
            Enemy *gop = new Enemy(3 * koeff(hero, 2), 2 * koeff(hero, 2),
                    2 * koeff(hero, 2));
            if (stat && hero->getSP() > gop->getSP()) {
                run(hero);
                break;
            }
            while (hero->getHP() > 0 && gop->getHP() > 0) {
                int luck = randomiwe() % 2;
                if (luck)
                    gop->setHP(gop->getHP() - hero->getDMG());
                luck = randomiwe() % 2;
                if (luck)
                    hero->setHP(-gop->getDMG());
            }
            if (hero->getHP() > 0)
            hero->setXP(hero->getXP() + 3);
            break;
        }
        case 2: {
            std::cout<<"Брат и сестра решили показать кто здесь главный..."<<std::endl;
            std::vector <Enemy*> bro = {new Enemy(3 * koeff(hero, 1), 2 * koeff(hero, 1), 1 * koeff(hero, 1)), new Enemy(2 * koeff(hero, 1), 1 * koeff(hero, 1), 5 * koeff(hero, 2))};
            if (stat && hero->getSP() > bro[1]->getSP()) {
                run(hero);
                break;
            }
            while (hero->getHP() > 0 && (bro[0]->getHP() > 0 || bro[1]->getHP() > 0)) {
                for (int i = 0; i < 2; i++) {
                    int luck = randomiwe() % 2;
                    if (luck)
                        bro[i]->setHP(bro[i]->getHP() - hero->getDMG());
                    luck = randomiwe() % 2;
                    if (luck)
                        hero->setHP(-bro[i]->getDMG());
                }
            }
            if (hero->getHP() > 0)
                hero->setXP(hero->getXP() + 4);
            break;
        }
    }
    sleep(2);
}

void food(Hero *hero)
{
    int event = randomiwe() % 5;
    switch (event) {
        case 0:
            std::cout<<"Ничего интересного, день как день, идём дальше"<<std::endl;
            break;
        case 1:
            std::cout<<"Поднят пирожок. +3 к здоровью"<<std::endl;
            hero->setHP(3);
            break;
        case 2:
            std::cout<<"Поднята шаурма. +1 к максимуму здоровья, +1 к здоровью"<<std::endl;
            hero->setMHP(hero->getMHP() + 1);
            hero->setHP(1);
            break;
        case 3:
            std::cout<<"После очередной шаурмы, "<<hero->getName()<<" отравился. -3 к здоровью"<<std::endl;
            hero->setHP(-3);
            break;
        case 4:
            std::cout<<"Привет от МакДака. -1 к максимуму здоровья"<<std::endl;
            hero->setHP(-1);
            break;
    }
    sleep(2);
}    

