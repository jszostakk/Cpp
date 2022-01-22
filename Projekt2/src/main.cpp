#include <iostream>
#include "../include/lib.h"
#include "../include/Entity.h"
#include "../include/Hero.h"
#include "../include/Enemy.h"

int main(int argc, char *argv[]){
    string order = argv[1];
    double difficulty;

    if(order == "help") {
        help();
        return 0;
    }

    else if(order == "easy")
        difficulty = 1.5;

    else if(order == "medium")
        difficulty = 2;

    else if(order == "hard")
        difficulty = 3;
    else {
        help();
        return 0;
    }
string h;
    cin>>h;
    toLowerCase(h);
    cout<<h;
//    Hero player;
//    player.levelUp();
//    Enemy *enemy = new Enemy(2, difficulty);
//    enemy->showStats();
//    tavern();
    vector<string> vector;
    getFile("C:\\Users\\Kuba\\CLionProjects\\JiPP2\\Projekt2\\missions", vector);
}