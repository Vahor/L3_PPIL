//
// Created by Nathan David on 01/12/2021.
//

#pragma once

#include "shapes/Shape.h"
#include "Point2D.h"
#include "data/DataImpl.h"
#include <cmath>

class Circle : public Shape {

    Point2D position;
    double diameter;

public:

    Circle(Point2D position, double diameter) :
            position(position),
            diameter(diameter),
            Shape() {}

    DataElement *serialize() const override {
        auto *object = new DataObjectImpl();

        auto *data = new DataObjectImpl();
        data->put("position", position.serialize());
        data->put("diameter", new DataPrimitiveImpl(diameter));

        object->put("CIRCLE", data);

        Shape::addMetaData(object);

        return object;
    }

    Circle *clone() const override {
        return new Circle(*this);
    }

    Point2D *getCenter() const override {
        return position.clone();
    }

    double getArea() const override {
        // πr²
        double radius = diameter / 2;
        return M_PI * (radius * radius);
    }

    void scale(int scale) override {
        diameter *= scale;
    }

    void translate(double x, double y) override {
        position.setX(position.getX() + x);
        position.setY(position.getY() + y);
    }

    void rotate(const Point2D &center, double deg) override {
        position.rotate(center, deg);
    }

};



