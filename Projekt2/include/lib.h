#include "Hero.h"
#include "Enemy.h"
#include "Exception.h"
#include "time.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <unistd.h>

using namespace std;

double checkDifficulty(string order);

void help();

void fight(Hero &hero);

void fight(Hero &hero, Enemy *enemy);

void tavern(Hero &hero, vector<string> &vector, double difficulty, Item items[], Item equipment[], Item backpack[]);

int mission(Hero &hero, vector<string> &vector, int level, double difficulty);

void shop(Hero &hero, Item items[], Item equipment[], Item backpack[]);

void heroF(Hero &hero, Item equipment[], Item backpack[]);

void getFile(string file, vector<string> &vector);

template<typename T>
bool whatsBigger(T a, T b) {
    cout << "Guess which is bigger: \n-a\n-b\n-equal" << endl;
    string choice;
    while (1) {
        cin >> choice;
        if (choice == "a" || choice == "b" || choice == "equal")
            break;
    }
    if (choice == "a" && a > b) {
        cout << "Congratulations!" << endl;
        return true;
    } else if (choice == "b" && b > a) {
        cout << "Congratulations!" << endl;
        return true;
    } else if (choice == "equal" && a == b) {
        cout << "Congratulations!" << endl;
        return true;
    }
    cout << "Maybe next time!" << endl;
    return false;
}

int gambling(Hero hero);

void itemsArray(Item items[], vector<string> &sitems);

void toLower(string &string);