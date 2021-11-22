#ifndef UNTITLED1_FIGURA_H
#define UNTITLED1_FIGURA_H

#include <iostream>
#include "math.h"
using namespace std;

class Figura {
protected:
    string name;
    string color;

public:
    Figura();
};

class Rectangle : public Figura
{
public:
    int a, b;
    Rectangle();
    double perimeter( int a, int b );
    double area( int a, int b);
    void setA(int a);
    void setB(int b);
};

class Circle : public Figura
{
public:
    int r;
    Circle();
    double perimeter(int r);
    double area(int r);
    void setR(int r);

};

#endif //UNTITLED1_FIGURA_H
