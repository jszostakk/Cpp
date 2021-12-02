
#include "../include/Figura.h"

Figura::Figura()
{
    cout << "Insert values: \n name = ";
    cin >> name;
    cout << "\n color = ";
    cin >> color;
}

Rectangle::Rectangle(int a, int b)
{/*
    cout << "Insert values: \n a = ";
    cin >> a;
    cout << "\n b = ";
    cin >> b;*/
}

void Rectangle::setA ( int a )
{
    this->a = a;
}

void Rectangle::setB ( int b )
{
    this->b = b;
}

double Rectangle::perimeter ( int a, int b )
{
    return 2*(a + b);
}

double Rectangle::getArea ()
{
    return a*b;
}

Circle::Circle(int r)
{
  /*  cout << "Insert value: \n r = ";
    cin >> r;*/
}

void Circle::setR( int r)
{
    this->r = r;
}

double Circle::perimeter(int r)
{
    return M_PI*2*r;
}

double Circle::getArea()
{
    return M_PI*r*r;
}