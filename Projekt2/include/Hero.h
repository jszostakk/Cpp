#ifndef PROJEKT2_HERO_H
#define PROJEKT2_HERO_H

#include "Entity.h"
#include "Item.h"

class Hero : public Entity {
protected:
    int money;

    Item *equipment;

    Item *backpack;
public:
    Hero();

    ~Hero();

    void setMoney(int money);

    int getMoney();

    void showStats();

    void levelUp();

    void buyItem(Item item);

    void sellItem(Item item);

    void equipItem(Item item);

    void unequipItem(Item item);
};


#endif //PROJEKT2_HERO_H
