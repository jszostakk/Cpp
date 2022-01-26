#include "Hero.h"
#include "Enemy.h"
#include "time.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <exception>

using namespace std;

double checkDifficulty(string order);

void help();

bool fight(Hero hero);

bool fight(Hero hero, Enemy *enemy);

string tavern(Hero hero, vector<string> &vector, int level, double difficulty);

int mission(Hero hero, vector<string> &vector, int level, double difficulty);

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