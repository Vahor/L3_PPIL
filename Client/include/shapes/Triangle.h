//
// Created by Nathan David on 13/12/2021.
//

#pragma once


#include "data/DataArray.h"
#include "shapes/Shape.h"
#include "Point2D.h"
#include <cmath>
#include <vector>

class Triangle : public Shape {

    Point2D *points[3];

public:

    Triangle(Point2D *a,
             Point2D *b,
             Point2D *c) : points{a, b, c} {
        if (a == nullptr || b == nullptr || c == nullptr) {
            throw std::invalid_argument("All points must be non-null.");
        }
    }

    Triangle *clone() const override {
        return new Triangle(*this);
    }

    DataElement *toDataElement0(bool ignoreGroup) const override;
    string toString() const override;
    Point2D *getCenter() const override;

    double getArea() const override {
        // Aire (triangle ABC) = 0.5 * det(AB,AC).

        // AB = B - A
        Point2D AB = *points[1] - *points[0];
        Point2D BC = *points[2] - *points[1];

        double det = abs(AB.getX() * BC.getY() - AB.getY() * BC.getX());

        return 0.5 * (det);
    }

    void scale(double scale) override {
        for (Point2D *point: points) {
            point->setY(point->getY() * scale);
            point->setX(point->getX() * scale);
        }
    }

    void translate(double x, double y) override {
        for (Point2D *point: points) {
            point->setX(point->getX() + x);
            point->setY(point->getY() + y);
        }
    }

    void rotate(const Point2D &center, double radians) override {
        for (Point2D *point: points) {
            point->rotate(center, radians);
        }
    }
};


