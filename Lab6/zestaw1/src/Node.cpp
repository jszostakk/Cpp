#include "../include/Node.h"
#include <math.h>


Node::Node() {
    x = 0;
    y = 0;
}

Node::Node(double x, double y): x(x), y(y) {}

void Node::display() {
    cout << "x: " << x << "\ty: " << y << endl;
}

void Node::updateValue(double x, double y) {
    this->x = x;
    this->y = y;
}

double pointsDistance(Node a, Node b)
{
    return sqrt( pow (a.x - b.x, 2 ) + pow ( a.y - b.y, 2 ));
}