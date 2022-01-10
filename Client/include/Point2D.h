//
// Created by Nathan David on 13/12/2021.
//
#pragma once


#include "data/DataImpl.h"
#include <cmath>

class Point2D {

    double x;
    double y;

public:

    static Point2D EMPTY;

    Point2D(double x, double y) : x(x), y(y) {}

    DataElement *serialize() const {
        auto *object = new DataObjectImpl();
        object->put("x", new DataPrimitiveImpl(x));
        object->put("y", new DataPrimitiveImpl(y));
        return object;
    }

    Point2D *clone() const {
        return new Point2D(*this);
    }

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    void rotate(Point2D center, double degrees) {
        x = cos(degrees) * (center.x - x) - sin(degrees) * (center.y - y);
        y = sin(degrees) * (center.x - x) + cos(degrees) * (center.y - y);
    }

    static Point2D center(Point2D p1, Point2D p2) {
        return {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
    }

    inline bool operator==(const Point2D &other) const {
        return x == other.x && y == other.y;
    }
    inline bool operator!=(const Point2D &other) const {
        return !(*this == other);
    }
};


