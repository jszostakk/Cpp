#include <iostream>
#include "../include/lib.h"
#include "../include/Hero.h"
#include "../include/Enemy.h"

using namespace std;

int main(int argc, char *argv[]){
    string order = argv[1];
    double difficulty;

    if(order == "help")
        help();

    else if(order == "easy")
        difficulty = 0.75;

    else if(order == "medium")
        difficulty == 1;

    else if(order == "hard")
        difficulty = 1.5;
    else
        help();

    Hero player;

}