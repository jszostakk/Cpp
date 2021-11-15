#include <iostream>
#include "../include/Node.h"

using namespace std;

int main()
{
    Node a(1,1), b(2,2);
    cout << pointsDistance(a,b);
}