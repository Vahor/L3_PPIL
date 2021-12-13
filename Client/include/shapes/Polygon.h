//
// Created by Nathan David on 13/12/2021.
//

#ifndef CLIENT_POLYGON_H
#define CLIENT_POLYGON_H


#include "api/shape/AShape.h"
#include "data/DataImpl.h"
#include <cmath>

class PolyGon : public AShape {

private:

    double x;
    double y;
    double diameter;

public:

    PolyGon(double x, double y, double diameter) :
            x(x),
            y(y),
            diameter(diameter),
            AShape() {}
};

#endif //CLIENT_POLYGON_H
