//
// Created by Nathan David on 01/12/2021.
//

#pragma once

#include "shapes/Shape.h"
#include "Point2D.h"
#include <cmath>
#include <utility>

class Line : public Shape {

    Point2D from;
    Point2D to;

public:

    Line(Point2D from,
         Point2D to) :
            from(std::move(from)), to(std::move(to)),
            Shape() {
    }

    // todo : tester le clone, faire une ligne puis modifier le from qui a été utilisé en entrée du constructeur
    Line *clone() const override {
        return new Line(*this);
    }

    DataElement *toDataElement0(bool ignoreGroup) const override;

    string toString() const override {
        return "Line[from=" + from.toString() +
               ",to=" + to.toString()
               + "," + Shape::getMetaString() +
               +"]";
    }

    Point2D *getCenter() const override {
        return Point2D::center(from, to);
    }

    double getArea() const override {
        return 0;
    }

    void scale(double scale) override {
        from.setX(from.getX() * scale);
        from.setY(from.getY() * scale);

        to.setX(to.getX() * scale);
        to.setY(to.getY() * scale);
    }

    void translate(double x, double y) override {
        from.setX(from.getX() + x);
        from.setY(from.getY() + y);

        to.setX(to.getX() + x);
        to.setY(to.getY() + y);
    }

    void rotate(const Point2D &center, double radians) override {
        from.rotate(center, radians);
        to.rotate(center, radians);
    }

};



