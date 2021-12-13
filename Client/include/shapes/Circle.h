//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_CIRCLE_H
#define CLIENT_CIRCLE_H

#include "api/shape/AShape.h"
#include "api/Point2D.h"
#include "data/DataImpl.h"
#include <cmath>

class Circle : public AShape {

private:

    Point2D position;
    double diameter;

public:

    Circle(Point2D position, double diameter) :
            position(position),
            diameter(diameter),
            AShape() {}

    ADataElement *serialize() const override {
        auto *object = new DataObjectImpl();

        auto *data = new DataObjectImpl();
        data->put("position", position.serialize());
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
