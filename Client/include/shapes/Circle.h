//
// Created by Nathan David on 01/12/2021.
//

#pragma once

#include "shapes/Shape.h"
#include "Point2D.h"
#include <cmath>
#include <utility>

class Circle : public Shape {

    Point2D position;
    double diameter;

public:

    Circle(Point2D position, double diameter) :
            position(std::move(position)),
            diameter(diameter),
            Shape() {
        if (diameter < 0) {
            throw std::invalid_argument("Invalid diameter, negative value received.");
        }
    }

    Circle *clone() const override {
        return new Circle(*this);
    }

    DataElement *toDataElement0(bool ignoreGroup) const override;

    string toString() const override {
        return "Circle[position=" + position.toString() +
               ",diameter=" + to_string(diameter)
               + "," + Shape::getMetaString() +
               +"]";
    }

    Point2D *getCenter() const override {
        return position.clone();
    }

    double getArea() const override {
        // πr²
        double radius = diameter / 2;
        return M_PI * (radius * radius);
    }

    void zoom(const Point2D &center, double factor) override {
        position.homothetie(factor, center);
        scale(factor);
    }

    void scale(double scale) override {
        diameter *= abs(scale);
    }

    void translate(double x, double y) override {
        position.setX(position.getX() + x);
        position.setY(position.getY() + y);
    }

    void rotate(const Point2D &center, double radians) override {
        position.rotate(center, radians);
    }

};



