//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_CIRCLE_H
#define CLIENT_CIRCLE_H

#include "api/shape/Shape.h"
#include <cmath>

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

    ADataElement* serialize() const override {
        auto* object = new JsonObject();

        Color color = getColor();
        auto* data = new JsonObject();
        data->put("x", new JsonPrimitive(x));
        data->put("y", new JsonPrimitive(y));
        data->put("diameter", new JsonPrimitive(diameter));

        object->put("CIRCLE", data);

        Shape::addMetaData(object);

        return object;
    }

    Circle* clone() const override {
        return new Circle(*this);
    }

    double getArea() const override {
        // πr²
        double radius = diameter / 2;
        return M_PI * (radius * radius);
    }

};


#endif //CLIENT_CIRCLE_H
