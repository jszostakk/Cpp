
#include "../include/Vector.h"

using namespace std;

Vector::Vector()
{
    x = 0;
    y = 0;
};

double Vector::length()
{
    return sqrt(x * x + y * y);
}

void Vector::print()
{
    cout << "x = " << x << "\ny = " << y << endl;
};
