//
// Created by Kuba on 30.10.2021.
//

#ifndef ZESTAW2_PROSTOPADLOSCIAN_H
#define ZESTAW2_PROSTOPADLOSCIAN_H


class Prostopadloscian
{
private:
    int a, b, h;

public:
    int pole ( int a, int b, int h );
    void setA ( int a );
    int getA ();
    void setB ( int b );
    int getB ();
    void setH ( int h );
    int getH ();

};


#endif //ZESTAW2_PROSTOPADLOSCIAN_H
