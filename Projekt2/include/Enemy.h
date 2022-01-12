#ifndef ZESTAW1_ENEMY_H
#define ZESTAW1_ENEMY_H

#include "Entity.h"
#include "time.h"

using namespace std;

class Enemy : public Entity {
public:
    Enemy(int level);

    void showStats();
};


#endif //ZESTAW1_ENEMY_H
