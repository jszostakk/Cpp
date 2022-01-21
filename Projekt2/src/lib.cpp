#include "../include/lib.h"
#include "../include/Entity.h"
#include <iostream>
#include <unistd.h>

using namespace std;

void help() {
    cout << "        ==Welcome in the game!==\n"
            "Choose difficulty by modifying argument as: \n"
            "- 'easy'\n"
            "- 'medium'\n"
            "- 'hard'" << endl;
}

bool fight(Hero hero) {
    Hero mirror = hero;
    srand(time(NULL));
    int heroHp = hero.getHP();
    int round = 0;
    cout << "Fight with your mirror image has started!" << endl;
    while (1) {
        round++;
        usleep(150000);
        cout << "Round " << round << "." << endl;
        int heroDamage = (rand() % (hero.getDamageMax() - hero.getDamageMin())) + hero.getDamageMin();
        cout << "Mirror image has " << mirror.getHP() << " hp left" << endl;
        mirror.setHP(mirror.getHP() - heroDamage);
        cout << "Dealt " << heroDamage << " damage to your mirror image" << endl;
        cout << "Mirror image has " << mirror.getHP() << " hp left" << endl;
        if (mirror.getHP() <= 0) {
            cout << "You win this fight!" << endl;
            return true;
        } else {
            int enemyDamage = (rand() % (mirror.getDamageMax() - mirror.getDamageMin())) + mirror.getDamageMin();
            cout << "You have " << heroHp << " hp left" << endl;
            heroHp -= enemyDamage;
            cout << "You lost " << enemyDamage << " hp" << endl;
            cout << "Now you have " << heroHp << " hp left" << endl;
            if (heroHp <= 0)
                return false;
        }
    }
}

bool fight(Hero hero, Enemy *enemy) {
    srand(time(NULL));
    int heroHp = hero.getHP();
    int round = 0;
    cout << "Fight has started!\n" << endl;
    while (1) {
        round++;
        usleep(150000);
        cout << "\nRound " << round << "." << endl;
        int heroDamage = (rand() % (hero.getDamageMax() - hero.getDamageMin())) + hero.getDamageMin();
        cout << "\n" << enemy->getName() << " has " << enemy->getHP() << " hp left" << endl;
        enemy->setHP(enemy->getHP() - heroDamage);
        cout << "Dealt " << heroDamage << " damage to " << enemy->getName() << endl;
        cout << enemy->getName() << " has " << enemy->getHP() << " hp left" << endl;
        if (enemy->getHP() <= 0) {
            cout << "\nYou win this fight!" << endl;
            return true;
        } else {
            int enemyDamage = (rand() % (enemy->getDamageMax() - enemy->getDamageMin())) + enemy->getDamageMin();
            cout << "\nYou have " << heroHp << " hp left" << endl;
            heroHp -= enemyDamage;
            cout << "You lost " << enemyDamage << " hp" << endl;
            cout << "Now you have " << heroHp << " hp left" << endl;
            if (heroHp <= 0)
                return false;
        }
    }
}