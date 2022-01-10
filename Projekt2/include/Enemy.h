#ifndef ZESTAW1_ENEMY_H
#define ZESTAW1_ENEMY_H

#include "Entity.h"

using namespace std;

class Enemy:public Entity {
public:
    Enemy();

    void showStats();
};


#endif //ZESTAW1_ENEMY_H
