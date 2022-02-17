//
// Created by Nathan David on 13/12/2021.
//

#pragma once


#include "data/DataArray.h"
#include "shapes/Shape.h"
#include "Point2D.h"
#include <cmath>
#include <vector>

class Polygon : public Shape {

protected:
    std::vector<Point2D *> points;

public:

    Polygon() : Shape() {}

    ~Polygon() override {
        points.clear();
    }

    Polygon *clone() const override {
        return new Polygon(*this);
    }

    virtual void addPoint(const Point2D &point) {
        points.push_back(point.clone());
    }

    void removePoint(const Point2D *point) {
        points.erase(std::find(points.begin(), points.end(), point));
    }

    DataElement *toDataElement0(bool ignoreGroup) const override;
    string toString() const override;

    Point2D *getCenter() const override;
    virtual double getArea() const override;
    int size() const { return (int) points.size(); }
    Point2D *getPointAt(int index) const {
        return points.at(index);
    }

    void zoom(const Point2D &center, double factor) override {
        for (Point2D *point: points) {
            point->homothetie(factor, center);
        }
        scale(factor);
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


