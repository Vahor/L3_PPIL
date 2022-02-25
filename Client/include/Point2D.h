//
// Created by Nathan David on 13/12/2021.
//
#pragma once

#include <cmath>
#include <ostream>
#include "data/DataObject.h"
#include "data/DataPrimitive.h"

class Point2D : public Serializable {

    double x;
    double y;

public:

    Point2D(double x, double y) : x(x), y(y) {}

    DataElement *toDataElement0(bool _) const override {
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
        double s = sin(radians);
        double c = cos(radians);

        x -= center.x;
        y -= center.y;

        double xnew = x * c - y * s;
        double ynew = x * s + y * c;

        x = xnew + center.x;
        y = ynew + center.y;
    }

    static Point2D *center(const Point2D &p1, const Point2D &p2) {
        return new Point2D{(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
    }

    void homothetie(const double k, const Point2D &point) {
        if (k == 1) return; // Si k == 1, il n'y a aucun agrandissement.

        const Point2D diff = *this - point;

        x = k * diff.x;
        y = k * diff.y;
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

    inline Point2D operator+(const Point2D &u) const {
        return {x + u.x, y + u.y};
    };

    inline Point2D operator-(const Point2D &u) const {
        return {x - u.x, y - u.y};
    };

    inline Point2D operator*(const Point2D &u) const {
        return {x * u.x, y * u.y};
    };

    inline Point2D operator*(const double u) const {
        return {x * u, y * u};
    };

    inline Point2D operator-() const {
        return {-x, -y};
    };

};


