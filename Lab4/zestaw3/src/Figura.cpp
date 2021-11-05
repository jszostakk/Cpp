#include "../include/Figura.h"
#include <iostream>

using namespace std;

Figura::Figura(int amount)
{
    cusps = new punkt [amount];

    for (int i = 0; i < amount; i++)
    {
        cout << "Insert x coordinate for cusp nr: " << i+1 << endl;
        cin >> cusps[i].x;
        cout << "Insert y coordinate for cusp nr: " << i+1 << endl;
        cin >> cusps[i].y;
    }
}