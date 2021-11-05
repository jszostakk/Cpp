#include <iostream>
#include "../include/Punkt.h"
#include "../include/Figura.h"

using namespace std;

void zad1()
{
    Punkt x;

    cout << x.distance() << endl;
}

void zad2()
{
    int n;
    cout << "Insert number of cusps :" << endl;
    cin >> n;
    Figura x(n);
}

int main()
{
    //zad1();
    zad2();
}
