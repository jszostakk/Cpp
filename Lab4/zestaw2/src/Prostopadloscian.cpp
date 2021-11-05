#include "../include/Prostopadloscian.h"

    int Prostopadloscian::pole ( int a, int b, int h )
    {
        return (2 * (a * b + a * h + b * h));
    }

    void Prostopadloscian::setA ( int a )
    {
        this->a = a;
    }

    int Prostopadloscian::getA()
    {
        return a;
    }

    void Prostopadloscian::setB ( int b )
    {
        this->b = b;
    }

    int Prostopadloscian::getB()
    {
        return b;
    }

    void Prostopadloscian::setH ( int h )
    {
        this->h = h;
    }

    int Prostopadloscian::getH()
    {
        return h;
    }