#include "../include/lib.h"

using namespace std;

double checkDifficulty(string order) {
    if (order == "help") {
        help();
        exit(0);
    } else if (order == "easy")
        return 1.5;

    else if (order == "medium")
        return 2;

    else if (order == "hard")
        return 3;
    else {
        help();
        exit(0);
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

void fight(Hero &hero) {
    Hero mirror = hero;
    srand(time(NULL));
    int heroHp = hero.getHP();
    int round = 0;
    cout << "Fight with your mirror image has started!" << endl;
    while (1) {
        round++;
        //usleep(1500000);
        cout << "\nRound " << round << "." << endl;
        int heroDamage = (rand() % (hero.getDamageMax() - hero.getDamageMin())) + hero.getDamageMin();
        cout << "\nMirror image has " << mirror.getHP() << " hp left" << endl;
        mirror.setHP(mirror.getHP() - heroDamage);
        cout << "Dealt " << heroDamage << " damage to your mirror image" << endl;
        cout << "Mirror image has " << mirror.getHP() << " hp left" << endl;
        if (mirror.getHP() <= 0) {
            cout << "\nYou win this fight!" << endl;
            break;
        } else {
            int enemyDamage = (rand() % (mirror.getDamageMax() - mirror.getDamageMin())) + mirror.getDamageMin();
            cout << "\nYou have " << heroHp << " hp left" << endl;
            heroHp -= enemyDamage;
            cout << "You lost " << enemyDamage << " hp" << endl;
            cout << "Now you have " << heroHp << " hp left" << endl;
            if (heroHp <= 0) {
                cout << "You lost!" << endl;
                exit(0);
            }
        }
    }
}

void fight(Hero &hero, Enemy *enemy) {
    srand(time(NULL));
    int heroHp = hero.getHP();
    int round = 0;
    cout << "Fight has started!\n" << endl;
    while (enemy->getHP() > 0 && hero.getHP() > 0) {
        round++;
        //usleep(1500000);
        cout << "\nRound " << round << "." << endl;
        int heroDamage = (rand() % (hero.getDamageMax() - hero.getDamageMin())) + hero.getDamageMin();
        cout << "\n" << enemy->getName() << " has " << enemy->getHP() << " hp left" << endl;
        enemy->setHP(enemy->getHP() - heroDamage);
        cout << "Dealt " << heroDamage << " damage to " << enemy->getName() << endl;
        cout << enemy->getName() << " has " << enemy->getHP() << " hp left" << endl;
        if (enemy->getHP() <= 0) {
            cout << "\nYou win this fight!" << endl;
        } else {
            int enemyDamage = (rand() % (enemy->getDamageMax() - enemy->getDamageMin())) + enemy->getDamageMin();
            cout << "\nYou have " << heroHp << " hp left" << endl;
            heroHp -= enemyDamage;
            cout << "You lost " << enemyDamage << " hp" << endl;
            cout << "Now you have " << heroHp << " hp left" << endl;
            if (heroHp <= 0) {
                cout << "You lost!" << endl;
                exit(0);
            }
        }
    }
}

void tavern(Hero &hero, vector<string> &missions, double difficulty, Item items[], Item equipment[], Item backpack[]) {
    cout << "===================================== WELCOME TO TAVERN =====================================" << endl;
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
        toLower(choice);
        if (choice == "mission") {
            hero.setMoney(hero.getMoney() + mission(hero, missions, hero.getLevel(), difficulty));
            hero.levelUp();
        } else if (choice == "mirror")
            fight(hero);
        else if (choice == "shop")
            shop(hero, items, equipment, backpack);
        else if (choice == "hero")
            heroF(hero, equipment, backpack);
        else if (choice == "gambling")
            hero.setMoney(hero.getMoney() + gambling(hero));
        else if (choice == "exit")
            exit(0);
        else
            cout << "There is no such command!" << endl;
    }
    cout << "   ########################################################################################\n"
            "   ####################################### YOU WON! #######################################\n"
            "   ########################################################################################\n"
            "   ############################# You have reached 10th level! #############################\n"
            "   ########################################################################################" << endl;
}

void shop(Hero &hero, Item items[], Item equipment[], Item backpack[]) {
    while (1) {
        cout << "===================================== SHOP =====================================" << endl;
        for (int i = 0; i < 10; i++) {
            cout << i << ". Name: " << items[i].getName() <<
                 "\nCost: " << items[i].getCost() << "&" << endl;
            if (items[i].getType() == "weapon")
                cout << "Damage: " << items[i].getDamage() << endl;
            else if (items[i].getType() == "armor")
                cout << "HP: " << items[i].getHP() << endl;
        }
        cout << "\n                               Choose action:\n"
                "                               -buy\n"
                "                               -exit\n\n"
                "                               Your choice: ";

        string choice;
        cin >> choice;
        toLower(choice);

        if (choice == "buy") {
            while (1) {
                cout << "\nInsert name of item you want to buy. "
                        "If you want to exit type 'exit'" << endl;
                string name;
                cin >> name;
                toLower(name);
                if (name == "exit")
                    break;
                else {
                    bool noSuchItem = true;
                    for (int i = 0; i < 10; i++) {
                        string temp = items[i].getName();
                        toLower(temp);
                        if (name == temp) {
                            hero.buyItem(items[i], backpack);
                            noSuchItem = false;
                        }
                    }
                    if (noSuchItem)
                        cout << "There is no such item!" << endl;
                }
            }
        } else if (choice == "exit")
            break;
    }
}

void heroF(Hero &hero, Item equipment[], Item backpack[]) {
    while (1) {
        cout << "                               \nChoose action:\n"
                "                               -stats\n"
                "                               -equip\n"
                "                               -unequip\n"
                "                               -sell\n"
                "                               -exit" << endl;

        string choice;
        cin >> choice;
        toLower(choice);


        if (choice == "stats") {
            hero.showStats();
            hero.showEq(equipment, backpack);
        } else if (choice == "equip") {
            bool noSuchItem = true;
            string itemChoice;
            cout << "Insert name of item you want to equip: ";
            cin >> itemChoice;
            toLower(itemChoice);
            for (int i = 0; i < 4; i++) {
                string temp = backpack[i].getName();
                toLower(temp);
                if (itemChoice == temp) {
                    noSuchItem = false;
                    hero.equipItem(backpack[i], equipment, backpack);
                    break;
                }
            }
            if (noSuchItem)
                cout << "There is no such item!" << endl;
        } else if (choice == "unequip") {
            bool noSuchItem = true;
            string itemChoice;
            cout << "Insert name of item you want to unequip: ";
            cin >> itemChoice;
            toLower(itemChoice);
            for (int i = 0; i < 2; i++) {
                string temp = equipment[i].getName();
                toLower(temp);
                if (itemChoice == temp) {
                    noSuchItem = false;
                    hero.unequipItem(equipment[i], equipment, backpack);
                    break;
                }
            }
            if (noSuchItem)
                cout << "There is no such item!" << endl;

        } else if (choice == "sell") {
            bool noSuchItem = true;
            string itemChoice;
            cout << "Insert name of item you want to sell: ";
            cin >> itemChoice;
            toLower(itemChoice);
            for (int i = 0; i < 4; i++) {
                string temp = backpack[i].getName();
                toLower(temp);
                if (itemChoice == temp) {
                    noSuchItem = false;
                    hero.sellItem(backpack[i], backpack);
                    break;
                }
            }
            if (noSuchItem)
                cout << "There is no such item!" << endl;
        } else if (choice == "exit")
            break;
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

int mission(Hero &hero, vector<string> &vector, int level, double difficulty) {
    srand(time(NULL));
    string missions[9];
    string choice;

    for (int i = 0; i < 9; i += 3) {
        int k = rand() % (21 / 3);
        missions[i] = vector[k * 3];
        missions[i + 1] = vector[k * 3 + 1];
        missions[i + 2] = vector[k * 3 + 2];
    }

    while (choice != "1" || choice != "2" || choice != "3") {
        cout << "\nChoose mission:\n"
                "1. Name: " << missions[0] << "  Reward: " << missions[1] << "&  Time: " << missions[2] << "s\n" <<
             "2. Name: " << missions[3] << "  Reward: " << missions[4] << "&  Time: " << missions[5] << "s\n" <<
             "3. Name: " << missions[6] << "  Reward: " << missions[7] << "&  Time: " << missions[8] << "s\n" << endl;

        cout << "Insert your choice: ";
        cin >> choice;

        if (choice == "1") {
            double seconds = stoi(missions[2]) * 1000000;
            usleep(seconds);
            Enemy *enemy = new Enemy(level, difficulty);
            fight(hero, enemy);
            delete enemy;
            return stoi(missions[1]);
        } else if (choice == "2") {
            double seconds = stoi(missions[5]) * 1000000;
            usleep(seconds);
            Enemy *enemy = new Enemy(level, difficulty);
            fight(hero, enemy);
            delete enemy;
            return stoi(missions[4]);
        } else if (choice == "3") {
            double seconds = stoi(missions[8]) * 1000000;
            usleep(seconds);
            Enemy *enemy = new Enemy(level, difficulty);
            fight(hero, enemy);
            delete enemy;
            return stoi(missions[7]);
        } else
            cout << "Wrong input!" << endl;
    }
    return 0;
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

void itemsArray(Item items[], vector<string> &sitems) {
    int i = 0;
    for (int j = 0; j < 10; j++) {
        items[j].setName(sitems[i++]);
        items[j].setCost(stoi(sitems[i++]));
        items[j].setDamage(stoi(sitems[i++]));
        items[j].setHP(stoi(sitems[i++]));
        items[j].setType(sitems[i++]);
    }
}

void toLower(string &string) {
    for_each(string.begin(), string.end(), [](char &c) {
        c = ::tolower(c);
    });
}