#include "../include/lib.h"
#include "../include/Hero.h"
#include "../include/Item.h"

using namespace std;

Hero::Hero() {
    cout << "Name your character: ";
    cin >> name;
    level = 1;
    hp = 30;
    damageMin = 3;
    damageMax = 7;
    money = 0;

    equipment = new Item[2];
    equipment = NULL;

    backpack = new Item[4];
    backpack = NULL;
}

Hero::~Hero() {
    delete[] equipment;
    delete[] backpack;
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
        for_each(choice.begin(), choice.end(), [](char &c) {
            c = ::tolower(c);
        });

        if (choice == "hp") {
            hp += 5;
            loop = false;
        } else if (choice == "damage") {
            damageMin += 2;
            damageMax += 2;
            loop = false;
        } else {
            cout << "\nERROR: Wrong input!\n" << endl;
        }
    }
    cout << "==============================================================================================" << endl;
}

int Hero::getMoney() {
    return money;
}

void Hero::setMoney(int money) {
    this->money = money;
}

void Hero::buyItem(Item item) {
    if (item.getCost() <= money) {
        for (int i = 0; i < sizeof(backpack) - 1; i++) {
            if (backpack[i].getName() == "none") {
                backpack[i] = item;
                money -= item.getCost();
                cout << item.getName() << " obtained!" << endl;
            } else
                cout << "You have no space in backpack!" << endl;
        }
    } else
        cout << "This item is too expensive!" << endl;
}

void Hero::sellItem(Item item) {
    Item none;
    for (int i = 0; i < sizeof(backpack) - 1; i++) {
        if (backpack[i].getName() == item.getName()) {
            backpack[i] = none;
            money += item.getCost() / 2;
            cout << item.getName() << " sold!" << endl;
        } else
            cout << "You dont have such item!" << endl;
    }
}

void Hero::equipItem(Item item) {
    Item none;
    for (int i = 0; i < sizeof(backpack) - 1; i++) {
        if (item.getType() == "weapon" && item.getName() == backpack[i].getName()) {
            equipment[0] = item;
            backpack[i] = none;

            damageMin += item.getDamage();
            damageMax += item.getDamage();

            hp += item.getHP();

            cout << item.getName() << " equipped!" << endl;
        } else if (item.getType() == "armor" && item.getName() == backpack[i].getName()) {
            equipment[1] = item;
            backpack[i] = none;

            damageMin += item.getDamage();
            damageMax += item.getDamage();

            hp += item.getHP();

            cout << item.getName() << " equipped!" << endl;
        } else
            cout << "You dont have such item!" << endl;
    }
}

void Hero::unequipItem(Item item) {
    Item none;
    for (int i = 0; i < sizeof(backpack) - 1; i++) {
        if (backpack[i].getName() == "none") {
            if (item.getType() == "weapon" && item.getName() == equipment[0].getName()) {
                equipment[0] = none;
                backpack[i] = item;

                damageMin -= item.getDamage();
                damageMax -= item.getDamage();

                hp -= item.getHP();

                cout << item.getName() << " unequipped!" << endl;
            } else if (item.getType() == "armor" && item.getName() == equipment[1].getName()) {
                equipment[1] = none;
                backpack[i] = item;

                damageMin -= item.getDamage();
                damageMax -= item.getDamage();

                hp -= item.getHP();

                cout << item.getName() << " unequipped!" << endl;
            } else
                cout << "You dont have equipped such item!" << endl;
        }
    }
}