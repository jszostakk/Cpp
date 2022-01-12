//
// Created by Kuba on 10.01.2022.
//

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
    int *pHp = &hp;
    int *pDamageMin = &damageMin;
    int *pDamageMax = &damageMax;
    int *pLevel = &level;
    string *pName = &name;

    Entity();

    void setHP(int hp);

    int getHp();

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
