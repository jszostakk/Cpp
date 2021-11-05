#include "Destruktor.h"
#include <iostream>

using namespace std;

Destruktor::Destruktor()
{
    t = new int [1024];
    cout << "Constructor initiated" << endl;
}

void Destruktor::pause()
{
    system("PAUSE");
}

Destruktor::~Destruktor()
{
    cout << "Destructor initiated" << endl;
    delete t;
}