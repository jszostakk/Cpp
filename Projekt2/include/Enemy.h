#ifndef ZESTAW1_ENEMY_H
#define ZESTAW1_ENEMY_H

#include "Entity.h"
#include "time.h"

using namespace std;

class Enemy : public Entity {
public:
    Enemy(int level, double difficulty);
    ~Enemy();

    void showStats();
};


#endif //PROJEKT2_ENEMY_H
