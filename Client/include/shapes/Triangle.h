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
             Point2D *c) : points{a, b, c} {}

    DataElement *serialize0(bool ignoreGroup) const override {
        auto *object = new DataObject();

        auto *data = new DataObject();
        auto *pointsArray = new DataArray();

        for (Point2D *point: points) {
            pointsArray->add(point->serialize());
        }

        data->put("points", pointsArray);
        object->put("POLYGON", data);

        return object;
    }

    string toString() const override {
        string res = "Triangle[";
        for (auto *point: points) {
            res += point->toString();
            res += ","; // On garde la dernière "," pour le Shape::_toString()
        }

        res += Shape::_toString();
        res += "]";
        return res;
    }

    Triangle *clone() const override {
        return new Triangle(*this);
    }

    Point2D *getCenter() const override {
//        double sumX = 0;
//        double sumY = 0;
//        auto size = (double) points.size();
//        for (Point2D *point: points) {
//            sumX += point->getX();
//            sumY += point->getY();
//        }
//        return new Point2D(sumX / size, sumY / size);
        return nullptr;
        // todo center triangles
    }

    double getArea() const override {
        // Aire (triangle ABC) = 0.5 * det(AB,AC).

        // AB = B - A
        Point2D AB = *points[1] - *points[0];
        Point2D BC = *points[2] - *points[1];

        double det = abs(AB.getX() * BC.getY() - AB.getY() * BC.getX());

        return 0.5 * (det);
    }

    void scale(int scale) override {
        // todo
    }

    void translate(double x, double y) override {
        for (Point2D *point: points) {
            point->setX(point->getX() + x);
            point->setY(point->getY() + y);
        }
    }

    void rotate(const Point2D &center, double deg) override {
        for (Point2D *point: points) {
            point->rotate(center, deg);
        }
    }
};


