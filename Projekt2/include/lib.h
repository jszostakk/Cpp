#include "Hero.h"
#include "Enemy.h"
#include "Mission.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void help();

bool fight(Hero hero);

bool fight(Hero hero, Enemy *enemy);

void toLowerCase(string a);

string tavern();

int mission(Hero hero, vector<string> &vector, int level, double difficulty);

void getFile(string file, vector<string> & vector);