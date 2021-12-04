//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_CIRCLE_H
#define CLIENT_CIRCLE_H

#include "api/shape/Shape.h"

class Circle : public Shape {

private:

    double x;
    double y;
    double diameter;

public:

    Circle(double x, double y, double diameter) :
            x(x),
            y(y),
            diameter(diameter) {}

    virtual ADataElement* serialize() const {
        auto* object = new JsonObject();

        object->put("type", new JsonPrimitive("CIRCLE"));

        Color color = getColor();
        auto* data = new JsonObject();
        data->put("x", new JsonPrimitive(to_string(x)));
        data->put("y", new JsonPrimitive(to_string(y)));
        data->put("diameter", new JsonPrimitive(to_string(diameter)));
        data->put("color", &color);

        object->put("CIRCLE", data);


        return object;
    }

    virtual Circle* clone() const {
        return new Circle(*this);
    }

};


#endif //CLIENT_CIRCLE_H
