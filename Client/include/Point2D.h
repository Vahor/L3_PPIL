//
// Created by Nathan David on 13/12/2021.
//
#pragma once

#include <cmath>
#include <ostream>
#include "data/DataObject.h"
#include "data/DataPrimitive.h"

class Point2D {

    double x;
    double y;

public:

    Point2D(double x, double y) : x(x), y(y) {}

    DataElement *serialize() const {
        auto *object = new DataObject();
        object->put("x", DataPrimitive(x));
        object->put("y", DataPrimitive(y));
        return object;
    }

    Point2D *clone() const {
        return new Point2D(*this);
    }

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double d) { this->x = d; }
    void setY(double d) { this->y = d; }

    void rotate(const Point2D &center, double radians) {
        double xShifted = x - center.x;
        double yShifted = y - center.y;

        x = center.x + (cos(radians) * xShifted - sin(radians) * yShifted);
        y = center.y + (sin(radians) * xShifted + cos(radians) * yShifted);
    }

    static Point2D center(const Point2D &p1, const Point2D &p2) {
        return {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
    }

    virtual string toString() const {
        return "(" + to_string(x) + "," + to_string(y) + ")";
    }

    explicit operator string() const { return toString(); }

    inline bool operator==(const Point2D &other) const {
        return x == other.x && y == other.y;
    }
    inline bool operator!=(const Point2D &other) const {
        return !(*this == other);
    }

    friend ostream &operator<<(ostream &os, const Point2D &d) {
        os << d.toString();
        return os;
    }

    inline Point2D operator-(const Point2D &u) const {
        return {x - u.x, y - u.y};
    };

};


