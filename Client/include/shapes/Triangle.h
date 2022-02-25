//
// Created by Nathan David on 13/12/2021.
//

#pragma once


#include "shapes/Polygon.h"

class Triangle : public Polygon {

public:

    Triangle(Point2D *a,
             Point2D *b,
             Point2D *c) : Polygon() {
        if (a == nullptr || b == nullptr || c == nullptr) {
            throw std::invalid_argument("All points must be non-null.");
        }
        Polygon::addPoint(*a);
        Polygon::addPoint(*b);
        Polygon::addPoint(*c);
    }

    Triangle *clone() const override {
        return new Triangle(*this);
    }

    DataElement *toDataElement0(bool ignoreGroup) const override;
    string toString() const override;
    Point2D *getCenter() const override;

    void addPoint(const Point2D &point) override {
        if (size() == 3) {
            throw std::invalid_argument("All points must be non-null.");
        }
    }

    double getArea() const override {
        // Aire (triangle ABC) = 0.5 * det(AB,AC).

        // AB = B - A
        Point2D AB = *getPointAt(1) - *getPointAt(0);
        Point2D BC = *getPointAt(2) - *getPointAt(1);

        double det = abs(AB.getX() * BC.getY() - AB.getY() * BC.getX());

        return 0.5 * (det);
    }
};


