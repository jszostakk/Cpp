#ifndef PROJEKT2_ITEM_H
#define PROJEKT2_ITEM_H

#include "Entity.h"

using namespace std;

class Item {
protected:
    string name;
    int cost;
    int damage;
    int hp;
    string type;
public:
    Item();

    Item(string name, int cost, int damage, int hp, string type);

    int getCost();

    void setCost(int cost);

    int getDamage();

    void setDamage(int damage);

    int getHP();

    void setHP(int hp);

    string getName();

    void setName(string name);

    string getType();

    void setType(string type);
};


#endif //PROJEKT2_ITEM_H
