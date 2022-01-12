#include "../include/lib.h"
#include <iostream>

using namespace std;

void help(){
    cout<<"help"<<endl;
}

void showStats(Hero hero){
    cout << "=====================================YOUR CHARACTER STATS=====================================" << endl <<
         "                                          Name: " << hero.getName() << endl <<
         "                                          Level: " << hero.getLevel() << endl <<
         "                                          HP: " << hero.getHp() << endl <<
         "                                          Damage: " << hero.getDamageMin() << " - " << hero.getDamageMax() << endl <<
         "                                          Money: " << hero.getMoney() << " &" << endl <<
         "==============================================================================================" << endl;
}
}