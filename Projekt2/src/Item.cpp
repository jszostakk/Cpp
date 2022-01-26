#include "../include/Item.h"

using namespace std;

Item::Item() {
    name = "none";
    cost = 0;
    damage = 0;
    hp = 0;
    type = "none";
}

Item::Item(string name, int cost, int damage, int hp, string type) {
    this->name = name;
    this->cost = cost;
    this->damage = damage;
    this->hp = hp;
    this->type = type;
}

int Item::getCost() {
    return cost;
}

void Item::setCost(int cost) {
    this->cost = cost;
}

int Item::getDamage() {
    return damage;
}

void Item::setDamage(int damage) {
    this->damage = damage;
}

int Item::getHP() {
    return hp;
}

void Item::setHP(int hp) {
    this->hp = hp;
}

string Item::getName() {
    return name;
}

void Item::setName(string name) {
    this->name = name;
}

string Item::getType() {
    return type;
}

void Item::setType(string type) {
    this->type = type;
}