//
// Created by Nathan David on 11/12/2021.
//

#pragma once

#include <utility>

#include "shapes/Shape.h"
#include "data/DataImpl.h"
#include <cmath>

class Text : public Shape {

    Point2D position;
    int size;
    string value;
    double angle;

public:


    Text(Point2D position, int size, string value, double angle = 0) :
            position(std::move(position)),
            size(size),
            value(std::move(value)),
            angle(angle),
            Shape() {}

    DataElement *serialize0(bool ignoreGroup) const override {
        auto *object = new DataObjectImpl();

        auto *data = new DataObjectImpl();
        data->put("position", position.serialize());
        data->put("size", new DataPrimitiveImpl(size));
        data->put("value", new DataPrimitiveImpl(value));
        data->put("angle", new DataPrimitiveImpl(angle));

        object->put("TEXT", data);

        return object;
    }

    string toString() const override {
        return "Text[position=" + position.toString()
               + ",size=" + to_string(size) +
               +",value=" + value +
               +",angle=" + to_string(angle) +
               Shape::_toString() +
               "]";
    }

    Text *clone() const override {
        return new Text(*this);
    }


    double getAngle() const {
        return angle;
    }

    void setAngle(double v) { this->angle = v; }

    Point2D *getCenter() const override {
        return position.clone();
    }

    double getArea() const override {
        return 0;
    }

    void scale(int scale) override {
        size *= scale;
    }

    void translate(double x, double y) override {
        position.setX(position.getX() + x);
        position.setY(position.getY() + y);
    }

    void rotate(const Point2D &center, double deg) override {
        this->angle = deg;
        //position.rotate(center, deg);
    }

};


