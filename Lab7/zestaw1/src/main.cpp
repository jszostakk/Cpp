#include <iostream>
#include "../include/Figura.h"

using namespace std;

int main() {
    Figura *circle = new Circle(5);
    Figura *rectangle = new Rectangle(5, 18);

    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;
}