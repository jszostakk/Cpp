#include "../include/Enemy.h"

Enemy::Enemy(int level) {
    srand(time(NULL));
    cout << "A new enemy has attacked!" << endl;
    this->level = level;
    hp = 10;
    damageMin = 1;
    damageMax = 4;
    for (int i = 0; i < level; i++) {
        int stat = rand() % 1;
        if (stat == 0)
            hp += 3;
        else {
            damageMin += 2;
            damageMax += 2;
        }
    }
}

