#include "../include/lib.h"

int main(int argc, char *argv[]) {

    if (argv[1] == NULL)
        help();

    double difficulty = checkDifficulty(argv[1]);

    vector<string> sitems;
    vector<string> missions;

    Item *equipment = new Item[2];
    equipment[0] = {"none",0,0,0,"none"};
    equipment[1] = {"none",0,0,0,"none"};
    Item *backpack = new Item[4];
    backpack[0] = {"none",0,0,0,"none"};
    backpack[1] = {"none",0,0,0,"none"};
    backpack[2] = {"none",0,0,0,"none"};
    backpack[3] = {"none",0,0,0,"none"};

    Hero player;

    try{
        player.getName();
    } catch(Exception& e){
        cout<<e.what()<<endl;
        exit(-1);
    }

    getFile("K:\\Projekt2\\missions", missions);
    getFile("K:\\Projekt2\\items", sitems);

    Item items[10];
    itemsArray(items, sitems);

    tavern(player, missions, difficulty, items, equipment, backpack);

    return 0;
}