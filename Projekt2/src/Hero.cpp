#include "../include/Hero.h"

Hero::Hero() {
    cout << "Name your character: ";
    cin >> name;
    level = 1;
    hp = 30;
    damageMin = 3;
    damageMax = 7;
    money = 0;
}

Hero::~Hero() {
    cout << "\nYou lost :(" << endl;
}

void Hero::showStats() {
    cout << "=====================================YOUR CHARACTER STATS=====================================" << endl <<
         "                                          Name: " << name << endl <<
         "                                          Level: " << level << endl <<
         "                                          HP: " << hp << endl <<
         "                                          Damage: " << damageMin << " - " << damageMax << endl <<
         "                                          Money: " << money << " &" << endl <<
         "==============================================================================================" << endl;
}

void Hero::levelUp() {
    level += 1;
    bool loop = true;
    string choice;
    cout << "===========================================LEVEL UP===========================================" << endl;
    while (loop) {
        cout << "Choose which stat you want to upgrade: \n-HP \n-Damage \n Your choice: ";
        cin >> choice;

        if (choice == "hp" || choice == "HP") {
            hp += 5;
            loop = false;
        } else if (choice == "damage" || choice == "Damage") {
            damageMin += 2;
            damageMax += 2;
            loop = false;
        } else {
            cout << "\nERROR: Wrong input!\n" << endl;
        }
    }
    cout << "==============================================================================================" << endl;
}