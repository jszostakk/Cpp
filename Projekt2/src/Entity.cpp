#include "../include/Entity.h"
#include "../include/Exception.h"

Entity::Entity() {}

void Entity::setHP(int hp) {
    this->hp = hp;
}

int Entity::getHP() {
    return hp;
}

void Entity::setDamageMin(int dmg) {
    damageMin = dmg;
}

int Entity::getDamageMin() {
    return damageMin;
}

void Entity::setDamageMax(int dmg) {
    damageMax = dmg;
}

int Entity::getDamageMax() {
    return damageMax;
}

void Entity::setLevel(int level) {
    this->level = level;
}

int Entity::getLevel() {
    return level;
}

void Entity::setName(string name) {
    this->name = name;
}

string Entity::getName() {
    if (name.length() > 15) {
        throw Exception("ERROR: Name too long!");
    }
    return name;
}