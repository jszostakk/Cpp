#include "../include/lib.h"
#include "../include/Hero.h"
#include "../include/Enemy.h"

using namespace std;

void help() {
    cout << "        ==Welcome in the game!==\n"
            "Choose difficulty by modifying argument as: \n"
            "- 'easy'\n"
            "- 'medium'\n"
            "- 'hard'" << endl;
}

bool fight(Hero hero) {
    Hero mirror = hero;
    srand(time(NULL));
    int heroHp = hero.getHP();
    int round = 0;
    cout << "Fight with your mirror image has started!" << endl;
    while (1) {
        round++;
        usleep(250000);
        cout << "\nRound " << round << "." << endl;
        int heroDamage = (rand() % (hero.getDamageMax() - hero.getDamageMin())) + hero.getDamageMin();
        cout << "\nMirror image has " << mirror.getHP() << " hp left" << endl;
        mirror.setHP(mirror.getHP() - heroDamage);
        cout << "Dealt " << heroDamage << " damage to your mirror image" << endl;
        cout << "Mirror image has " << mirror.getHP() << " hp left" << endl;
        if (mirror.getHP() <= 0) {
            cout << "\nYou win this fight!" << endl;
            return true;
        } else {
            int enemyDamage = (rand() % (mirror.getDamageMax() - mirror.getDamageMin())) + mirror.getDamageMin();
            cout << "\nYou have " << heroHp << " hp left" << endl;
            heroHp -= enemyDamage;
            cout << "You lost " << enemyDamage << " hp" << endl;
            cout << "Now you have " << heroHp << " hp left" << endl;
            if (heroHp <= 0)
                return false;
        }
    }
}

bool fight(Hero hero, Enemy *enemy) {
    srand(time(NULL));
    int heroHp = hero.getHP();
    int round = 0;
    cout << "Fight has started!\n" << endl;
    while (1) {
        round++;
        usleep(2500000);
        cout << "\nRound " << round << "." << endl;
        int heroDamage = (rand() % (hero.getDamageMax() - hero.getDamageMin())) + hero.getDamageMin();
        cout << "\n" << enemy->getName() << " has " << enemy->getHP() << " hp left" << endl;
        enemy->setHP(enemy->getHP() - heroDamage);
        cout << "Dealt " << heroDamage << " damage to " << enemy->getName() << endl;
        cout << enemy->getName() << " has " << enemy->getHP() << " hp left" << endl;
        if (enemy->getHP() <= 0) {
            cout << "\nYou win this fight!" << endl;
            return true;
        } else {
            int enemyDamage = (rand() % (enemy->getDamageMax() - enemy->getDamageMin())) + enemy->getDamageMin();
            cout << "\nYou have " << heroHp << " hp left" << endl;
            heroHp -= enemyDamage;
            cout << "You lost " << enemyDamage << " hp" << endl;
            cout << "Now you have " << heroHp << " hp left" << endl;
            if (heroHp <= 0)
                return false;
        }
    }
}

string tavern(Hero hero, vector<string> &vector, int level, double difficulty) {
    cout << "=====================================WELCOME IN TAVERN=====================================" << endl;
    while (1) {
        cout << "                                       Choose action:\n"
                "                               -Mission           (type 'mission')\n"
                "                               -Mirror arena      (type 'mirror')\n"
                "                               -Shop              (type 'shop')\n"
                "                               -Your character    (type 'hero')\n"
                "                               -Wheel of Fortune  (type 'wheel')\n" << endl;
        string choice;
        cin >> choice;
        for_each(choice.begin(), choice.end(), [](char &c) {
            c = ::tolower(c);
        });
        if (choice == "mission") {
            hero.setMoney(hero.getMoney() + mission(hero, vector, hero.getLevel(), difficulty));
            hero.levelUp();
        }
        else if (choice == "mirror")
            fight(hero);
        else if (choice == "shop")
            return "shop";
        else if (choice == "hero")
            hero.showStats();
        else if (choice == "wheel")
            return "wheel";
    }
}

void getFile(string file, vector<string> &vector) {
    ifstream in(file.c_str());
    if (!in) {
        cerr << "Error with opening the file: " << file << endl;
    }

    string str;
    while (getline(in, str)) {
        if (str.size() > 0)
            vector.push_back(str);
    }

    in.close();
}

int mission(Hero hero, vector<string> &vector, int level, double difficulty) {
    srand(time(NULL));
    string missions[9];
    int choice;

    for (int i = 0; i < 9; i += 3) {
        int k = rand() % ((sizeof(vector)) / 3);
        missions[i] = vector[k * 3];
        missions[i + 1] = vector[k * 3 + 1];
        missions[i + 2] = vector[k * 3 + 2];
    }
    cout << "Choose mission:\n"
            "1. Name: " << missions[0] << "  Reward: " << missions[1] << "&  Time: " << missions[2] << "s\n" <<
         "2. Name: " << missions[3] << "  Reward: " << missions[4] << "&  Time: " << missions[5] << "s\n" <<
         "3. Name: " << missions[6] << "  Reward: " << missions[7] << "&  Time: " << missions[8] << "s\n" << endl;
    cin >> choice;
    if (choice == 1) {
        double seconds = atof(missions[2].c_str()) * 1000000;
        usleep(seconds);
        Enemy *enemy = new Enemy(level, difficulty);
        fight(hero, enemy);
        return atof(missions[1].c_str());
    } else if (choice == 2) {
        double seconds = atof(missions[5].c_str()) * 1000000;
        usleep(seconds);
        Enemy *enemy = new Enemy(level, difficulty);
        fight(hero, enemy);
        return atof(missions[4].c_str());
    } else if (choice == 3) {
        double seconds = atof(missions[8].c_str()) * 1000000;
        usleep(seconds);
        Enemy *enemy = new Enemy(level, difficulty);
        fight(hero, enemy);
        return atof(missions[7].c_str());
    }
}