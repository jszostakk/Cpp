#include "../include/lib.h"

using namespace std;

double checkDifficulty(string order) {
    if (order == "help") {
        help();
    } else if (order == "easy")
        return 1.5;

    else if (order == "medium")
        return 2;

    else if (order == "hard")
        return 3;
    else {
        help();
    }
}

void help() {
    cout << "        ==Welcome in the game!==\n"
            "Choose difficulty by modifying argument as: \n"
            "- 'easy'\n"
            "- 'medium'\n"
            "- 'hard'" << endl;
    exit(0);
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

string tavern(Hero hero, vector<string> &missions, int level, double difficulty) {
    cout << "=====================================WELCOME IN TAVERN=====================================" << endl;
    while (hero.getLevel() < 10) {
        cout << "                                       Choose action:\n"
                "                               -Mission           (type 'mission')\n"
                "                               -Mirror arena      (type 'mirror')\n"
                "                               -Shop              (type 'shop')\n"
                "                               -Your character    (type 'hero')\n"
                "                               -Gambler           (type 'gambling')\n"
                "                               -Exit game         (type 'exit')\n" << endl;
        string choice;
        cin >> choice;
        for_each(choice.begin(), choice.end(), [](char &c) {
            c = ::tolower(c);
        });
        if (choice == "mission") {
            hero.setMoney(hero.getMoney() + mission(hero, missions, hero.getLevel(), difficulty));
            hero.levelUp();
        } else if (choice == "mirror")
            fight(hero);
        else if (choice == "shop")
            return "shop";
        else if (choice == "hero")
            hero.showStats();
        else if (choice == "gambling")
            hero.setMoney(hero.getMoney() + gambling(hero));
        else if (choice == "exit")
            exit(420);
        else
            cout << "There is no such command!" << endl;
    }
    cout << "########################################################################################\n"
            "####################################### YOU WON! #######################################\n"
            "########################################################################################\n"
            "############################# You have reached 10th level! #############################\n"
            "########################################################################################" << endl;
    exit(0);
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
        int k = rand() % (21 / 3);
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

int gambling(Hero hero) {
    srand(time(NULL));
    int amount;
    cout << "How much money to invest: ";
    cin >> amount;
    while (amount > hero.getMoney()) {
        cout << "You are not rich enough!\n How much money to invest: ";
        cin >> amount;
    }
    int a = rand() % 10;
    int b = rand() % 10;
    if (whatsBigger<int>(a, b))
        return amount;
    else
        return -amount;
}

void itemsArray(Item items[], vector<string> &sitems){
    //std::string::size_type sz;
    int j = 0;
    for (int i = 1; i <= 59; i++) {
        Item temp;

        temp.setName(sitems[5*j+i]);
        temp.setCost(atof(sitems[5*j+i + 1].c_str()));
        temp.setDamage(atof(sitems[5*j+i + 2].c_str()));
        temp.setHP(atof(sitems[5*j+i + 3].c_str()));
        temp.setType(sitems[5*j+i + 4]);

        items[j] = temp;
        j++;
    }
}