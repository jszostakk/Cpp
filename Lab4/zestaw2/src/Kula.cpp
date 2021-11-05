#include "../include/Kula.h"
#include <math.h>

float Kula::volume ( int r )
{
    return M_PI*r*r;
}

void Kula::setR ( int r )
{
    this->r = r;
}

int Kula::getR ()
{
    return r;
}