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
    virtual double getArea() = 0;
};

class Rectangle : public Figura
{
public:
    int a, b;
    Rectangle(int a, int b);
    double perimeter( int a, int b );
    double getArea();
    void setA(int a);
    void setB(int b);
};

class Circle : public Figura
{
public:
    int r;
    Circle(int r);
    double perimeter(int r);
    double getArea();
    void setR(int r);

};

#endif //UNTITLED1_FIGURA_H
