#include "FunkcjaKwadratowa.h"
#include <iostream>

using namespace std;

void FunkcjaKwadratowa::equasion ( int a, int b, int c )
{
    cout << "f(x) = " << a << "x^2 + " << b << "x + " << c << endl;
}

void FunkcjaKwadratowa::setA ( int a )
{
    this->a = a;
}

int FunkcjaKwadratowa::getA ()
{
    return a;
}

void FunkcjaKwadratowa::setB ( int b )
{
    this->b = b;
}

int FunkcjaKwadratowa::getB ()
{
    return b;
}

void FunkcjaKwadratowa::setC ( int c )
{
    this->c = c;
}

int FunkcjaKwadratowa::getC ()
{
    return c;
}