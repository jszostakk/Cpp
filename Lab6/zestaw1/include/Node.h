#ifndef ZESTAW1_NODE_H
#define ZESTAW1_NODE_H

using namespace std;

#include <iostream>

class Node {
private:
    double x, y;

public:
    Node();
    Node(double x, double y);

    void display();

    void updateValue(double x, double y);

    friend double pointsDistance(Node a, Node b);
};

double pointsDistance(Node a, Node b);

#endif //ZESTAW1_NODE_H