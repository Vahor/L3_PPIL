//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_CIRCLE_H
#define CLIENT_CIRCLE_H

#include "shapes/Shape.h"

class Circle:public Shape{

private:

    double x;
    double y;
    double diameter;

public:

    Circle(double x, double y, double diameter):
    x(x),
    y(y),
    diameter(diameter),
    Shape("D_CIRCLE")
    {
        addChildren("x", new JsonPrimitive(to_string(x)));
        addChildren("y", new JsonPrimitive(to_string(y)));
        addChildren("diameter", new JsonPrimitive(to_string(diameter)));
    }

};


#endif //CLIENT_CIRCLE_H
