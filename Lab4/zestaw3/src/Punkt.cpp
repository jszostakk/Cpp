#include "../include/Punkt.h"
#include <iostream>
#include <math.h>

using namespace std;

Punkt::Punkt()
{
    cout << "Insert values: \n x1 = ";
    cin >> a.x;
    cout << "\n y1 = ";
    cin >> a.y;

    cout << "\nInsert values: \n x2 = ";
    cin >> b.x;
    cout << "\n y2 = ";
    cin >> b.y;
}

float Punkt::distance ()
{
    return sqrt ( pow ( a.x - b.x, 2) + pow ( a.y - b.y, 2 ));
}