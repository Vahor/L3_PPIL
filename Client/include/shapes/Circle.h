//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_CIRCLE_H
#define CLIENT_CIRCLE_H

#include "shapes/Shape.h"

class Circle : public Shape {

private:

    double x;
    double y;
    double diameter;

public:

    Circle(double x, double y, double diameter) :
            x(x),
            y(y),
            diameter(diameter),
            Shape("CIRCLE") {}

    virtual JsonElement* serialize() const {
        auto* object = new JsonObject();

        object->put("x", new JsonPrimitive(to_string(x)));
        object->put("y", new JsonPrimitive(to_string(y)));
        object->put("diameter", new JsonPrimitive(to_string(diameter)));

        return object;
    }

    virtual Circle* clone() const {
        return new Circle(*this);
    }

};


#endif //CLIENT_CIRCLE_H
