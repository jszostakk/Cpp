#include "Hero.h"
#include "Enemy.h"
#include "Mission.h"
#include "time.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <unistd.h>
#include <algorithm>

using namespace std;

void help();

bool fight(Hero hero);

bool fight(Hero hero, Enemy *enemy);

string tavern(Hero hero, vector<string> &vector, int level, double difficulty);

int mission(Hero hero, vector<string> &vector, int level, double difficulty);

void getFile(string file, vector<string> & vector);