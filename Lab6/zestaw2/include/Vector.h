//
// Created by student on 15.11.21.
//

#ifndef ZESTAW1_VECTOR_H
#define ZESTAW1_VECTOR_H

#include <iostream>
#include "math.h"

using namespace std;

class Vector{
private:
    double x, y;

public:
    Vector();

    void print();

    Vector(double x, double y) : x(x), y(y) {}

    double length();

    Vector operator+(const Vector &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    Vector &operator+=(const Vector &rhs) {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        return *this;
    }

    Vector operator-(const Vector &rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    Vector &operator-=(const Vector &rhs) {
        this->x = this->x - rhs.x;
        this->y = this->y - rhs.y;
        return *this;
    }

    Vector operator*(const Vector &rhs) const {
        return {x * rhs.x, y * rhs.y};
    }

    Vector &operator*=(const Vector &rhs) {
        this->x = this->x * rhs.x;
        this->y = this->y * rhs.y;
        return *this;
    }

};


#endif //ZESTAW1_VECTOR_H
