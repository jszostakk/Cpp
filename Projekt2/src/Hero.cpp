#include "../include/lib.h"

using namespace std;

Hero::Hero() {
    cout << "Name your character: ";
    cin >> name;
    level = 1;
    hp = 30;
    damageMin = 3;
    damageMax = 7;
    money = 0;
}

Hero::Hero(Hero &hero) {
    name = hero.getName();
    damageMin = hero.getDamageMin();
    damageMax = hero.getDamageMax();
    hp = hero.getHP();
    money = hero.getMoney();
    level = hero.getLevel();
}

Hero::~Hero() {
    cout << "Hero destroyed!" << endl;
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

void Hero::showEq(Item equipment[], Item backpack[]) {
    cout << "===================================== YOUR EQUIPMENT =====================================\n" << endl;
    if (equipment[0].getName() == "none" &&
        equipment[1].getName() == "none")
        cout << "Equipment empty!" << endl;

    else {
        for (int i = 0; i < 2; i++) {
            if (equipment[i].getName() != "name") {
                if (equipment[i].getType() == "weapon")
                    cout << "Name: " << equipment[i].getName() <<
                         " Damage: " << equipment[i].getDamage() << endl;
                else if (equipment[i].getType() == "armor")
                    cout << "Name: " << equipment[i].getName() <<
                         " HP: " << equipment[i].getHP() << endl;
            }
        }
    }

    cout << "\n===================================== YOUR BACKPACK =====================================\n" << endl;
    if (backpack[0].getName() == "none" &&
        backpack[1].getName() == "none" &&
        backpack[2].getName() == "none" &&
        backpack[3].getName() == "none")
        cout << "Backpack empty!" << endl;

    else {
        for (int i = 0; i < 4; i++) {
            if (backpack[i].getName() != "none") {
                if (backpack[i].getType() == "weapon")
                    cout << "Name: " << backpack[i].getName() <<
                         " Damage: " << backpack[i].getDamage() << endl;
                else if (backpack[i].getType() == "armor")
                    cout << "Name: " << backpack[i].getName() <<
                         " HP: " << backpack[i].getHP() << endl;
            }
        }
    }
}

void Hero::levelUp() {
    level += 1;
    bool loop = true;
    string choice;
    cout << "===========================================LEVEL UP===========================================" << endl;
    while (loop) {
        cout << "                               Choose which stat you want to upgrade: \n"
                "                               -HP \n"
                "                               -Damage \n "
                "                               Your choice: ";
        cin >> choice;
        toLower(choice);

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

void Hero::buyItem(Item item, Item backpack[]) {
    if (item.getCost() <= money) {
        bool noSpaceInBackpack = true;
        for (int i = 0; i < 4; i++) {
            if (backpack[i].getName() == "none") {
                noSpaceInBackpack = false;
                backpack[i] = item;
                money -= item.getCost();
                cout << item.getName() << " obtained!" << endl;
                break;
            }
        }
        if (noSpaceInBackpack)
            cout << "You have no space in backpack!" << endl;
    } else
        cout << "This item is too expensive!" << endl;
}

void Hero::sellItem(Item item, Item backpack[]) {
    Item none;
    for (int i = 0; i < 4; i++) {
        if (backpack[i].getName() == item.getName()) {
            backpack[i] = none;
            money += (item.getCost() / 2);
            cout << item.getName() << " sold!" << endl;
            break;
        }
    }
}

void Hero::equipItem(Item item, Item equipment[], Item backpack[]) {
    Item none;
    for (int i = 0; i < 4; i++) {
        if (item.getType() == "weapon" && item.getName() == backpack[i].getName()) {
            if (equipment[0].getName() == "none") {
                equipment[0] = item;
                backpack[i] = none;

                damageMin += item.getDamage();
                damageMax += item.getDamage();

                hp += item.getHP();

                cout << item.getName() << " equipped!" << endl;
                break;
            } else
                cout << "This slot is occupied!" << endl;
        } else if (item.getType() == "armor" && item.getName() == backpack[i].getName()) {
            if (equipment[1].getName() == "none") {
                equipment[1] = item;
                backpack[i] = none;

                damageMin += item.getDamage();
                damageMax += item.getDamage();

                hp += item.getHP();

                cout << item.getName() << " equipped!" << endl;
                break;
            } else
                cout << "This slot is occupied!" << endl;
        }
    }
}

void Hero::unequipItem(Item item, Item equipment[], Item backpack[]) {
    Item none;
    for (int i = 0; i < 4; i++) {
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
            }
        }
    }
}