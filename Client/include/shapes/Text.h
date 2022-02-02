//
// Created by Nathan David on 11/12/2021.
//

#pragma once

#include <utility>

#include "shapes/Shape.h"
#include <cmath>

class Text : public Shape {

    Point2D position;
    int size;
    string value;
    double radians;

public:

    Text(const Text &copy) = default;

    Text(Point2D position, int size, string value, double radians = 0) :
            position(std::move(position)),
            size(size),
            value(std::move(value)),
            radians(radians),
            Shape() {
        if (size < 0) {
            throw std::invalid_argument("Invalid size, negative value received.");
        }
    }

    DataElement *serialize0(bool ignoreGroup) const override {
        auto *object = new DataObject();

        auto *data = new DataObject();
        data->put("position", position.serialize());
        data->put("size", DataPrimitive(size));
        data->put("value", DataPrimitive(value));
        data->put("radians", DataPrimitive(radians));

        object->put("TEXT", data);

        return object;
    }

    string toString() const override {
        return "Text[position=" + position.toString()
               + ",size=" + to_string(size) +
               +",value=" + value +
               +",radians=" + to_string(radians) +
               "," + Shape::getMetaString() +
               "]";
    }

    Text *clone() const override {
        return new Text(*this);
    }


    double getAngle() const {
        return radians;
    }

    void setAngleDeg(double v) { this->radians = v * M_PI / 180; }
    void setAngle(double v) { this->radians = v; }

    Point2D *getCenter() const override {
        return position.clone();
    }

    double getArea() const override {
        return 0;
    }

    void scale(double scale) override {
        size *= scale;
    }

    void translate(double x, double y) override {
        position.setX(position.getX() + x);
        position.setY(position.getY() + y);
    }

    void rotate(const Point2D &center, double d) override {
        this->radians -= d;
        this->radians = fmod(this->radians, 2 * M_PI);
        position.rotate(center, d);
    }

};


