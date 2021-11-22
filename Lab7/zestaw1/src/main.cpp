#include <iostream>
#include "../include/Figura.h"

using namespace std;

int main()
{
    Rectangle x;
    cout << x.area(x.a, x.b) << endl;

    Circle y;
    cout << y.area(y.r) << endl;

    return 0;
}

