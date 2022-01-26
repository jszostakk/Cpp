#ifndef PROJEKT2_ENTITY_H
#define PROJEKT2_ENTITY_H

#include <iostream>
#include "stdlib.h"
#include <cstring>

using namespace std;

class Entity {
protected:
    int hp;
    int damageMin;
    int damageMax;
    int level;
    string name;

public:
    Entity();

    void setHP(int hp);

    int getHP();

    void setDamageMin(int dmg);

    int getDamageMin();

    void setDamageMax(int dmg);

    int getDamageMax();

    void setLevel(int level);

    int getLevel();

    void setName(string name);

    string getName();

    virtual void showStats() = 0;
};


#endif //PROJEKT2_ENTITY_H
