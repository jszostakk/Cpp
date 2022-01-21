#include <fstream>
#include "../include/Enemy.h"

using namespace std;

Enemy::Enemy(int level, double difficulty) {
    srand(time(NULL));
    ifstream input("C:\\Users\\Kuba\\CLionProjects\\JiPP2\\Projekt2\\names");
    cout << "A new enemy has attacked!" << endl;
    this->level = level;
    hp = 10;
    damageMin = 1;
    damageMax = 4;
    for (int i = 0; i < level; i++) {
        int stat = rand() % 2;
        if (stat == 0)
            hp += 3;
        else {
            damageMin += 2;
            damageMax += 3;
        }
    }

    for (int i = 0; i< (rand() % 8)+1; i++) {
        getline(input, name);
    }
    hp*=difficulty;
    damageMin*=difficulty;
    damageMax*=difficulty;
}

Enemy::~Enemy() {
    cout << "Fight has ended!" << endl;
}

void Enemy::showStats() {
    cout << "=====================================ENEMY STATS=====================================" << endl <<
         "                                     Name: " << name << endl <<
         "                                     Level: " << level << endl <<
         "                                     HP: " << hp << endl <<
         "                                     Damage: " << damageMin << " - " << damageMax << endl <<
         "=====================================================================================" << endl;
}