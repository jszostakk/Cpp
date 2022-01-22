#ifndef ZESTAW1_HERO_H
#define ZESTAW1_HERO_H

#include "Entity.h"

class Hero : public Entity {
protected:
    int money;
public:
    Hero();

    ~Hero();

    void setMoney(int money);

    int getMoney();

    void showStats();

    void levelUp();
};


#endif //PROJEKT2_HERO_H