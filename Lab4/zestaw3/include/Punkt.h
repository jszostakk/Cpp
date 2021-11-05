
#ifndef ZESTAW2_PUNKT_H
#define ZESTAW2_PUNKT_H


struct punkt
{
    int x, y;
};

class Punkt
{
public:
    punkt a, b;
    Punkt();
    float distance();
};


#endif //ZESTAW2_PUNKT_H
