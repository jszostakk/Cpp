#include <iostream>
#include <string>
#include "../include/calc.h"

using namespace std;

int main(int argc, char *argv[]){
    string i = argv[1];
    if(i=="add"){
        cout<<add()<<endl;
        return 0;
    }
    else if(i=="subtract"){
        cout<<subtract()<<endl;
        return 0;
    }
    else if(i=="volume"){
        cout<<volume()<<endl;
        return 0;
    }
    else if(i=="help"){
        help();
        return 0;
    }
    help();
    return 0;
}