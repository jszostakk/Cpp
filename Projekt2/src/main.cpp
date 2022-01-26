#include "../include/lib.h"

int main(int argc, char *argv[]) {

    if (argv[1] == NULL)
        help();

    double difficulty = checkDifficulty(argv[1]);

    vector<string> sitems;
    vector<string> missions;

    //Hero player;

    getFile("C:\\Users\\Kuba\\CLionProjects\\JiPP2\\Projekt2\\missions", missions);
    getFile("C:\\Users\\Kuba\\CLionProjects\\JiPP2\\Projekt2\\items", sitems);

    Item items[10];
    itemsArray(items,sitems);
//    for(int i = 0; i <10; i++){
//        cout<<
//        items[i].getName()<<
//        items[i].getCost()<<
//        items[i].getDamage()<<
//        items[i].getHP()<<
//        items[i].getType()<<endl;
//    }
cout<<items[0].getName();
    //tavern(player, missions, player.getLevel(), difficulty);
}