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

    Hero(Hero &hero);

    ~Hero();

    void setMoney(int money);

    int getMoney();

    void showStats();

    void showEq(Item equipment[], Item backpack[]);

    void levelUp();

    void buyItem(Item item, Item backpack[]);

    void sellItem(Item item, Item backpack[]);

    void equipItem(Item item, Item equipment[], Item backpack[]);

    void unequipItem(Item item, Item equipment[], Item backpack[]);
};


#endif //PROJEKT2_HERO_H
