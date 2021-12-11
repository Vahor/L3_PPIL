//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_CIRCLE_H
#define CLIENT_CIRCLE_H

#include "api/shape/AShape.h"
#include "data/DataImpl.h"
#include <cmath>

class Circle : public AShape {

private:

    double x;
    double y;
    double diameter;

public:

    Circle(double x, double y, double diameter) :
            x(x),
            y(y),
            diameter(diameter),
            AShape() {}

    ADataElement *serialize() const override {
        auto *object = new DataObjectImpl();

        auto *data = new DataObjectImpl();
        data->put("x", new DataPrimitiveImpl(x));
        data->put("y", new DataPrimitiveImpl(y));
        data->put("diameter", new DataPrimitiveImpl(diameter));

        object->put("CIRCLE", data);

        AShape::addMetaData(object);

        return object;
    }

    Circle *clone() const override {
        return new Circle(*this);
    }

    double getArea() const override {
        // πr²
        double radius = diameter / 2;
        return M_PI * (radius * radius);
    }

};


#endif //CLIENT_CIRCLE_H
